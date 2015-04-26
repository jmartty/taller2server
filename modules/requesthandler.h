#pragma once

#include <unordered_map>

#include "database.h"
#include "request.h"
#include "mongoose.h"
#include "config.h"

// RequestTable type: strmethod.URI -> Request*
// Examples:
// "GET./Login" -> &RequestGETLogin
// "POST./Usuario" -> &RequestPOSTUsuario
typedef std::unordered_map<std::string, Request*> RequestTable;

class RequestHandler {

	public:

	RequestHandler();
	~RequestHandler();
	// Install all REST resources and routes
	void installRequests(Database* db);
	// Start the web server and handle requests
	void serveRequests(const std::string& port);

	private:

	// Methods to install and serve requests
	int serve(struct mg_connection *conn, const std::string& method, const std::string& uri, const std::string& query_params, const std::string& content);
	void install(const std::string& methodURI, Request* req);

	// Table to store installed requests
	RequestTable routes;

	// Database pointer
	Database* db;

	// Mongoose stuff
	std::vector<mg_server*> servers;
	static int web_evhandler(struct mg_connection *conn, enum mg_event ev);

};
