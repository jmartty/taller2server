#pragma once
#include <string>
#include <unordered_map>
#include "database.h"

/// Tipo para resultado de parseo de parametros de query
typedef std::unordered_map<std::string, std::string> QParams;

/// Interface para resultados de requests
struct RequestResult {
	/// Defaults to HTTP 200 OK
	RequestResult() : code(200) { }
	/// Codigo de retorno HTTP
	int code;
	/// Respuesta en el content del request
	std::string data;
};

/// Tipo de puntero a funcion para requests
typedef RequestResult (*Request)(Database*, const std::string&, const std::string&, const std::string&);

// Helper functions
/// Genera un hash para usar de token de session
std::string genToken();

/// Parsea los parametros en una query
QParams parseQueryParams(const std::string& qparams);
