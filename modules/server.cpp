#include <exception>
#include <sstream>
#include <string>
#include <stdexcept>

#include "server.h"
#include "logger.h"

static Logger& log = Logger::get();

void Server::init(int argc, char* argv[]) {

	// Parse and store settings
	config.parse(argc, argv);
	if(!config.start) return;

	// Setup logger
	if(!log.open("event.log")) {
		std::cerr << "Error abriendo log!\n";
	}

        //  Ponemos todos los modos de loggeo
        log.toggle(LOG_TYPE::DEBUG, config.l_debug);
        log.toggle(LOG_TYPE::WARN, config.l_warn);
        log.toggle(LOG_TYPE::INFO, config.l_info);
        log.toggle(LOG_TYPE::ERROR, config.l_error);

	// Abrimos la base de datos
	if(!db.open(config.db_file)) {
		std::stringstream err;
		err << "Error abriendo DB `" << config.db_file << "`";
		log.msg(LOG_TYPE::ERROR, err.str());
		throw std::runtime_error(err.str());
	}

	log.msg(LOG_TYPE::INFO, "Server init");

}

void Server::run() {

	log.msg(LOG_TYPE::INFO, "Running server");

	reqh.installRequests(&db);
	reqh.serveRequests(config.port);

}

Server::~Server() {

	log.msg(LOG_TYPE::INFO, "Server shutdown");
	log.close();

}
