#include <cassert>
#include "rocksdb/db.h"
#include <iostream>

int main() {

	rocksdb::DB* db;
	rocksdb::Options options;
	options.create_if_missing = true;
	rocksdb::Status status = rocksdb::DB::Open(options, "testdb.rocksdb", &db);
	assert(status.ok());
	std::cout << "corre bien\n";
}
