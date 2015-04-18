#include <cassert>
#include "rocksdb/db.h"
#include <iostream>
#include "database.h"

/*
Database::Database(){

};*/

bool Database::open(const std::string& file){
	rocksdb::DB* db_nueva;
	db = db_nueva;
	rocksdb::Options options;
	options.create_if_missing = true;
	rocksdb::Status status = rocksdb::DB::Open(options, "/../RocksDB", &db);
	options.error_if_exists = true;

	return true;
}


bool Database::setValue(const std::string& key, const std::string& value){

	db->Put(rocksdb::WriteOptions(), key, value);
	return true;
}


bool Database::keyExists(const std::string& key){
	std::string value = "";
	rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key, &value);
	if (value == ""){
		return false;
	}
	return true;
}
std::string Database::getValue(const std::string& key){

	std::string value;
	rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key, &value);
	return value;
}
void Database::close(){

	delete db;
	return;
}
