#include <cassert>
#include <iostream>
#include <rocksdb/db.h>
#include "database.h"
#include "config.h"
#include "aux_func.h"
#include "logger.h"
#include <iostream>

static Logger& log = Logger::get();

bool Database::open(const std::string& file){

	// Crea la base de datos si no existe
	rocksdb::Options options;
	options.create_if_missing = true;
	rocksdb::Status status = rocksdb::DB::Open(options, file, &db);
	return status.ok();

}


bool Database::put(const std::string& key, const std::string& value){
	rocksdb::Status status = db->Put(rocksdb::WriteOptions(), key, value);
	return status.ok();
}


bool Database::exists(const std::string& key){
	std::string value;
	rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key, &value);
	return s.ok() && !s.IsNotFound();
}

bool Database::del(const std::string& key){
	rocksdb::Status s = db->Delete(rocksdb::WriteOptions(), key);
	return s.ok();
}

std::string Database::get(const std::string& key){
	std::string value;
	rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key, &value);
	assert(s.ok());
	return value;
}

void Database::close(){
	delete db;
}

bool Database::usuarioExists(const std::string& id) {

	return exists(std::string("Usuario.") + id);

}

bool Database::loadUsuario(const std::string& id, Usuario& usr) {

	if(!usuarioExists(id)) return false;
	Usuario loaded_usr(get(std::string("Usuario.") + id));
	if(loaded_usr.id == id) {
		usr = loaded_usr;
		return true;
	}else{
		return false;
	}

}

bool Database::saveUsuario(const Usuario& usr) {

	if(!validateUser(usr) || !usuarioExists(usr.id))
		return false;
	return this->put(std::string("Usuario.") + usr.id, usr.serialStr());

}

bool Database::createUsuario(const Usuario& usr, std::string& err_str) {

	// Validamos la info y nos fijamos que no exista
	if(!validateUser(usr)) {
		log.msg(LOG_TYPE::DEBUG, "Usuario no valido");
		err_str = "Los campos deben tener entre 4 y 16 caracteres";
		return false;
	}
	if(usuarioExists(usr.id)) {
		log.msg(LOG_TYPE::DEBUG, "Usuario ya existente");
		err_str = "Usuario ya existente";
		return false;
	}
	// Agregamos
	listaUsuariosAdd(usr.id);
	return this->put(std::string("Usuario.") + usr.id, usr.serialStr());

}

void Database::listaUsuariosAdd(const std::string& id) {

	// Leemos la lista actual
	ListaUsuarios lu = getListaUsuarios();
	// Agregamos al usuario
	lu.insert(id);
	// Guardamos
	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
        {
                cereal::BinaryOutputArchive oarch(ss);
                oarch(lu);
        }
	put("Usuarios", ss.str());

}

ListaUsuarios Database::getListaUsuarios() {

	// Creamos si no existe
	if(!exists("Usuarios")) {
		ListaUsuarios lu;
		// Guardamos
		std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
		{
                	cereal::BinaryOutputArchive oarch(ss);
	                oarch(lu);
        	}
		put("Usuarios", ss.str());
		return lu;
	}else{
		// Leemos la lista
		ListaUsuarios lu;
		std::string str = this->get("Usuarios");
		std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
		ss.write(str.data(), str.size());
		{
			cereal::BinaryInputArchive iarch(ss);
			iarch(lu);
		}
		return lu;
	}

}

bool Database::validateUserId(const std::string& id) {
	// Debe tener mas de 0 caraceteres y menos de 8
	// TODO: alphanum
	return id.size() >= 4 && id.size() <= 8;
}

bool Database::validateUserName(const std::string& name) {
	// Debe tener mas de 0 caraceteres y menos de 24
	// TODO: alphanum
	return name.size() >= 4 && name.size() <= 16;
}

bool Database::validateUserPwd(const std::string& pwd) {
	// Debe tener mas de 0 caraceteres y menos de 24
	// TODO: alphanum
	return pwd.size() >= 4 && pwd.size() <= 16;
}

bool Database::validateUser(const Usuario& usr) {
	if(!validateUserId(usr.id)) log.msg(LOG_TYPE::DEBUG, std::string("usr.id invalido `") + usr.id + "`");
	if(!validateUserPwd(usr.password)) log.msg(LOG_TYPE::DEBUG, std::string("usr.password invalido `") + usr.password + "`");
	if(!validateUserName(usr.nombre)) log.msg(LOG_TYPE::DEBUG, std::string("usr.nombre invalido `") + usr.nombre + "`");
	return validateUserId(usr.id) && validateUserPwd(usr.password) && validateUserName(usr.nombre);
}

