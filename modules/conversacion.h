#pragma once
#include <cereal/types/string.hpp>
#include <cereal/types/deque.hpp>
#include <cereal/types/array.hpp>
#include <cereal/archives/binary.hpp>
#include <string>
#include <ctime>
#include <json/json.h>
#include <deque>

typedef size_t UserIndex;

// Helper struct para conversaciones
struct Line {

	// Serializacion
	template<class Archive>
	void serialize(Archive& ar) {
		ar(timestamp, msg, autor);
	}
	// Atribs
	time_t timestamp;
	std::string msg;
	// Valores posibles: 0, 1
	// Index into Conversation.users
	UserIndex autor;

};

// POD con serializacion
struct Conversacion {

	// Constructor default
	Conversacion() {
		unread[0] = unread[1] = false;
	}
	// Constructor para crear vacia desde 2 usuarios
	Conversacion(const std::string& user1, const std::string& user2);
	// Constructor from serialized string
	Conversacion(const std::string& str) {
		deserialStr(str);
	}
	// Retornar como Json
	std::string asJson(int num_lines=0) const;
	// Agregar mensaje
	void postear(const std::string& autor, const std::string& msg);

	// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(users, lines, unread);
	}
	// Actual serial
	std::string serialStr() const;
	// Deserial from str
	void deserialStr(const std::string& str);

	// Attribs
	// Usuarios parte de la conversacion
	std::array<std::string, 2> users;
	// Conjunto de lineas (mensajes)
	std::deque<Line> lines;
	// Mensajes sin leer para cada usuario
	bool unread[2];
	// Marca la conversacion como leida para el usuario whoread
	void markRead(const std::string& whoread);
	// True si el usuario user tiene mensajes sin leer en la conversacion
	bool hasUnread(const std::string& user) const;

	// Helper
	static std::string keyGen(const std::string& user1, const std::string& user2);
	// Convierte el user_id en indice para la conversacion
	UserIndex userToIndex(const std::string& id) const;
	// Convierte el indice en el nombre de usuario
	std::string indexToUser(UserIndex i) const;

};
