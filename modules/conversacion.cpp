#include <cassert>
#include "conversacion.h"
#include <sstream>
#include <string>
#include <json/json.h>
#include <algorithm>

// Serializacion
// Actual serial
std::string Conversacion::serialStr() const {

	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
	{
		cereal::BinaryOutputArchive oarch(ss);
		oarch(*this);
	}
	return ss.str();

}

// Unserial from str
void Conversacion::unserialStr(const std::string& str) {

	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
	ss.write(str.data(), str.size());
	{
		cereal::BinaryInputArchive iarch(ss);
		iarch(*this);
	}

}

std::string Conversacion::asJson() const {

/*        // Pasa la lista de usuarios a JSON y ademas
        auto c = lines.size();
        // Build JSON reply
        std::string ret("[ ");
        size_t i = 0;
        for(const auto& line : lines) {
                ret += "{\"id\": \"";
                ret += usr.id;
                ret += "\", \"nombre\": \"";
                ret += usr.nombre;
                ret += "\", \"estado\": \"";
                ret += usr.estado;
                ret += "\"}";
                if(i+1 != c)
                        ret += ", ";
                        i++;
                }
        ret += " ]";
        return ret;
*/

}


void Conversacion::orderUsers(std::string& lhs, std::string& rhs) {

	if(lhs > rhs) std::swap(lhs, rhs);

}

// Convierte el user_id en indice para la conversacion
size_t Conversacion::userToIndex(const std::string& id) {

	size_t ret = 999;
	if(id == users[0]) {
		ret = 0;
	}else if(id == users[1]) {
		ret = 1;
	}
	assert(ret != 999);
	return ret;

}

// Convierte el indice en el nombre de usuario
std::string Conversacion::indexToUser(size_t i) {

	assert(i == 0 || i == 1);
	return users[i];

}

