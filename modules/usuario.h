#pragma once
#include <cereal/types/string.hpp>
#include <cereal/archives/binary.hpp>
#include <string>
#include <ctime>
#include <json/json.h>

// POD con serializacion
struct Usuario {

	// Constructor default
	Usuario() : estado("desconectado"), last_action(0), broadcast_unread(false), appear_offline(false) { }
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
		ar(id, password, nombre, foto, ubicacion, estado, token, last_action, email, telefono, broadcast_unread, appear_offline);
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
	// Valores posibles para conectado
	// "conectado", "desconectado"
	std::string estado;
	// Timestamp de ultimo request
	std::time_t last_action;
	// True si tiene mensajes sin leer en el broadcast
	bool broadcast_unread;
	// Aparecer como offline
	bool appear_offline;
};
