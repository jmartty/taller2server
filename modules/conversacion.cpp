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

	// Marco como leido todo
	unread[0] = unread[1] = false;
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

std::string Conversacion::asJson(size_t num_lines) const {

        // Pasa la conversacion a JSON
        auto c = lines.size();
	// Limitamos la cantidad de lineas
	if(num_lines > 0 && c > num_lines) c = num_lines;
        // Build JSON reply
        std::string ret("[ ");
        size_t i = 0;
        for(const auto& line : lines) {
                ret += "{\"id\": \"";
                ret += users[line.autor];
                ret += "\", \"time\": ";
                ret += std::to_string(line.timestamp);
                ret += ", \"msg\": \"";
                ret += line.msg;
                ret += "\"}";
                if(i+1 < c) {
			ret += ", ";
		}else{
			break;
		}
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
UserIndex Conversacion::userToIndex(const std::string& id) const {

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
std::string Conversacion::indexToUser(UserIndex i) const {

	assert(i == 0 || i == 1);
	return users[i];

}

void Conversacion::postear(const std::string& autor, const std::string& msg) {
	// Preparamos la nueva linea
	Line newLine;
	auto ai = userToIndex(autor);
	newLine.autor = ai;
	newLine.msg = msg;
	newLine.timestamp = std::time(nullptr);
	// La agregamos
	lines.push_front(newLine);
	// Marcamos como no leido para el otro usuario
	if(ai == 0) {
		unread[1] = true;
	}else if(ai == 1) {
		unread[0] = true;
	}
	// Si excedemos la cantidad de lineas a guardar, borramos la del frente
	if(lines.size() > CONVERSACION_MAX_LINES)
		lines.pop_back();

}

void Conversacion::markRead(const std::string& whoread) {
	unread[userToIndex(whoread)] = 0;
}

bool Conversacion::hasUnread(const std::string& user) const {
	return unread[userToIndex(user)];
}
