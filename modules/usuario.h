#pragma once
#include <cereal/types/string.hpp>
#include <cereal/archives/binary.hpp>
#include <string>
#include <ctime>
#include <json/json.h>

// POD con serializacion
/// Clase para el manejo de usuarios
struct Usuario {

	/// Constructor default inicializa todo en 0/apagado/nunca/falso
	Usuario() : estado("desconectado"), last_action(0), broadcast_unread(false), appear_offline(false) { }
	/// Constructor from serialized string
	Usuario(const std::string& str);
	/// Cargar desde un Json::value
	void load(const Json::Value& js);
	/// Retornar el usuario como Json
	std::string asJson() const;

	/// Serializacion
	// Cereal method
	template<class Archive>
	void serialize(Archive& ar) {
		ar(id, password, nombre, foto, fotochica, ubicacion, estado, token, last_action, email, telefono, broadcast_unread, appear_offline);
	}
	/// Actual serial
	std::string serialStr() const;
	/// Deserial from str
	void deserialStr(const std::string& str);

	// Attribs
	/// Id del usuario (unico)
	std::string id;
	/// Password de usuario
	std::string password;
	/// Nombre de usuario
	std::string nombre;
	/// Foto del usuario (Base64)
	std::string foto;
	/// Thumbnail de foto (Base64)
	std::string fotochica;
	/// String con ubicacion textual
	std::string ubicacion;
	/// Email del usuario
	std::string email;
	/// Telefono del usuario
	std::string telefono;
	/// Hash de session de usuario
	std::string token;
	/// Estado del usuario. Valores posibles: "conectado", "desconectado"
	std::string estado;
	/// Timestamp de ultimo request
	std::time_t last_action;
	/// True si tiene mensajes sin leer en el broadcast
	bool broadcast_unread;
	/// Aparecer como offline
	bool appear_offline;
};
