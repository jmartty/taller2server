#include <sstream>
#include <stdexcept>
#include <unistd.h>
#include "requesthandler.h"
#include "logger.h"

static Logger& log = Logger::get();

RequestHandler::RequestHandler() {

	// Set number of servers and init pointers to null
	servers.resize(NUM_THREADS);
	for(auto &i : servers) {
		i = nullptr;
	}

}

RequestHandler::~RequestHandler() {

	// Release allocated requests
	for(auto it = routes.begin();it != routes.end();it++)
		delete it->second;

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

	log.msg(LOG_TYPE::INFO, "Starting web service...");
	for(auto &i : servers) {
		i = mg_create_server((void*)this, RequestHandler::web_evhandler);
	}

	mg_set_option(servers[0], "listening_port", port.c_str());
	log.msg(LOG_TYPE::INFO, std::string("Listening on port ") + mg_get_option(servers[0], "listening_port"));

	for(auto i = 1;i < NUM_THREADS;i++) {
		mg_copy_listeners(servers[0], servers[i]);
	}

	for(auto &i : servers) {
		mg_start_thread(mg_serve, i);
	}

	// Do nothing till ctrl-break
	while(true)
		sleep(1);

}

int RequestHandler::web_evhandler(struct mg_connection *conn, enum mg_event ev) {

	// Fake 'this' via global
	RequestHandler* this_ = reinterpret_cast<RequestHandler*>(conn->server_param);

	// Handler segun API mg
	switch (ev) {
		case MG_AUTH: return MG_TRUE;
		case MG_REQUEST: {
			log.msg(LOG_TYPE::INFO, "Received MG_REQUEST");
			// Preparamos los datos y se los pasamos al servidor
			if (!strcmp(conn->uri, "/hello")) {
				mg_printf_data(conn, "{ \"msg\": \"Hello World\" }");
				sleep(15);
				return MG_TRUE;
			}
			return MG_FALSE;
		}
		default:
			return MG_FALSE;
	}

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

