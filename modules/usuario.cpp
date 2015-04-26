#include "usuario.h"
#include <sstream>
#include <string>

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

