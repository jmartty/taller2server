#include "logger.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cassert>

Logger& Logger::get() {
	static Logger instance;
	return instance;
}

bool Logger::open(const std::string& path) {
	conexion.open(path.c_str(), std::ios_base::app);
	return conexion.is_open();
}

void Logger::msg(const int& type, const std::string& str) {

	// Abort if stream isnt writable
	if(!conexion.is_open() || !conexion.good()) return;
	// Generate timestamp
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
	std::string timestamp(buffer);
	timestamp.append(" - ");

	// Switch based on log type and log level
	if(type == LOG_TYPE::WARN) {
		if(flags[LOG_TYPE::WARN])
			conexion << timestamp << "WARN: " << str << std::endl;
	}else if(type == LOG_TYPE::INFO) {
		if(flags[LOG_TYPE::INFO])
			conexion << timestamp << "INFO: " << str << std::endl;
	}else if(type == LOG_TYPE::DEBUG) {
		if(flags[LOG_TYPE::DEBUG])
			conexion << timestamp << "DEBUG: " << str << std::endl;
	}else if(type == LOG_TYPE::ERROR) {
		if(flags[LOG_TYPE::ERROR])
			conexion << timestamp << "ERROR: " << str << std::endl;
	}else{
		conexion << timestamp << "UNKNOWN(" << type << "): " << str << std::endl;
	}
}

// Toggles for each log level
void Logger::toggle(const int& type, bool val) {
	assert(type >= 0 && type < 4);
	flags[type] = val;
}

// Close conexion
void Logger::close() {
	conexion << "------------------------------------------------" << std::endl;
	conexion.close();
}
