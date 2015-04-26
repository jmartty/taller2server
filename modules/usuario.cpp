#include "usuario.h"
#include <sstream>
#include <string>
#include <json/json.h>

// Constructor from serialized string
Usuario::Usuario(const std::string& str) {

	unserialStr(str);

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

// Unserial from str
void Usuario::unserialStr(const std::string& str) {

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
	this->ubicacion = js.get("ubicacion", this->ubicacion).asString();

}

std::string Usuario::asJson() const {

	Json::Value js;

}
