#include <sstream>
#include <stdexcept>
#include <unistd.h>
#include "requesthandler.h"
#include "logger.h"

#define log Logger::get()

// esto es horrible pero no se me ocurrio una mejor manera
// global para pasar "this" (desde RequestHandler::) al event_handler de mg
RequestHandler* UGLY_HACK;

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

static void* mg_serve(void *server) {
	for (;;) mg_poll_server((struct mg_server *) server, 1000);
	return NULL;
}

void RequestHandler::serveRequests(const std::string& port) {

	log.msg(LOG_TYPE::INFO, "Starting web service...");
	UGLY_HACK = this;
	web_server = mg_create_server((void*)"1", RequestHandler::web_evhandler);
	web_server2 = mg_create_server((void*)"2", RequestHandler::web_evhandler);

	mg_set_option(web_server, "listening_port", port.c_str());
	log.msg(LOG_TYPE::INFO, std::string("Listening on port ") + mg_get_option(web_server, "listening_port"));

	mg_copy_listeners(web_server, web_server2);

	mg_start_thread(mg_serve, web_server);
	mg_start_thread(mg_serve, web_server2);

	while(true)
		sleep(1);

}

int RequestHandler::web_evhandler(struct mg_connection *conn, enum mg_event ev) {

	// Fake 'this' via global
	RequestHandler* this_ = UGLY_HACK;

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

