#include <cassert>
#include <iostream>
#include <rocksdb/db.h>
#include "database.h"
#include "config.h"
#include "aux_func.h"
#include "logger.h"
#include <iostream>

//static Logger& log = Logger::get();

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

bool Database::createUsuario(const Usuario& usr) {

	// Validamos la info y nos fijamos que no exista
	if(!validateUser(usr) || usuarioExists(usr.id))
		return false;
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
	return id.size() > 0 && id.size() <= 8;
}

bool Database::validateUserName(const std::string& name) {
	// Debe tener mas de 0 caraceteres y menos de 24
	// TODO: alphanum
	return name.size() > 0 && name.size() <= 24;
}

bool Database::validateUserPwd(const std::string& pwd) {
	// Debe tener mas de 0 caraceteres y menos de 24
	// TODO: alphanum
	return pwd.size() > 0 && pwd.size() <= 24;
}

bool Database::validateUser(const Usuario& usr) {
	return validateUserId(usr.id) && validateUserPwd(usr.password) && validateUserName(usr.nombre);
}

std::string Database::getListaUsuariosJson() {

	// Pasa la lista de usuarios a JSON y ademas 
	auto lu = getListaUsuarios();
	auto c = lu.size();
	// Build JSON reply
	std::string ret("[ ");
	size_t i = 0;
	for(const auto& id : lu) {
		Usuario usr;
		assert(this->heartbeatUsuario(id));
		assert(this->loadUsuario(id, usr));
		ret += "{\"id\": \"";
		ret += usr.id;
		ret += "\", \"nombre\": \"";
		ret += usr.nombre;
		ret += "\", \"estado\": \"";
		ret += usr.estado;
		ret += "\"}";
		if(i+1 != c)
			ret += ", ";
			i++;
		}
	ret += " ]";
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
