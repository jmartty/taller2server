#include "requesthandler.h"
#include "database.h"

// Define all requests here
struct RequestPUTLogin : public Request {
	virtual RequestResult process(Database* db, const std::string& params, const std::string& body) {
		RequestResult ret;
		// Do something
		return ret;
	}
};

// Install them
void RequestHandler::installRequests(Database*) {
	RequestPUTLogin* requestPUTLogin = new RequestPUTLogin;
	install("/Login", requestPUTLogin);
}
