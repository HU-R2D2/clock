#include <iostream>
#include <thread>
#include "gtest/gtest.h"
#include "../source/include/Clock.hpp"

// ====================
//	duration
// ====================

//	duration();
TEST(ConstructorDuration, Default) {
	Clock::Duration a = Clock::Duration();
	
	EXPECT_EQ(a, (std::chrono::duration<long, std::micro>(0)));
}

//	duration(const std::chrono::duration<long, std::micro>& arg);
TEST(ConstructorDuration, Argument) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	
	EXPECT_EQ(a, (std::chrono::duration<long, std::micro>(10)));
}

//	duration(const duration& arg) = default;
TEST(ConstructorDuration, Copy) {
	Clock::Duration a = Clock::Duration();
	Clock::Duration b(a);
	
	EXPECT_EQ(a, b);
}

//	const duration& operator+=(const duration& d);
TEST(AddAssign, ConstTimeStamp) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(20));

	a += b;
	
	EXPECT_EQ(a , c);
}

//	const duration& operator-=(const duration& d);
TEST(SubstractAssign, ConstDuration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(20));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));

	a -= b;
	
	EXPECT_EQ(a , c);
}

//	const duration& operator*=(const int rhs);
TEST(MultiplyAssign, ConstInt) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	
	a *= 2;
	
	EXPECT_EQ(a , b);
	EXPECT_NE(a , c);
}

//	const duration& operator/=(const int rhs);
TEST(DivideAssign, ConstInt) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));

	a /= 2;
	
	EXPECT_EQ(a , c);
	EXPECT_NE(a , b);
}

//	bool operator==(const duration& rhs) const;
TEST(IsEqualDuration, Constduration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(20));
	
	EXPECT_TRUE(a == b);
	EXPECT_FALSE(a == c);
}

//	bool operator!=(const duration& rhs) const;
TEST(IsNotEqualDuration, Constduration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	
	EXPECT_TRUE(a != b);
	EXPECT_FALSE(a != c);
}

//	bool operator<(const duration& rhs) const;
TEST(LessThanDuration, Constduration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(15));
	
	EXPECT_TRUE(b < c);
	EXPECT_FALSE(b < a);
}

//	bool operator<=(const duration& rhs) const;
TEST(LessOrEqualDuration, Constduration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b <= c);
	EXPECT_TRUE(b <= b);
	EXPECT_FALSE(b <= a);
}

//	bool operator>(const duration& rhs) const;
TEST(GreaterThanDuration, Constduration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b > a);
	EXPECT_FALSE(b > c);
}

//	bool operator>=(const duration& rhs) const;
TEST(GreaterOrEqualDuration, Constduration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b >= a);
	EXPECT_TRUE(b >= b);
	EXPECT_FALSE(b >= c);
}

//	duration operator+(const Clock::Duration& rhs) const;
TEST(AddDuration, ConstClock) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));

	Clock::Duration d = a + b;
	
	EXPECT_EQ(d , c);
}

//	duration operator-(const Clock::Duration& rhs) const;
TEST(SubstractDuration, ConstClock) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::Duration c = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	
	Clock::Duration d = a - b;
	
	EXPECT_EQ(d, c);
}

//	duration operator*(const int rhs) const;
TEST(MultiplyDuration, ConstInt) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(20));
	
	Clock::Duration c = a * 2;
	
	EXPECT_EQ(c, b);
}

//	duration operator/(const int rhs) const;
TEST(DivideDuration, ConstInt) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::Duration b = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));

	Clock::Duration c = a / 2;

	EXPECT_EQ(c, b);
}

// ====================
//	TimeStamp
// ====================

//	TimeStamp();
TEST(ConstructorTimeStamp, Default) {
	std::chrono::high_resolution_clock::time_point t = 
		std::chrono::high_resolution_clock::now();
	Clock::TimeStamp a = Clock::TimeStamp();

	std::time_t t1 = std::chrono::high_resolution_clock::to_time_t(t);
	std::time_t a1 = std::chrono::high_resolution_clock::to_time_t(a.m_time_stamp);
	
	EXPECT_EQ(a1, t1);
}

