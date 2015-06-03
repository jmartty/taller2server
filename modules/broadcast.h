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
struct BroadcastLine {

	// Serializacion
	template<class Archive>
	void serialize(Archive& ar) {
		ar(timestamp, msg, autor_id);
	}
	// Atribs
	time_t timestamp;
	std::string msg;
	std::string autor_id;

};

// POD con serializacion
struct Broadcast {

	// Constructor default
	Broadcast() { }
	// Constructor from serialized string
	Broadcast(const std::string& str) {
		deserialStr(str);
	}
	// Retornar como Json
	std::string asJson(size_t num_lines=0) const;
	// Agregar mensaje
	void postear(const std::string& autor, const std::string& msg);

	// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(lines);
	}
	// Actual serial
	std::string serialStr() const;
	// Deserial from str
	void deserialStr(const std::string& str);

	// Attribs
	// Conjunto de lineas (mensajes)
	std::deque<BroadcastLine> lines;

};
