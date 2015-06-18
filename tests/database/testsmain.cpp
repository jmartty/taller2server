#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cstdio>
#include "database.h"

using testing::ReturnNew;
using testing::Return;

TEST(Database, CreateOnOpen) {
	Database db;
	std::remove("test.db");
	EXPECT_TRUE(db.open("test.db"));
	db.close();
	std::system("rm -r test.db");
}

TEST(Database, KeyExists) {
	Database db;
	EXPECT_TRUE(db.open("test.db"));
	EXPECT_FALSE(db.exists("key"));
	EXPECT_TRUE(db.put("key", "value"));
	EXPECT_TRUE(db.exists("key"));
	db.close();
	std::system("rm -r test.db");
}

TEST(Database, DeleteKey) {
	Database db;
	EXPECT_TRUE(db.open("test.db"));
	EXPECT_TRUE(db.put("key", "value"));
	EXPECT_TRUE(db.exists("key"));
	EXPECT_TRUE(db.del("key"));
	EXPECT_FALSE(db.exists("key"));
	db.close();
	std::system("rm -r test.db");
}

TEST(Database, SetAndGet) {
	Database db;
	EXPECT_TRUE(db.open("test.db"));
	std::string val;
	EXPECT_TRUE(db.put("key", "value"));
	val = db.get("key");
	db.close();
	EXPECT_STREQ("value", val.c_str());
	std::system("rm -r test.db");
}

TEST(Database, TestUsuario) {
	Database db;
	Usuario usr,usr2;
	usr.id = "pepe";
	usr.nombre = "Pepe";
	usr.password = "123";
	std::string str;
	EXPECT_TRUE(db.open("test.db"));
	EXPECT_FALSE(db.usuarioExists(usr.id));
	EXPECT_FALSE(db.saveUsuario(usr));
	EXPECT_TRUE(db.createUsuario(usr, str));
	EXPECT_TRUE(db.usuarioExists(usr.id));
	auto lu = db.getListaUsuarios();
	EXPECT_EQ(lu.size(), (size_t)1);
	EXPECT_EQ(lu.count(usr.id), (size_t)1);
	EXPECT_FALSE(db.usuarioExists("otro_usuario"));
	EXPECT_TRUE(db.loadUsuario(usr.id, usr2));
	db.close();
	EXPECT_STREQ(usr.id.c_str(), usr2.id.c_str());
	std::system("rm -r test.db");
}



int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
  	testing::InitGoogleMock(&argc, argv);
  	return RUN_ALL_TESTS();
}
