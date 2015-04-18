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

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
  	testing::InitGoogleMock(&argc, argv);
  	return RUN_ALL_TESTS();
}
