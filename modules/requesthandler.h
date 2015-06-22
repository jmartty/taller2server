#pragma once

#include <unordered_map>

#include "database.h"
#include "request.h"
#include "mongoose.h"
#include "config.h"

/// RequestTable type: strmethod.URI -> Request*
/// Examples:
/// "GET./Login" -> &RequestGETLogin
/// "POST./Usuario" -> &RequestPOSTUsuario
typedef std::unordered_map<std::string, Request*> RequestTable;

/// Clase para el manejo de requests
class RequestHandler {

	public:

	RequestHandler();
	~RequestHandler();
	/// Instala todos los recursos y rutas del protocolo
	void installRequests(Database* db);
	/// Start the web server and handle requests
	void serveRequests(const std::string& port);

	private:

	// Methods to install and serve requests
	/// Callback interno para servir requests
	int serve(struct mg_connection *conn, const std::string& method, const std::string& uri, const std::string& query_params, const std::string& content);
	/// Instala un request particular
	/// @param methodURI ruta del request, por ejemplo "GET./login"
	void install(const std::string& methodURI, Request* req);

	/// Table to store installed requests
	RequestTable routes;

	/// Database pointer
	Database* db;

	// Mongoose stuff
	/// Vector de threads de mongoose
	std::vector<mg_server*> servers;
	/// Callback de mongoose
	static int web_evhandler(struct mg_connection *conn, enum mg_event ev);

};
