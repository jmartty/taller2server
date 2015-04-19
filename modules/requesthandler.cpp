#include <sstream>
#include <stdexcept>
#include "requesthandler.h"
#include "logger.h"

#define log Logger::get()

RequestHandler::RequestHandler() {

	web_server = nullptr;

}

RequestHandler::~RequestHandler() {

	// Release allocated requests
	for(auto it = routes.begin();it != routes.end();it++)
		delete it->second;

	// Mongoose cleanup
	mg_destroy_server(&web_server);

}

void RequestHandler::serveRequests(int port) {
}

void RequestHandler::serve(const std::string& methodURI, const std::string& params, const std::string& body) {
}

void RequestHandler::install(const std::string& methodURI, Request* req) {

	if(routes.count(methodURI) == 0) {
		routes[methodURI] = req;
	}else{
		std::stringstream error;
		error << "Error installing '" << methodURI << "', entry already in table";
		log.msg(LOG_TYPE::ERROR, error.str());
		throw std::runtime_error(error.str());
	}

}

