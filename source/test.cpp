#include "gtest\gtest.h"
#include "..\source\include\clock.hpp"

TEST(Clock, get_current_time){
	EXPECT_EQ(clock::get_current_time(), std::chrono::high_resolution_clock::now());
}

int main(int ac, char* av[]) {
	::testing::InitGoogleTest(&ac, av);
 	return RUN_ALL_TESTS();
}