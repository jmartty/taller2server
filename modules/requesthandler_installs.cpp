#include "requesthandler.h"
#include "database.h"

// Define all requests here
struct Request_PUT_Login : public Request {
	virtual RequestResult process(Database* db, const std::string& params, const std::string& body) {
		RequestResult ret;
		// Do something
		return ret;
	}
};

struct Request_GET_Test : public Request {
	virtual RequestResult process(Database* db, const std::string& params, const std::string& body) {
		RequestResult ret;
		return ret;
	}
};

// Install them
void RequestHandler::installRequests(Database* db) {
	// Store db pointer
	this->db = db;
	// Format: install("method.URI", Request)
	install("PUT_/Login", new Request_PUT_Login);
	install("GET_/Test", new Request_GET_Test);

}
