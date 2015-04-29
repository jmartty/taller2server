#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

#include "logger.h"
#include "server.h"

int main(int argc, char* argv[]) {

	try {
		srand(std::time(nullptr));
		Server server;
		server.init(argc, argv);
		server.run();
		return 0;

	}catch(const std::exception& e) {

		std::cerr << "Exception: " << e.what() << std::endl;
		return -1;

	}catch(...) {

		std::cerr << "Unhandled exception" << std::endl;
		return -2;

	}

}
