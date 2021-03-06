#include "usuario.h"
#include <sstream>
#include <string>
#include <cstdlib>
#include <json/json.h>

// Constructor from serialized string
Usuario::Usuario(const std::string& str) {

	deserialStr(str);

}

// Serializacion
// Actual serial
std::string Usuario::serialStr() const {

	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
	{
		cereal::BinaryOutputArchive oarch(ss);
		oarch(*this);
	}
	return ss.str();

}

// Deserial from str
void Usuario::deserialStr(const std::string& str) {

	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
	ss.write(str.data(), str.size());
	{
		cereal::BinaryInputArchive iarch(ss);
		iarch(*this);
	}

}

void Usuario::load(const Json::Value& js) {

	this->id = js.get("id", this->id).asString();
	this->password = js.get("password", this->password).asString();
	this->nombre = js.get("nombre", this->nombre).asString();
	this->foto = js.get("foto", this->foto).asString();
	this->fotochica = js.get("fotochica", this->fotochica).asString();
	this->ubicacion = js.get("ubicacion", this->ubicacion).asString();
	this->telefono = js.get("telefono", this->telefono).asString();
	this->email = js.get("email", this->email).asString();
	this->appear_offline = js.get("appear_offline", this->appear_offline).asBool();

}

std::string Usuario::asJson() const {

	Json::Value js;
	js["id"] = this->id;
	js["nombre"] = this->nombre;
	js["foto"] = this->foto;
	js["fotochica"] = this->fotochica;
	js["ubicacion"] = this->ubicacion;
	js["estado"] = this->estado;
	js["telefono"] = this->telefono;
	js["email"] = this->email;
	js["ultimoacceso"] = std::to_string(this->last_action);

	std::stringstream ss;
	ss << js;
	return ss.str();
}
