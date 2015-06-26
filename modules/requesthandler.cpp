#include <sstream>
#include <stdexcept>
#include <unistd.h>
#include "requesthandler.h"
#include "logger.h"
RequestResult Request_POST_Login(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_GET_Test(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_POST_Usuario(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_GET_Usuarios(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_GET_Usuario(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_PUT_Usuario(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_POST_Conversacion(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_GET_Conversacion(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_GET_Broadcast(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
RequestResult Request_POST_Broadcast(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body);
static Logger& logger = Logger::get();

RequestHandler::RequestHandler() {

	// Set number of servers and init pointers to null
	servers.resize(NUM_THREADS);
	for(auto &i : servers) {
		i = nullptr;
	}

}

RequestHandler::~RequestHandler() {

	// Mongoose cleanup
        servers.resize(NUM_THREADS);
        for(auto &i : servers) {
                mg_destroy_server(&i);
        }

}

static void* mg_serve(void *server) {
	for (;;) mg_poll_server((struct mg_server *) server, 1000);
	return NULL;
}

void RequestHandler::serveRequests(const std::string& port) {

	// Setup del los threads de poll de mongoose
	logger.msg(LOG_TYPE::INFO, "Starting web service...");
	for(auto &i : servers) {
		i = mg_create_server((void*)this, RequestHandler::web_evhandler);
	}

	mg_set_option(servers[0], "listening_port", port.c_str());
	logger.msg(LOG_TYPE::INFO, std::string("Listening on port ") + mg_get_option(servers[0], "listening_port"));

	for(auto i = 1;i < NUM_THREADS;i++) {
		mg_copy_listeners(servers[0], servers[i]);
	}

	for(auto &i : servers) {
		mg_start_thread(mg_serve, i);
	}

	// Do nothing on main thread till ctrl-break
	while(true) sleep(60);

}

int RequestHandler::web_evhandler(struct mg_connection *conn, enum mg_event ev) {

	// Fake 'this' via conn->server_param
	RequestHandler* this_ = reinterpret_cast<RequestHandler*>(conn->server_param);

	// Handler segun API mg
	switch (ev) {
		case MG_AUTH: return MG_TRUE;
		case MG_REQUEST: {

			// Preparamos los datos y se los pasamos al servidor
			return this_->serve(conn, conn->request_method, conn->uri, (conn->query_string == nullptr ? "" : conn->query_string), std::string(conn->content, conn->content_len) );
		}
		default: return MG_FALSE;
	}

}

int RequestHandler::serve(struct mg_connection *conn, const std::string& method, const std::string& uri, const std::string& query_params, const std::string& content) {

	logger.msg(LOG_TYPE::INFO, std::string("Request (") + method + "): " + uri);


	// Parseamos el URI para diferenciar request de params
	std::string uri_resource;
	std::string uri_params;

	// Parseamos uri y sacamos el resource y params como tokens
	// Ej, foo/bar -> foo, bar
	// Buscamos la posicion del primer '/' sin contar el primer caracter
	auto fs_pos = uri.find('/', 1);
	// Sacamos el substring hasta la posicion
	uri_resource = uri.substr(0, fs_pos);
	// Si lo encontramos, el otro substring son los caracteres que quedan
	// Sin incluir el delimitador
	if(fs_pos != std::string::npos) {
		uri_params = uri.substr(fs_pos+1);
	}
	// Crafteamos el methodURI de acuerdo a la convencion
	std::string methodURI = method + "." + uri_resource;

	// Servimos el request
	if(routes.count(methodURI) == 0) {
		// Si no encontramos el methodURI en la tabla, 404
		return MG_FALSE;
	}else{
		logger.msg(LOG_TYPE::DEBUG, std::string("uri_params: ") + uri_params);
		logger.msg(LOG_TYPE::DEBUG, std::string("query_params: ") + query_params);
		logger.msg(LOG_TYPE::DEBUG, std::string("content: ") + content);
		RequestResult res;
		if(methodURI == "GET./test")
			res = Request_GET_Test(this->db, uri_params, query_params, content);
		else if(methodURI == "POST./login")
			res = Request_POST_Login(this->db, uri_params, query_params, content);
		else if(methodURI == "GET./usuarios")
			res = Request_GET_Usuarios(this->db, uri_params, query_params, content);
		else if(methodURI == "POST./usuario")
			res = Request_POST_Usuario(this->db, uri_params, query_params, content);
		else if(methodURI == "GET./usuario")
			res = Request_GET_Usuario(this->db, uri_params, query_params, content);
		else if(methodURI == "PUT./usuario")
			res = Request_PUT_Usuario(this->db, uri_params, query_params, content);
		else if(methodURI == "GET./conversacion")
			res = Request_GET_Conversacion(this->db, uri_params, query_params, content);
		else if(methodURI == "POST./conversacion")
			res = Request_POST_Conversacion(this->db, uri_params, query_params, content);
		else if(methodURI == "POST./broadcast")
			res = Request_POST_Broadcast(this->db, uri_params, query_params, content);
		else if(methodURI == "GET./broadcast")
			res = Request_GET_Broadcast(this->db, uri_params, query_params, content);
		mg_send_status(conn, res.code);
		mg_send_data(conn, res.data.c_str(), res.data.size());
		logger.msg(LOG_TYPE::DEBUG, res);
		return MG_TRUE;
	}

}

void RequestHandler::install(const std::string& methodURI, Request req) {

	if(routes.count(methodURI) == 0) {
		routes[methodURI] = req;
	}else{
		std::stringstream error;
		error << "Error installing '" << methodURI << "', entry already in table";
		logger.msg(LOG_TYPE::ERROR, error.str());
		throw std::runtime_error(error.str());
	}

}
