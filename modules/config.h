#pragma once
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*! \mainpage Documentacion proyecto MensajerO
 * Siga los links en el menu para ver la documentacion.
 * Para instalar el servidor, ver el README en el dir raiz del proyecto.
 */

// Constants
/// # mongoose threads
const int NUM_THREADS = 8;
/// Segundos de inactividad para que expire la sesion
const int SESSION_EXPIRE_SECONDS = 30;
/// Cantidad de chars en session token
const int TOKEN_LENGTH = 16;
/// Cantidad de lineas de conversaciones a guardar
const size_t CONVERSACION_MAX_LINES = 10;

/// Clase para manejo de configuracion
struct Config {

	// Attribs
	/// Archivo de base de datos
	std::string db_file;
	/// Flags de loggeo
	bool l_warn, l_debug, l_error, l_info;
	/// Puerto de conexiones
	std::string port;
	bool start; // if false, the server startup is aborted

	/// Parse el CLI y guarda las opciones
	void parse(int argc, char* argv[]) {

		// Setup defaults
		l_warn = l_error = l_info = true;
		l_debug = false;
		db_file = "database.db";
		port = "5000";
		start = true;

		// Parse
		if(argc == 1) return;

		int c;
		while((c = getopt (argc, argv, "hp:d:l:")) != -1) {
			switch(c) {
				case 'h':
					printUsage();
					return;
				case 'p': {
					port = optarg;
					break;
				}
				case 'd':
					db_file = std::string(optarg) + std::string(".db");
					break;
				case 'l': {
					int level = atoi(optarg);
					if(level == 0) {
						l_error = true; l_warn = false; l_info = false; l_debug = false;
					}else if(level == 1) {
						l_error = true; l_warn = true; l_info = false; l_debug = false;
					}else if(level == 2) {
						l_error = true; l_warn = true; l_info = true; l_debug = false;
					}else if(level == 3) {
						l_error = true; l_warn = true; l_info = true; l_debug = true;
					}else{
						printUsage();
					}
					break;
				}
				default:
					printUsage();
					return;
			}
		}

	}

	/// Imprime los posibles usos por consola
	void printUsage() {
		printf("Usage: server [-p <port>] [-d <database>] [-l <log-level>]\n");
		printf("log-levels:\n");
		printf("\t0:\terror\n");
		printf("\t1:\terror+warn\n");
		printf("\t2:\terror+warn+info\n");
		printf("\t3:\terror+warn+info+debug\n");
		printf("--default: 3\n");
		start = false;
	}

};
