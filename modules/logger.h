#pragma once

#include <iostream>
#include <fstream>
#include <bitset>
#include "request.h"

namespace LOG_TYPE {
	/// Log types
	enum {
		WARN = 0,
		DEBUG = 1,
		ERROR = 2,
		INFO = 3
	};
};

/// Clase para loggeo de mensajes
class Logger {

	public:

	/// Singleton instance get
	static Logger& get();

	/// Abre el log en el archivo pasado por path
	/// @return true en caso de exito, false en caso de error
	bool open(const std::string& path);
	/// Cierra el log
	void close();

	/// Loggea el mensaje con el tipo solicitado
	void msg(const int& type, std::string msg);
	/// Loggea el resultado completo de un request
	void msg(const int& type, const RequestResult& reqres);
	/// Switch para activar o desactivar tipos de loggeo
	void toggle(const int& type, bool val);

	/// Devuelve un string con el timestamp actual
	static std::string timestamp();
	private:

	/// Singleton, no permitir crear o copiar
	Logger() { }
	/// Singleton, no permitir crear o copiar
	Logger(const Logger&);
	/// Singleton, no permitir crear o copiar
	void operator=(const Logger&);

	/// Stream de conexion
	std::ofstream conexion;
	/// Bit flags con los tipos de loggeo en on/off
	std::bitset<4> flags;
};