//	TimeStamp(const std::chrono::time_point<std::chrono::high_resolution_clock>& arg);
TEST(ConstructorTimeStamp, Argument) {
	std::chrono::high_resolution_clock::time_point t1 = 
		std::chrono::high_resolution_clock::now();
	Clock::TimeStamp a = Clock::TimeStamp(t1);
	
	EXPECT_EQ(a, t1);
}

//	TimeStamp(const TimeStamp& arg) = default;
TEST(ConstructorTimeStamp, Copy){
	Clock::TimeStamp a = Clock::TimeStamp();
	Clock::TimeStamp b(a);
	
	EXPECT_EQ(a, b);
}

//	bool operator==(const Clock::TimeStamp& rhs) const;
TEST(IsEqualTimeStamp, ConstTimeStamp) {
	Clock::TimeStamp a = Clock::TimeStamp();
	Clock::TimeStamp b = a;
	
	
	EXPECT_TRUE(a == b);
	
	std::chrono::high_resolution_clock::time_point t1 =
		std::chrono::high_resolution_clock::now();
	a = Clock::TimeStamp(t1);
	b = Clock::TimeStamp(t1);
	
	EXPECT_TRUE(a == b);

	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	b = Clock::TimeStamp();
	EXPECT_FALSE(a == b);
}

//	bool operator!=(const Clock::TimeStamp& rhs) const;
TEST(IsNotEqualTimeStamp, ConstTimeStamp) {
	Clock::TimeStamp a = Clock::TimeStamp();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	Clock::TimeStamp b = Clock::TimeStamp();
	
	EXPECT_TRUE(a != b);
	
	std::chrono::high_resolution_clock::time_point t1 = 
		std::chrono::high_resolution_clock::now();
	a = Clock::TimeStamp(t1);
	b = Clock::TimeStamp(t1);
	EXPECT_FALSE(a != b);
}

//	bool operator<(const Clock::TimeStamp& rhs) const;
TEST(LessThanTimeStamp, ConstTimeStamp) {
	Clock::TimeStamp a = Clock::TimeStamp();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	Clock::TimeStamp b = Clock::TimeStamp();
	EXPECT_TRUE(a < b);
	EXPECT_FALSE(b < a);
	
	std::chrono::high_resolution_clock::time_point t1 = 
		std::chrono::high_resolution_clock::now();
	a = Clock::TimeStamp(t1);
	b = Clock::TimeStamp(t1);
	
	EXPECT_FALSE(a < b);
}

//	bool operator<=(const Clock::TimeStamp& rhs) const;
TEST(LessOrEqualTimeStamp, ConstTimeStamp) {
	Clock::TimeStamp a = Clock::TimeStamp();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	Clock::TimeStamp b = Clock::TimeStamp();
	EXPECT_TRUE(a <= b);
	EXPECT_FALSE(b <= a);
	
	std::chrono::high_resolution_clock::time_point t1 = 
		std::chrono::high_resolution_clock::now();
	a = Clock::TimeStamp(t1);
	b = Clock::TimeStamp(t1);
	
	EXPECT_TRUE(a <= b);
}

//	bool operator>(const Clock::TimeStamp& rhs) const;
TEST(GreaterThanTimeStamp, ConstTimeStamp) {
	Clock::TimeStamp b = Clock::TimeStamp();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	Clock::TimeStamp a = Clock::TimeStamp();
	EXPECT_TRUE(a > b);
	EXPECT_FALSE(b > a);
	
	std::chrono::high_resolution_clock::time_point t1 = 
		std::chrono::high_resolution_clock::now();
	a = Clock::TimeStamp(t1);
	b = Clock::TimeStamp(t1);
	
	EXPECT_FALSE(a > b);
}

