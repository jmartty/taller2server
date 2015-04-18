#pragma once

#include <iostream>
#include <fstream>
#include <bitset>

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
	// Open and close
	bool open(const std::string& path);
	void close();


	// Log and level control
	void msg(const int& type, const std::string& msg);
	// By default all levels are off
	void toggle(const int& type, bool val);

	private:

	std::ofstream conexion;
	std::bitset<4> flags;
};
