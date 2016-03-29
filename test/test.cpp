#include "gtest\gtest.h"
#include "..\source\include\clock.hpp"

//REMOVE ONCE ACTUAL TESTS HAVE BEEN IMPLEMENTED
TEST(Clock, Adding){
	clock::duration abc = clock::duration();
	clock::duration ac = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration ab = clock::duration(std::chrono::duration<long, std::micro>(5));
	EXPECT_EQ(abc += ac, ab);
}

//ACTUAL TESTS
TEST(Clock, get_current_time){
	EXPECT_EQ(clock::get_current_time(), std::chrono::high_resolution_clock::now());
}

int main(int ac, char* av[]) {
	::testing::InitGoogleTest(&ac, av);
 	return RUN_ALL_TESTS();
}