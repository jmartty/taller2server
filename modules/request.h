#include <string>
#include <unordered_map>
#include "database.h"

typedef std::unordered_map<std::string, std::string> QParams;

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
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& queryparams, const std::string& body) = 0;
        // Helper functions
        static std::string genToken();
	static QParams parseQueryParams(const std::string& qparams);

};
