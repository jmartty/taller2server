#pragma once
#include <cereal/types/string.hpp>
#include <cereal/archives/binary.hpp>
#include <string>
#include <ctime>

// POD con serializacion
struct Usuario {

	// Constructor default
	Usuario() : conectado(false) { }
	// Constructor from serialized string
	Usuario(const std::string& str);

	// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(id, nombre, foto, ubicacion, token, last_login);
	}
	// Actual serial
	std::string serialStr() const;
	// Unserial from str
	void unserialStr(const std::string& str);

	// Attribs
	std::string id;
	std::string nombre;
	std::string foto;
	std::string ubicacion;
	std::string token;
	std::time_t last_login;
	bool conectado;

};
