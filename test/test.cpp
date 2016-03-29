#include "gtest\gtest.h"
#include "..\source\include\clock.hpp"

/*
	duration
*/

TEST(AddAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	a += b;
	
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(20));
}

TEST(RemoveAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(20));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	a -= b;
	
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(10));
	ASSERT_TRUE(b == std::chrono::duration<long, std::micro>(10));
}

TEST(MultiplyAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	a *= 2;
	
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(10));
	ASSERT_TRUE(a != std::chrono::duration<long, std::micro>(5));
}

TEST(DivideAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	a /= 2;
	
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(5));
	ASSERT_TRUE(a != std::chrono::duration<long, std::micro>(10));
}

TEST(ModuloAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	a %= 3;
	
	ASSERT_TRUE(a == 1);
	ASSERT_TRUE(a != std::chrono::duration<long, std::micro>(10));
	
	a %= 2;
	
	ASSERT_TRUE(a == 0);
	ASSERT_TRUE(a != std::chrono::duration<long, std::micro>(10));
}

TEST(ModuloAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(3));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(2));
	
	a %= b;
	
	ASSERT_TRUE(a == 1);
	ASSERT_TRUE(a != std::chrono::duration<long, std::micro>(10));
	
	a %= c;
	
	ASSERT_TRUE(a == 0);
	ASSERT_TRUE(a != std::chrono::duration<long, std::micro>(10));
}

TEST(IsEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(20));
	
	EXPECT_EQ(a == b); // True
	EXPECT_FALSE(a == c); // True because a == c is false
}

TEST(IsNotEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	ASSERT_TRUE(a != b);
	ASSERT_FALSE(a == b);
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
	
	ASSERT_TRUE(c == std::chrono::duration<long, std::micro>(10));
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(5));
	ASSERT_TRUE(b == std::chrono::duration<long, std::micro>(5));
}

TEST(RemoveDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	clock::duration c = a - b;
	
	ASSERT_TRUE(c == std::chrono::duration<long, std::micro>(5));
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(10));
	ASSERT_TRUE(b == std::chrono::duration<long, std::micro>(5));
}

TEST(MultiplyDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	clock::duration b = a * 2;
	
	ASSERT_TRUE(b == std::chrono::duration<long, std::micro>(50));
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(10));
}

TEST(DivideDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	clock::duration b = a / 2;
	
	ASSERT_TRUE(b == std::chrono::duration<long, std::micro>(5));
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(10));
}

TEST(ModuloDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	clock::duration b = a % 3;
	
	ASSERT_TRUE(b == std::chrono::duration<long, std::micro>(1));
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(10));
	
	clock::duration c = a % 2;
	
	ASSERT_TRUE(c == std::chrono::duration<long, std::micro>(0));
}

TEST(ModuloDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(3));
	
	clock::duration c = a % b;
	
	ASSERT_TRUE(c == std::chrono::duration<long, std::micro>(1));
	ASSERT_TRUE(a == std::chrono::duration<long, std::micro>(10));
	ASSERT_TRUE(b == std::chrono::duration<long, std::micro>(3));
	
	clock::duration d = clock::duration(std::chrono::duration<long, std::micro>(2));
	
	clock::duration e = a % d;
	
	ASSERT_TRUE(e == std::chrono::duration<long, std::micro>(0));
	ASSERT_TRUE(d == std::chrono::duration<long, std::micro>(2));
}

/*
	time_stamp
*/

TEST(IsEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	clock::time_stamp b = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	clock::time_stamp c = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(5));
	
	ASSERT_TRUE(a == b);
	ASSERT_TRUE(a != c);
	ASSERT_TRUE(b != c);
}

TEST(IsNotEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	clock::time_stamp b = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(5));
	clock::time_stamp c = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(10));
	
	ASSERT_TRUE(a != b);
	ASSERT_TRUE(a == c);
	ASSERT_TRUE(b != c);
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