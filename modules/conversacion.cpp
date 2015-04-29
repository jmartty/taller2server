#include <ctime>
#include <cassert>
#include "conversacion.h"
#include "config.h"
#include "aux_func.h"
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

Conversacion::Conversacion(const std::string& user1, const std::string& user2) {

	// Cargamos los usuarios en orden alfabetico
	if(user1 > user2) {
		users[0] = user2;
		users[1] = user1;
	}else{
		users[0] = user1;
		users[1] = user2;
	}
}

// Deserial from str
void Conversacion::deserialStr(const std::string& str) {

	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
	ss.write(str.data(), str.size());
	{
		cereal::BinaryInputArchive iarch(ss);
		iarch(*this);
	}

}

std::string Conversacion::asJson() const {

        // Pasa la conversacion a JSON
        auto c = lines.size();
        // Build JSON reply
        std::string ret("[ ");
        size_t i = 0;
        for(const auto& line : lines) {
                ret += "{\"id\": \"";
                ret += users[line.autor];
                ret += "\", \"time\": \"";
                ret += toString(line.timestamp);
                ret += "\", \"msg\": \"";
                ret += line.msg;
                ret += "\"}";
                if(i+1 != c)
                        ret += ", ";
                        i++;
                }
        ret += " ]";
        return ret;

}


std::string Conversacion::keyGen(const std::string& user1, const std::string& user2) {

	const std::string* fst = &user1;
	const std::string* snd = &user2;
	if(user1 > user2) {
		std::swap(fst, snd);
	}
	std::stringstream ss;
	ss << "Conversacion." << *fst << "." << *snd;
	return ss.str();

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

void Conversacion::postear(const std::string& autor, const std::string& msg) {
	// Preparamos la nueva linea
	Line newLine;
	newLine.autor = userToIndex(autor);
	newLine.msg = msg;
	newLine.timestamp = std::time(nullptr);
	// La agregamos
	lines.push_back(newLine);
	// Si excedemos la cantidad de lineas a guardar, borramos la del frente
	if(lines.size() > CONVERSACION_MAX_LINES)
		lines.pop_front();

}
