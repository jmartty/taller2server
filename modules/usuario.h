#pragma once
#include <cereal/types/string.hpp>
#include <cereal/archives/binary.hpp>
#include <string>
#include <ctime>
#include <json/json.h>

// POD con serializacion
struct Usuario {

	// Constructor default
	Usuario() : estado("desconectado") { }
	// Constructor from serialized string
	Usuario(const std::string& str);
	// Cargar desde un Json::value
	void load(const Json::Value& js);
	std::string asJson() const;

	// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(id, password, nombre, foto, ubicacion, estado, token, last_login);
	}
	// Actual serial
	std::string serialStr() const;
	// Unserial from str
	void unserialStr(const std::string& str);

	// Attribs
	std::string id;
	std::string password;
	std::string nombre;
	std::string foto;
	std::string ubicacion;
	std::string token;
	std::time_t last_login;
	// Valores posibles para conectado
	// "conectado", "desconectado"
	std::string estado;

};
