#pragma once
#include <iostream>
#include <string>
#include <rocksdb/db.h>

class Database {

	public:
	// Debe crear si no existe
	// Si existe, abrir
	bool open(const std::string& file);
	bool put(const std::string& key, const std::string& value);
	bool exists(const std::string& key);
	bool del(const std::string& key);
	std::string get(const std::string& key);
	void close();

	private:
	rocksdb::DB* db;

};
