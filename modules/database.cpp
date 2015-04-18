#include <cassert>
#include <iostream>
#include <rocksdb/db.h>
#include "database.h"

bool Database::open(const std::string& file){

	// Crea la base de datos si no existe
	rocksdb::Options options;
	options.create_if_missing = true;
	rocksdb::Status status = rocksdb::DB::Open(options, file, &db);
	return status.ok();

}


bool Database::put(const std::string& key, const std::string& value){
	rocksdb::Status status = db->Put(rocksdb::WriteOptions(), key, value);
	return status.ok();
}


bool Database::exists(const std::string& key){
	std::string value;
	rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key, &value);
	return s.ok() && !s.IsNotFound();
}

bool Database::del(const std::string& key){
	rocksdb::Status s = db->Delete(rocksdb::WriteOptions(), key);
	return s.ok();
}

std::string Database::get(const std::string& key){
	std::string value;
	rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key, &value);
	assert(s.ok());
	return value;
}

void Database::close(){
	delete db;
}
