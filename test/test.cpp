#include <iostream>
#include "gtest\gtest.h"
#include "..\source\include\clock.hpp"

/*
	duration
*/

TEST(AddAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(20));

	a += b;
	
	EXPECT_EQ(a , c);
}

TEST(SubstractAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(20));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(10));

	a -= b;
	
	EXPECT_EQ(a , c);
}

TEST(MultiplyAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	a *= 2;
	
	EXPECT_EQ(a , b);
	EXPECT_NE(a , c);
}

TEST(DivideAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(5));

	a /= 2;
	
	EXPECT_EQ(a , c);
	EXPECT_NE(a , b);
}

TEST(IsEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(20));
	
	EXPECT_TRUE(a == b);
	EXPECT_FALSE(a == c);
}

TEST(IsNotEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	EXPECT_TRUE(a != b);
	EXPECT_FALSE(a != c);
}

TEST(LessThanDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));
	
	EXPECT_TRUE(b < c);
	EXPECT_FALSE(b < a);
}

TEST(LessOrEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b <= c);
	EXPECT_TRUE(b <= b);
	EXPECT_FALSE(b <= a);
}

TEST(GreaterThanDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b > a);
	EXPECT_FALSE(b > c);
}

TEST(GreaterOrEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b >= a);
	EXPECT_TRUE(b >= b);
	EXPECT_FALSE(b >= c);
}

TEST(AddDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(10));

	clock::duration d = a + b;
	
	EXPECT_EQ(d , c);
}

TEST(SubstractDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	clock::duration d = a - b;
	
	EXPECT_EQ(d, c);
}

TEST(MultiplyDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(20));
	
	clock::duration c = a * 2;
	
	EXPECT_EQ(c, b);
}

TEST(DivideDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));

	clock::duration c = a / 2;

	EXPECT_EQ(c, b);
}

/*
	time_stamp


TEST(IsEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));
	clock::time_stamp b = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));
	clock::time_stamp c = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	
	EXPECT_EQ(a , b);
	EXPECT_NE(a , c);
	EXPECT_NE(b , c);
}

TEST(IsNotEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));
	clock::time_stamp b = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	clock::time_stamp c = clock::time_stamp::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10));
	
	EXPECT_NE(a , b);
	EXPECT_EQ(a , c);
	EXPECT_NE(b , c);
}

TEST(LessThanTimeStamp, ConstTimeStamp) {
	
}

TEST(LessOrEqualTimeStamp, ConstTimeStamp) {
	
}

TEST(GreaterThanTimeStamp, ConstTimeStamp) {
	
}

TEST(GreaterOrEqualTimeStamp, ConstTimeStamp) {
	
}

TEST(SubstractTimeStamp, ConstTimeStamp) {
	
}

/*
	Friend functions
*/

TEST(AddAssignFriend, TimeStampDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::time_stamp b = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(15)));

	b += a;

	EXPECT_EQ(b, c);
}

TEST(SubstractAssignFriend, TimeStampDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::time_stamp b = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(15)));

	c -= a;

	EXPECT_EQ(c, b);
}

TEST(AddFriend, TimeStampDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::time_stamp b = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));

	clock::time_stamp d = b + a;

	EXPECT_EQ(d, c);
}

TEST(SubstractFriend, TimeStampDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::time_stamp b = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(15)));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));

	clock::time_stamp d = b - a;

	EXPECT_EQ(d, c);
}

TEST(AddFriend, DurationTimeStamp) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::time_stamp b = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));

	clock::time_stamp d = a + b;

	EXPECT_EQ(d, c);
}

TEST(ShiftLeft, StreamDuration) {
	std::ostream stream;
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));

	stream << a;

	EXPECT_EQ(stream, a);
}

TEST(ShiftLeft, StreamTimeStamp) {
	std::ostream stream;
	clock::time_stamp a = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));

	stream << a;

	EXPECT_EQ(stream, a);
}

int main(int ac, char* av[]) {
	::testing::InitGoogleTest(&ac, av);
 	return RUN_ALL_TESTS();
}