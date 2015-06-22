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

/// Request abstract base class (interface)
struct Request {

	virtual ~Request() {}
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& queryparams, const std::string& body) = 0;
        // Helper functions
	/// Genera un hash para usar de token de session
        static std::string genToken();
	/// Parsea los parametros en una query
	static QParams parseQueryParams(const std::string& qparams);

};