std::string Database::getListaUsuariosJson(const std::string& r_user) {

	// Pasa la lista de usuarios a JSON y ademas
	assert(this->heartbeatUsuario(r_user));
	auto lu = getListaUsuarios();
	auto c = lu.size()-1; // Resto 1 por self
	// Build JSON reply
	std::string ret("{ \"nuevobroadcast\": ");
	ret += (hasBroadcastUnread(r_user) ? "true" : "false");
	ret += ", \"usuarios\": [ ";
	size_t i = 0;
	for(const auto& id : lu) {
		// Skip self
		if(id == r_user) {
			continue;
		}

		Usuario usr;
		assert(this->loadUsuario(id, usr));
		assert(this->heartbeatUsuario(id));
		ret += "{\"id\": \"";
		ret += usr.id;
		ret += "\", \"nombre\": \"";
		ret += usr.nombre;
		ret += "\", \"fotochica\": \"";
		ret += usr.fotochica;
		// Se muestra online solo si esta online y no tiene appear_offline enabled
		ret += "\", \"estado\": \"";
		ret += (usr.appear_offline ? "desconectado" : usr.estado);
		// Nos fijamos si tiene mensajes nuevos con ese usuario
		Conversacion conv;
		loadConversacion(r_user, id, conv);
		if(conv.hasUnread(r_user)) {
			ret += "\", \"nuevomsg\": true";
		}else{
			ret += "\", \"nuevomsg\": false";
		}
		ret += "}";
		// Separador
		if(i+1 < c) {
			ret += ", ";
			i++;
		}
	}
	ret += " ] }";
	return ret;

}

bool Database::validateSession(const std::string& id, const std::string& token) {

	// Validamos la sesion
	Usuario usr;
	bool res = loadUsuario(id, usr) &&
		usr.token == token &&
		secondsFrom(usr.last_action) < SESSION_EXPIRE_SECONDS;

	if(res) {
		// Si es valida, actualizamos el last_action
		usr.last_action = std::time(nullptr);
		saveUsuario(usr);
		return true;
	}else{
		// Si no es valida, debe loggearse nuevamente
		return false;
	}

}

bool Database::heartbeatUsuario(const std::string& id) {

	// Actualizamos el estado basado en el tiempo desde la ultima query
	Usuario usr;
	if(!loadUsuario(id, usr)) return false;
	//std::stringstream ss;
	//ss << "Usuario `" << usr.id << "`.seconds from last action: " << secondsFrom(usr.last_action);
	//log.msg(LOG_TYPE::DEBUG, ss.str());
	if(secondsFrom(usr.last_action) > SESSION_EXPIRE_SECONDS) {
		usr.estado = "desconectado";
	}else{
		usr.estado = "conectado";
	}
	return saveUsuario(usr);

}

bool Database::loadConversacion(const std::string& user1, const std::string& user2, Conversacion& conv) {
	if(!usuarioExists(user1) || !usuarioExists(user2)) return false;
	// Buscamos la key en la DB
	const auto key = Conversacion::keyGen(user1, user2);
	// Si no existe, creamos la conversacion desde 0
	if(!exists(key)) {
		conv = Conversacion(user1, user2);
	}else{
		// Si existe la cargamos
		conv.deserialStr(this->get(key));
	}
	// Falta chequeo de errores
	return true;
}

bool Database::postearMensaje(const std::string& source_user, const std::string& target_user, const std::string& mensaje) {

	conv_mutex.lock();
	Conversacion conv;
	if(!loadConversacion(source_user, target_user, conv)) {
		conv_mutex.unlock();
		return false;
	}else{
		conv.postear(source_user, mensaje);
		bool val = this->put(Conversacion::keyGen(source_user, target_user), conv.serialStr());
		conv_mutex.unlock();
		return val;
	}

}

bool Database::markRead(const std::string& source_user, const std::string& target_user) {

        conv_mutex.lock();
        Conversacion conv;
        if(!loadConversacion(source_user, target_user, conv)) {
                conv_mutex.unlock();
                return false;
        }else{
		conv.markRead(source_user);
                bool val = this->put(Conversacion::keyGen(source_user, target_user), conv.serialStr());
                conv_mutex.unlock();
                return val;
        }


}

bool Database::postearMensajeBroadcast(const std::string& source_user, const std::string& mensaje) {

	// Agrego el mensaje a la conversacion de broadcast
        conv_mutex.lock();
        Broadcast bcast;
        if(!loadBroadcast(bcast)) {
                conv_mutex.unlock();
                return false;
        }else{
                bcast.postear(source_user, mensaje);
                bool val = this->put("Broadcast", bcast.serialStr());
                conv_mutex.unlock();
		if(!val) return false;
        }
	// Marco como no leido para todos los usuarios menos el que lo envia
	const auto& lu = getListaUsuarios();
	for(auto& u : lu) {
		if(u != source_user) markBroadcastUnread(u, true);
	}
	return true;

}

bool Database::markBroadcastUnread(const std::string& id, bool val) {
	// Marca el broadcast como no leido
        Usuario usr;
        bool res = loadUsuario(id, usr);
        if(res) {
                usr.broadcast_unread = val;
                saveUsuario(usr);
                return true;
        }else{
                // Si no es valida, debe loggearse nuevamente
                return false;
        }

}

bool Database::loadBroadcast(Broadcast& bcast) {

        const auto key = "Broadcast";
        // Si no existe, creamos la conversacion desde 0
        if(!exists(key)) {
                bcast = Broadcast();
        }else{
                // Si existe la cargamos
                bcast.deserialStr(this->get(key));
        }
        // Falta chequeo de errores
        return true;

}


bool Database::hasBroadcastUnread(const std::string& id) {

        Usuario usr;
        bool res = loadUsuario(id, usr);
        if(res) {
                return usr.broadcast_unread;
        }else{
                return false;
        }

}

