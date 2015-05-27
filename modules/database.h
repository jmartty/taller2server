#pragma once
#include <iostream>
#include <string>
#include <rocksdb/db.h>
#include <set>
#include <mutex>
#include <cereal/types/set.hpp>
#include "usuario.h"
#include "conversacion.h"

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
	bool heartbeatUsuario(const std::string& id);
	static bool validateUser(const Usuario& usr);
	static bool validateUserId(const std::string& id);
	static bool validateUserName(const std::string& name);
	static bool validateUserPwd(const std::string& pwd);

	// Operacion sobre conversaciones
	bool loadConversacion(const std::string& user1, const std::string& user2, Conversacion& conv);
	bool postearMensaje(const std::string& source_user, const std::string& target_user, const std::string& msg);
	bool postearMensajeTodos(const std::string& source_user, const std::string& msg);

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
	// Para exclusion mutua durante operacion de escritura y lectura de mas de un key
	// En el caso de conversaciones hay read seguido de write (append a conversacion)
	// De esta manera se evita perder mensajes en el caso que dos usuarios hagan append en paralelo
	// I.e.: read1->write1, read2->write2 podria resultar en read1->read2->write1->write2
	// En ese caso write2 sobreescribe lo que escribio write1
	std::mutex conv_mutex;
};
