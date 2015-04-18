#include <iostream>
#include <string>


class Database {
	rocksdb::DB* db;

	public:
	// Debe crear si no existe
	// Si existe, abrir
	bool open(const std::string& file);
	bool setValue(const std::string& key, const std::string& value);
	bool keyExists(const std::string& key);
	std::string getValue(const std::string& key);
	void close();
};
