#pragma once
#include "logger.h"
#include "config.h"
#include "database.h"
#include "requesthandler.h"

class Server {

	public:
	bool init(int argc, char* argv[]);
	void run();
	~Server();

	private:
	Config config;
	Database db;
	RequestHandler reqh;
};
