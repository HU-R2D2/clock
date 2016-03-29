#include "gtest\gtest.h"
#include "..\source\include\clock.hpp"

/*
	duration
*/

TEST(AddAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	a += b;
	
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(20));
}

TEST(RemoveAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(20));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	a -= b;
	
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(10));
	EXPECT_EQ(b, std::chrono::duration<long, std::micro>(10));
}

TEST(MultiplyAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	a *= 2;
	
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(10));
}

TEST(DivideAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	a /= 2;
	
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(5));
}

TEST(IsEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(20));
	
	EXPECT_EQ(a, b); // True
}

TEST(IsNotEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	ASSERT_TRUE(a != b);
	EXPECT_EQ(a, b);
}

TEST(LessThanDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	ASSERT_TRUE(a < b);
	ASSERT_FALSE(a > b);
}

TEST(LessOrEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(4));
	
	ASSERT_TRUE(a <= b);
	ASSERT_TRUE(c <= a);
}

TEST(GreaterThanDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	ASSERT_TRUE(a > b);
	ASSERT_FALSE(a < b);
}

TEST(GreaterOrEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(6));
	
	ASSERT_TRUE(a >= b);
	ASSERT_TRUE(c >= a);
}

TEST(AddDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	clock::duration c = a + b;
	
	EXPECT_EQ(c, std::chrono::duration<long, std::micro>(10));
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(5));
	EXPECT_EQ(b, std::chrono::duration<long, std::micro>(5));
}

TEST(RemoveDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	clock::duration c = a - b;
	
	EXPECT_EQ(c, std::chrono::duration<long, std::micro>(5));
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(10));
	EXPECT_EQ(b, std::chrono::duration<long, std::micro>(5));
}

TEST(MultiplyDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	clock::duration b = a * 2;
	
	EXPECT_EQ(b, std::chrono::duration<long, std::micro>(50));
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(10));
}

TEST(DivideDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	clock::duration b = a / 2;
	
	EXPECT_EQ(b, std::chrono::duration<long, std::micro>(5));
	EXPECT_EQ(a, std::chrono::duration<long, std::micro>(10));
}

/*
	time_stamp
*/

TEST(IsEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	clock::time_stamp b = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	clock::time_stamp c = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(5));
	
	EXPECT_EQ(a, b);
}

TEST(IsNotEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	clock::time_stamp b = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(5));
	clock::time_stamp c = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	
	EXPECT_EQ(a, c);
}

TEST(LessThanTimeStamp, ConstTimeStamp) {
	
}

TEST(LessOrEqualTimeStamp, ConstTimeStamp) {
	
}

TEST(GreaterThanTimeStamp, ConstTimeStamp) {
	
}

TEST(GreaterOrEqualTimeStamp, ConstTimeStamp) {
	
}

TEST(RemoveTimeStamp, ConstTimeStamp) {
	
}

/*
	Friend functions
*/

TEST(AddAssignFriend, TimeStampDuration) {
	
}

TEST(RemoveAssignFriend, TimeStampDuration) {
	
}

TEST(AddFriend, TimeStampDuration) {
	
}

TEST(RemoveFriend, TimeStampDuration) {
	
}

TEST(AddFriend, DurationTimeStamp) {
	
}

TEST(ShiftLeft, StreamDuration) {
	
}

TEST(ShiftLeft, StreamTimeStamp) {
	
}

int main(int ac, char* av[]) {
	::testing::InitGoogleTest(&ac, av);
 	return RUN_ALL_TESTS();
}