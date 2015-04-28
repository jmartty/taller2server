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
	std::string timestamp;
	std::string msg;
	// Valores posibles: 0, 1
	// Index into Conversation.users
	size_t autor;

};

// POD con serializacion
struct Conversacion {

	// Constructor default
	Conversacion() { }
	// Constructor from serialized string
	Conversacion(const std::string& str) {
		unserialStr(str);
	}
	// Retornar como Json
	std::string asJson() const;

	// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(users, lines);
	}
	// Actual serial
	std::string serialStr() const;
	// Deserial from str
	void unserialStr(const std::string& str);

	// Attribs
	std::array<std::string, 2> users;
	std::deque<Line> lines;

	// Helper
	// Si lhs > rhs hace swap
	static void orderUsers(std::string& lhs, std::string& rhs);
	// Convierte el user_id en indice para la conversacion
	size_t userToIndex(const std::string& id);
	// Convierte el indice en el nombre de usuario
	std::string indexToUser(size_t i);

};
