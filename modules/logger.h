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
	void toggleWarn(bool val);
	void toggleDebug(bool val);
	void toggleError(bool val);
	void toggleInfo(bool val);

	private:

	std::ofstream conexion;
	std::bitset<4> flags;
};
