#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>

// Separa un string en vector<string> usando un delimitador dado
std::vector<std::string> explode(const std::string& delim, const std::string& str);

// Cuantos segundos pasaron desde 't' hasta now
time_t secondsFrom(const time_t& t);

// Convertir a string usando streams
template<typename T> 
std::string toString(const T& val) {
	std::stringstream ss;
	ss << val;
	return ss.str();
}
