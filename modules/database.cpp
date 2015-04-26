#include <cassert>
#include <iostream>
#include <rocksdb/db.h>
#include "database.h"

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

	if(!usuarioExists(usr.id)) return false;
	return this->put(std::string("Usuario.") + usr.id, usr.serialStr());

}

bool Database::createUsuario(const Usuario& usr) {

	if(!validateUserId(usr.id) || usuarioExists(usr.id)) return false;
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
	return id.size() > 0 && id.size() <= 8;
}
