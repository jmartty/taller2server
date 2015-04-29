#pragma once
#include <cereal/types/string.hpp>
#include <cereal/types/deque.hpp>
#include <cereal/types/array.hpp>
#include <cereal/archives/binary.hpp>
#include <string>
#include <ctime>
#include <json/json.h>
#include <deque>

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
	size_t autor;

};

// POD con serializacion
struct Conversacion {

	// Constructor default
	Conversacion() { }
	// Constructor para crear vacia desde 2 usuarios
	Conversacion(const std::string& user1, const std::string& user2);
	// Constructor from serialized string
	Conversacion(const std::string& str) {
		deserialStr(str);
	}
	// Retornar como Json
	std::string asJson() const;
	// Agregar mensaje
	void postear(const std::string& autor, const std::string& msg);

	// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(users, lines);
	}
	// Actual serial
	std::string serialStr() const;
	// Deserial from str
	void deserialStr(const std::string& str);

	// Attribs
	std::array<std::string, 2> users;
	std::deque<Line> lines;

	// Helper
	static std::string keyGen(const std::string& user1, const std::string& user2);
	// Convierte el user_id en indice para la conversacion
	size_t userToIndex(const std::string& id);
	// Convierte el indice en el nombre de usuario
	std::string indexToUser(size_t i);

};