//	bool operator>=(const Clock::TimeStamp& rhs) const;
TEST(GreaterOrEqualTimeStamp, ConstTimeStamp) {
	Clock::TimeStamp b = Clock::TimeStamp();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	Clock::TimeStamp a = Clock::TimeStamp();
	EXPECT_TRUE(a >= b);
	EXPECT_FALSE(b >= a);
	
	std::chrono::high_resolution_clock::time_point t1 = 
		std::chrono::high_resolution_clock::now();
	a = Clock::TimeStamp(t1);
	b = Clock::TimeStamp(t1);
	
	EXPECT_TRUE(a >= b);
}

//	Clock::Duration operator-(const Clock::TimeStamp& rhs) const;
TEST(SubstractTimeStamp, ConstTimeStamp) {
	std::chrono::high_resolution_clock::time_point t1 = 
		std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	std::chrono::high_resolution_clock::time_point t2 = 
		std::chrono::high_resolution_clock::now();
	
	Clock::TimeStamp a = Clock::TimeStamp(t1);
	Clock::TimeStamp b = Clock::TimeStamp(t2);
	
	Clock::Duration d1 = 
		Clock::Duration(std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1));
	Clock::Duration	d2 = b - a;
	EXPECT_EQ(d1, d2);
	
	d2 = a - b;
	EXPECT_NE(d1, d2);
	
	d1 = 
		Clock::Duration(std::chrono::duration_cast<std::chrono::microseconds>(t1 - t2));
	EXPECT_EQ(d1, d2);
}

// ====================
//	Friend functions
// ====================

//	Clock::TimeStamp& operator+=(Clock::TimeStamp& lhs, const Clock::Duration& d);
TEST(AddAssignTimeStamp, ConstDuration) {
	Clock::Duration a = Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::TimeStamp b = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(5)));
	Clock::TimeStamp c = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(15)));

	b += a;

	EXPECT_EQ(b, c);
}

//	Clock::TimeStamp& operator-=(Clock::TimeStamp& lhs, const Clock::Duration& d);
TEST(SubstractAssignTimeStamp, ConstDuration) {
	Clock::Duration a = Clock::Duration(std::chrono::duration<long, std::micro>(10));
	Clock::TimeStamp b = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(5)));
	Clock::TimeStamp c = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(15)));

	c -= a;

	EXPECT_EQ(c, b);
}

//	Clock::TimeStamp operator+(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
TEST(AddTimeStamp, ConstDuration) {
	Clock::Duration a = Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::TimeStamp b = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(5)));
	Clock::TimeStamp c = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(10)));

	Clock::TimeStamp d = b + a;

	EXPECT_EQ(d, c);
}

//	Clock::TimeStamp operator-(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
TEST(SubstractTimeStamp, ConstDuration) {
	Clock::Duration a = 
		Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::TimeStamp b = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(15)));
	Clock::TimeStamp c = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(10)));

	Clock::TimeStamp d = b - a;

	EXPECT_EQ(d, c);
}

//	Clock::TimeStamp operator+(const Clock::Duration& lhs, const Clock::TimeStamp& rhs);
TEST(AddDuration, ConstTimeStamp) {
	Clock::Duration a = Clock::Duration(std::chrono::duration<long, std::micro>(5));
	Clock::TimeStamp b = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(5)));
	Clock::TimeStamp c = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(10)));

	Clock::TimeStamp d = a + b;

	EXPECT_EQ(d, c);
}

//	std::ostream & operator<<(std::ostream & s, const Clock::Duration & rhs);
TEST(ShiftLeft, StreamDuration) {
	Clock::Duration a = Clock::Duration(std::chrono::duration<long, std::micro>(5));

	std::cout << a << std::endl;
}

//	std::ostream & operator<<(std::ostream & s, const Clock::TimeStamp &rhs);
TEST(ShiftLeft, StreamTimeStamp) {
	Clock::TimeStamp a = 
		Clock::TimeStamp(std::chrono::time_point<std::chrono::high_resolution_clock>
			(std::chrono::duration<long, std::micro>(5)));

	std::cout << a << std::endl;
}

int main(int ac, char* av[]) {
	::testing::InitGoogleTest(&ac, av);
 	return RUN_ALL_TESTS();
}
