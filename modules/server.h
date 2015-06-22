#pragma once
#include "logger.h"
#include "config.h"
#include "database.h"
#include "requesthandler.h"

/// Clase wrapper para todo el servidor
class Server {

	public:
	/// Carga el servidor desde la linea de comandos
	bool init(int argc, char* argv[]);
	/// Corre el servidor
	void run();
	~Server();

	private:
	/// Configuracion
	Config config;
	/// Base de datos
	Database db;
	/// Handler de requests
	RequestHandler reqh;
};
