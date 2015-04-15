#include <string>
#include "database.h"

// Interface para requests
// Return type
struct RequestResult {
	// Defaults to HTTP 200 OK
	RequestResult() : code(200) { }
	int code;
	std::string data;
};

// Request abstract base class (interface)
struct Request {

	virtual ~Request() {}
	virtual RequestResult process(Database* db, const std::string& params, const std::string& body) = 0;

};
