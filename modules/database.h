#pragma once
#include <iostream>
#include <string>
#include <rocksdb/db.h>
#include <set>
#include <mutex>
#include <cereal/types/set.hpp>
#include "usuario.h"
#include "conversacion.h"
#include "broadcast.h"

/// Tipo lista de usuarios
typedef std::set<std::string> ListaUsuarios;

/// Clase para manejar persistencia del sistema
class Database {

	public:

	// Operaciones sobre usuarios
	/// Usuario existe?
	/// @return false en caso de error
	bool usuarioExists(const std::string& id);
	/// Cargar usuario dado el id
	/// @param usr usuario donde se carga la informacion
	/// @return false en caso de error
	bool loadUsuario(const std::string& id, Usuario& usr);
	/// Guardar usuario
	/// @return false en caso de error
	bool saveUsuario(const Usuario& usr);
	/// Get de lista de usuarios
	ListaUsuarios getListaUsuarios();
	/// Get de lista de usuarios en JSON
	/// @param r_user usuario que solicita el request
	std::string getListaUsuariosJson(const std::string& r_user);
	/// Crear usuario nuevo
	/// @param err_str en caso de error se llena el string con el mensaje
	/// @return false en caso de error
	bool createUsuario(const Usuario& usr, std::string& err_str);
	/// Mantiene al usuario como conectado (ping)
	bool heartbeatUsuario(const std::string& id);
	/// Validacion completa de atributos de usuario
	static bool validateUser(const Usuario& usr);
	/// Validacion de id de usuario
	static bool validateUserId(const std::string& id);
	/// Validacion de nombre de usuario
	static bool validateUserName(const std::string& name);
	/// Validacion de clave del usuario
	static bool validateUserPwd(const std::string& pwd);

	// Operacion sobre conversaciones
	/// Carga la conversacion entre dos usuarios
	/// Crea la conversacion si no existe
	/// @param conv donde se carga la conversacion
	/// @return false en caso de error
	bool loadConversacion(const std::string& user1, const std::string& user2, Conversacion& conv);
	/// Agregar un mensaje a una conversacion entre dos usuarios
	/// @return false en caso de error
	bool postearMensaje(const std::string& source_user, const std::string& target_user, const std::string& msg);
	/// Marca la conversacion como leida (por source_user)
	/// @return false en caso de error
	bool markRead(const std::string& source_user, const std::string& target_user);
	// Operaciones de broadcast
	/// Carga el broadcast en una conversacion
	/// @return false en caso de error
	bool loadBroadcast(Broadcast& conv);
	/// Agrega un mensaje al broadcast grupal
	/// @return false en caso de error
	bool postearMensajeBroadcast(const std::string& source_user, const std::string& msg);
	/// Marcar el broadcast como leido o no leido
	/// @param val true = no leido, false = leido
	/// @return false en caso de error
	bool markBroadcastUnread(const std::string& user, bool val);
	/// Para averiguar si un usuario tiene mensajes sin leer en el broadcast
	/// @param user el usuario en cuestion
	/// @return true si tiene mensajes sin leer
	bool hasBroadcastUnread(const std::string& user);

	/// Validar la session por tiempo/token
	/// @return true si la sesion es valida y actualiza el last_action al time() actual
	bool validateSession(const std::string& user_id, const std::string& token);

	// Operaciones basicas de bajo nivel
	// No deberian ser llamadas en general

	/// Abre la base de datos
	/// @param file archivo de base de datos
	/// Debe crear si no existe. Si existe, abrir
	/// @return false en caso de error
	bool open(const std::string& file);
	/// Escribe una key/val a la base de datos abierta
	/// @return false en caso de error
	bool put(const std::string& key, const std::string& value);
	/// Existencia de una key en la DB
	/// @return true si existe, false en caso contrario
	bool exists(const std::string& key);
	/// Borra una key en la DB 
	/// @return true si existe, false en caso contrario
	bool del(const std::string& key);
	/// Escribe una key/val a la base de datos abierta
	/// @return false en caso de error
	std::string get(const std::string& key);
	/// Cierra la base de datos
	void close();

	private:
	/// Link interno a la DB
	rocksdb::DB* db;
	/// Helper para agregar un usuario a la DB
	void listaUsuariosAdd(const std::string& id);
	/// Permite acceso a la clase de serializacion
	friend class cereal::access;
	/// Para exclusion mutua durante operacion de escritura y lectura de mas de un key
	/// En el caso de conversaciones hay read seguido de write (append a conversacion)
	/// De esta manera se evita perder mensajes en el caso que dos usuarios hagan append en paralelo
	/// I.e.: read1->write1, read2->write2 podria resultar en read1->read2->write1->write2
	/// En ese caso write2 sobreescribe lo que escribio write1
	std::mutex conv_mutex;
};
