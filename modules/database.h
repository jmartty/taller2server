#pragma once
#include <iostream>
#include <string>
#include <rocksdb/db.h>
#include <set>
#include <cereal/types/set.hpp>
#include "usuario.h"

typedef std::set<std::string> ListaUsuarios;

class Database {

	public:

	// Operaciones sobre usuarios
	bool usuarioExists(const std::string& id);
	bool loadUsuario(const std::string& id, Usuario& usr);
	bool saveUsuario(const Usuario& usr);
	ListaUsuarios getListaUsuarios();
	std::string getListaUsuariosJson();
	bool createUsuario(const Usuario& usr);
	static bool validateUser(const Usuario& usr);
	static bool validateUserId(const std::string& id);
	static bool validateUserName(const std::string& name);
	static bool validateUserPwd(const std::string& pwd);

	// Operacion sobre conversaciones


	// Devuelve true si la sesion es valida y actualiza el last_action al time() actual
	bool validateSession(const std::string& user_id, const std::string& token);

	// Operaciones basicas de bajo nivel
	// No deberian ser llamadas en general

	// Debe crear si no existe
	// Si existe, abrir
	bool open(const std::string& file);
	bool put(const std::string& key, const std::string& value);
	bool exists(const std::string& key);
	bool del(const std::string& key);
	std::string get(const std::string& key);
	void close();

	private:
	// Link a la DB
	rocksdb::DB* db;
	void listaUsuariosAdd(const std::string& id);
	// Permite acceso a la clase de serializacion
	friend class cereal::access;

};
