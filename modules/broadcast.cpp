#include <ctime>
#include <cassert>
#include "broadcast.h"
#include "config.h"
#include "aux_func.h"
#include <sstream>
#include <string>
#include <json/json.h>
#include <algorithm>

// Serializacion
// Actual serial
std::string Broadcast::serialStr() const {

	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
	{
		cereal::BinaryOutputArchive oarch(ss);
		oarch(*this);
	}
	return ss.str();

}

// Deserial from str
void Broadcast::deserialStr(const std::string& str) {

	std::stringstream ss(std::stringstream::out | std::stringstream::in | std::stringstream::binary);
	ss.write(str.data(), str.size());
	{
		cereal::BinaryInputArchive iarch(ss);
		iarch(*this);
	}

}

std::string Broadcast::asJson(size_t num_lines) const {

        // Pasa la conversacion a JSON
        auto c = lines.size();
	// Limitamos la cantidad de lineas
	if(num_lines > 0 && c > num_lines) c = num_lines;
        // Build JSON reply
        std::string ret("[ ");
        size_t i = 0;
        for(const auto& line : lines) {
                ret += "{\"id\": \"";
                ret += line.autor_id;
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


void Broadcast::postear(const std::string& autor, const std::string& msg) {
	// Preparamos la nueva linea
	BroadcastLine newLine;
	newLine.autor_id = autor;
	newLine.msg = msg;
	newLine.timestamp = std::time(nullptr);
	// La agregamos
	lines.push_front(newLine);
	// Si excedemos la cantidad de lineas a guardar, borramos la del frente
	if(lines.size() > CONVERSACION_MAX_LINES)
		lines.pop_back();

}
