#include "../../modules/database.h"
#include <iostream>

//
// Test para cargar una base de datos y un par key/value raw
//

int main(int argc, char* argv[]) {

	// Test open/create db
	Database db;
	if(!db.open("test.db")) {
		std::cout << "Error abriendo DB\n";
		return -1;
	}

	// Test set KV
	if(!db.setValue("key", "value")) {
		std::cout << "Error setteando KV\n";
		return -1;
	}

	// Test existe key
	if(!db.keyExists("key)) {
		std::cout << "Error, key existente no existe\n");
		return -1;
	}

	// Test key value
	std::string val = db.getValue("key");
	if(val != "value") {
		std::cout << "Error, key value mismatch\n");
		return -1;
	}

	return 0;
}
