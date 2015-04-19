#include <string>
#include "database.h"

// Interface para requests
// Return type
struct RequestResult {
	int code;
	std::string body;
};

// Interface
struct Request {

	virtual ~Request() {}
	virtual RequestResult process(Database* db, const std::string& params, const std::string& body) = 0;

};
