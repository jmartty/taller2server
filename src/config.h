#include <string.h>
#include <stdio.h>

struct Config {

	// Attribs
	std::string db_file;
	bool l_warn, l_debug, l_error, l_info;

	// Parse and store options
	Config(int argc, char* argv[]) {

		// Setup defaults
		l_warn = l_error = l_info = true;
		l_debug = false;
		db_file = "database.db";

		// Parse
		if(argc == 1) return;
		if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
			printf("server [-d <database>] [log-levels]\n");
			printf("log-levels:\n");
			printf("\t+warn/-warn:\t habilitar/deshabilitar mensajes de warning\n");
			printf("\t+error/-error:\t habilitar/deshabilitar mensajes de error\n");
			printf("\t+info/-info:\t habilitar/deshabilitar mensajes de informacion\n");
			printf("\t+debug/-debug:\t habilitar/deshabilitar mensajes de debug\n");
			printf("--default: +warn +error +info -debug:\n");
		}

		// Parse for database file
		int parse_i = 1;
		if(argc == 2 && !strcmp(argv[1], "-d")) {
			printf("Error specifying database, using database.db\n");
		}else if(argc >= 3 && !strcmp(argv[1], "-d")) {
			db_file = std::string(argv[2]) + ".db";
			parse_i = 3;
		}

		// Parse the rest for log flags
		while(parse_i < argc) {
			if(!strcmp(argv[parse_i], "+warn")) {
				l_warn = true;
			}else if(!strcmp(argv[parse_i], "-warn")) {
				l_warn = false;
			}else if(!strcmp(argv[parse_i], "+info")) {
				l_info = true;
			}else if(!strcmp(argv[parse_i], "-info")) {
				l_info = false;
			}else if(!strcmp(argv[parse_i], "+error")) {
				l_error = true;
			}else if(!strcmp(argv[parse_i], "-error")) {
				l_error = false;
			}else if(!strcmp(argv[parse_i], "+debug")) {
				l_debug = true;
			}else if(!strcmp(argv[parse_i], "-debug")) {
				l_debug = false;
			}
			parse_i++;
		}

	}

};
