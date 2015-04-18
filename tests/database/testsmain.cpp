#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::ReturnNew;
using testing::Return;

TEST(Database, StoreAndRetrieve) {
	ASSERT_TRUE(true);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
  	testing::InitGoogleMock(&argc, argv);
  	return RUN_ALL_TESTS();
}
