#pragma once
#include <cereal/types/string.hpp>
#include <cereal/types/deque.hpp>
#include <cereal/types/array.hpp>
#include <cereal/archives/binary.hpp>
#include <string>
#include <ctime>
#include <json/json.h>
#include <deque>

/// Helper struct para conversaciones
struct BroadcastLine {

	/// Serializacion
	template<class Archive>
	void serialize(Archive& ar) {
		ar(timestamp, msg, autor_id);
	}
	/// Timestamp de mensaje
	time_t timestamp;
	/// Mensaje en si
	std::string msg;
	/// Id del autor del mensaje
	std::string autor_id;

};

/// Estructura para manejar los mensajes de broadcast
struct Broadcast {

	/// Constructor default
	Broadcast() { }
	/// Constructor from serialized string
	Broadcast(const std::string& str) {
		deserialStr(str);
	}
	/// Retornar los mensajes como JSON
	std::string asJson(size_t num_lines=0) const;
	/// Agregar mensaje al broadcast
	void postear(const std::string& autor, const std::string& msg);

	/// Serializacion. Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(lines);
	}
	/// Actual serial
	std::string serialStr() const;
	/// Deserial from str
	void deserialStr(const std::string& str);

	// Attribs
	/// Conjunto de lineas (mensajes)
	std::deque<BroadcastLine> lines;

};
