#include "gtest/gtest.h"

TEST() {
	ASSERT_EQ(10, 10);
}

int main() {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}