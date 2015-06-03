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
	// Retornar como Json
	std::string asJson() const;

	// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(id, password, nombre, foto, ubicacion, estado, token, last_action, email, telefono);
	}
	// Actual serial
	std::string serialStr() const;
	// Deserial from str
	void deserialStr(const std::string& str);

	// Attribs
	std::string id;
	std::string password;
	std::string nombre;
	std::string foto;
	std::string ubicacion;
	std::string email;
	std::string telefono;
	std::string token;
	std::time_t last_action;
	// Valores posibles para conectado
	// "conectado", "desconectado"
	std::string estado;

};
