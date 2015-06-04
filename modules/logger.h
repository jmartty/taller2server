#pragma once

#include <iostream>
#include <fstream>
#include <bitset>
#include "request.h"

// Log types
namespace LOG_TYPE {
	enum {
		WARN = 0,
		DEBUG = 1,
		ERROR = 2,
		INFO = 3
	};
};

class Logger {

	public:

	// Singleton instance get
	static Logger& get();

	// Open and close
	bool open(const std::string& path);
	void close();

	// Log and level control
	// Overrideamos para los distintos tipos
	void msg(const int& type, std::string msg);
	void msg(const int& type, const RequestResult& reqres);
	// By default all levels are off
	void toggle(const int& type, bool val);

	// Devuelve un string con el timestamp actual
	static std::string timestamp();
	private:

	// Singleton, no permitir crear o copiar
	Logger() { }
	Logger(const Logger&);
	void operator=(const Logger&);

	// members
	std::ofstream conexion;
	std::bitset<4> flags;
};
