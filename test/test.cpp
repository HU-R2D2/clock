#include <iostream>
#include "windows.h"
#include "gtest\gtest.h"
#include "..\source\include\clock.hpp"

/*
	duration
*/
//c	onst duration& operator+=(const duration& d);
TEST(AddAssign, ConstTimeStamp) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(20));

	a += b;
	
	EXPECT_EQ(a , c);
}
//	const duration& operator-=(const duration& d);
TEST(SubstractAssign, ConstDuration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(20));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(10));

	a -= b;
	
	EXPECT_EQ(a , c);
}
//	const duration& operator*=(const int rhs);
TEST(MultiplyAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	a *= 2;
	
	EXPECT_EQ(a , b);
	EXPECT_NE(a , c);
}
//	const duration& operator/=(const int rhs);
TEST(DivideAssign, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(5));

	a /= 2;
	
	EXPECT_EQ(a , c);
	EXPECT_NE(a , b);
}
//	bool operator==(const duration& rhs) const;
TEST(IsEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(20));
	
	EXPECT_TRUE(a == b);
	EXPECT_FALSE(a == c);
}
//	bool operator!=(const duration& rhs) const;
TEST(IsNotEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(10));
	
	EXPECT_TRUE(a != b);
	EXPECT_FALSE(a != c);
}
//	bool operator<(const duration& rhs) const;
TEST(LessThanDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));
	
	EXPECT_TRUE(b < c);
	EXPECT_FALSE(b < a);
}
//	bool operator<=(const duration& rhs) const;
TEST(LessOrEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b <= c);
	EXPECT_TRUE(b <= b);
	EXPECT_FALSE(b <= a);
}
//	bool operator>(const duration& rhs) const;
TEST(GreaterThanDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b > a);
	EXPECT_FALSE(b > c);
}
//	bool operator>=(const duration& rhs) const;
TEST(GreaterOrEqualDuration, Constduration) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(15));

	EXPECT_TRUE(b >= a);
	EXPECT_TRUE(b >= b);
	EXPECT_FALSE(b >= c);
}
//	duration operator+(const clock::duration& rhs) const;
TEST(AddDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(10));

	clock::duration d = a + b;
	
	EXPECT_EQ(d , c);
}
//	duration operator-(const clock::duration& rhs) const;
TEST(SubstractDuration, ConstClock) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::duration c = clock::duration(std::chrono::duration<long, std::micro>(5));
	
	clock::duration d = a - b;
	
	EXPECT_EQ(d, c);
}
//	duration operator*(const int rhs) const;
TEST(MultiplyDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(20));
	
	clock::duration c = a * 2;
	
	EXPECT_EQ(c, b);
}
//	duration operator/(const int rhs) const;
TEST(DivideDuration, ConstInt) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));

	clock::duration c = a / 2;

	EXPECT_EQ(c, b);
}

/*
	time_stamp
*/
//	time_stamp();
TEST(ConstructorTimeStamp, Default){ // TODO Moet nog gedaan worden, weet momenteel niet zogoed hoe ik zijn returnwaarde moet testen/printen
	clock::time_stamp a = clock::time_stamp();
}
//	time_stamp(const time_stamp& arg) = default;
TEST(ConstructorTimeStamp, Copy){
	clock::time_stamp a = clock::time_stamp(); //Vanaf standaard constructor
	clock::time_stamp b = a;
	
	EXPECT_EQ(a, b) << "Copy constructor maakt gelijke objecten";
}
//	bool operator==(const clock::time_stamp& rhs) const;
TEST(IsEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp(); //Vanaf standaard constructor
	clock::time_stamp b = a;
	
	
	EXPECT_TRUE(a == b) << "Default copy constructor gelijk";
	
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp(t1);
	b = clock::time_stamp(t1);
	
	EXPECT_TRUE(a == b) << "Equal vanaf time_point constructor";

	Sleep(1);
	b = clock::time_stamp();
	EXPECT_FALSE(a == b) << "Returns false voor verschillende timestamps";
}
//	bool operator!=(const clock::time_stamp& rhs) const;
TEST(IsNotEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp();
	Sleep(1);
	clock::time_stamp b = clock::time_stamp();
	
	EXPECT_TRUE(a != b) << "2 default constructors ongelijk met Sleep(1ms) ertussen";
	
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp(t1);
	b = clock::time_stamp(t1);
	EXPECT_FALSE(a != b) << "2 gelijke timestamps geven false terug";
}
//	bool operator<(const clock::time_stamp& rhs) const;
TEST(LessThanTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp();
	Sleep(1);
	clock::time_stamp b = clock::time_stamp();
	EXPECT_TRUE(a < b) << "Returns true als a < b";
	EXPECT_FALSE(b < a) << "Returns false bij b < a";
	
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp(t1);
	b = clock::time_stamp(t1);
	
	EXPECT_FALSE(a < b) << "Returns false bij gelijke waarde";
}
//	bool operator<=(const clock::time_stamp& rhs) const;
TEST(LessOrEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp();
	Sleep(1);
	clock::time_stamp b = clock::time_stamp();
	EXPECT_TRUE(a <= b) << "Returns true als a <= b";
	EXPECT_FALSE(b <= a) << "Returns false als b <= a";
	
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp(t1);
	b = clock::time_stamp(t1);
	
	EXPECT_TRUE(a <= b) << "Returns true bij gelijke waarde";
}
//	bool operator>(const clock::time_stamp& rhs) const;
TEST(GreaterThanTimeStamp, ConstTimeStamp) {
	clock::time_stamp b = clock::time_stamp();
	Sleep(1);
	clock::time_stamp a = clock::time_stamp();
	EXPECT_TRUE(a > b) << "Returns true als a > b";
	EXPECT_FALSE(b > a) << "Returns false als b > a";
	
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp(t1);
	b = clock::time_stamp(t1);
	
	EXPECT_FALSE(a > b) << "Returns false bij gelijke waarde";
}
//	bool operator>=(const clock::time_stamp& rhs) const;
TEST(GreaterOrEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp b = clock::time_stamp();
	Sleep(1);
	clock::time_stamp a = clock::time_stamp();
	EXPECT_TRUE(a >= b) << "Returns true als a >= b";
	EXPECT_FALSE(b >= a) << "Returns false als b >= a";
	
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp(t1);
	b = clock::time_stamp(t1);
	
	EXPECT_TRUE(a >= b) << "Returns true bij gelijke waarde";
}
//	clock::duration operator-(const clock::time_stamp& rhs) const;
TEST(DifferenceTimeStamp, ConstTimeStamp) {
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	Sleep(1);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	
	clock::time_stamp a = clock::time_stamp(t1);
	clock::time_stamp b = clock::time_stamp(t2);
	
	clock::duration d1 = clock::duration(std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1));
	clock::duration	d2 = b - a;
	EXPECT_EQ(d1 , d2) << "De clock::duration van het verschil tussen de time_stamps is gelijk aan de duration cast";
	
	d2 = a - b;
	EXPECT_NE(d1 , d2) << "De volgorde van aftrekken omdraaien om andere negatieve duration te krijgen";
	
	d1 = clock::duration(std::chrono::duration_cast<std::chrono::microseconds>(t1 - t2));
	EXPECT_EQ(d1 , d2) << "De clock::duration van het verschil tussen de time_stamps is gelijk aan de duration cast geinverteerd";
}

/*
	Friend functions
*/

TEST(AddAssignFriend, time_stampDuration) {
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

//	clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);
TEST(addAssign_Timestamp_Duration, constTimeStamp) {
	clock::time_stamp a = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));

	a+=b;

	EXPECT_EQ(a, c);
}
//	clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);
TEST(subtractAssign_Timestamp_Duration, constTimeStamp) {
	clock::time_stamp a = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(0)));

	a-=b;

	EXPECT_EQ(a, c);
}
//	clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);
TEST(add_TimeStamp_Duration, constTimeStamp) {
	clock::time_stamp a = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(5)));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(5));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));

	clock::time_stamp d = a + b;

	EXPECT_EQ(d, c);
}
//	clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);
TEST(subtract_TimeStamp_Duration, constTimeStamp) {
	clock::time_stamp a = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));
	clock::duration b = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(0)));

	clock::time_stamp d = a - b;

	EXPECT_EQ(d, c);
}
//	clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);
TEST(add_Duration_TimeStamp, constTimeStamp) {
	clock::duration a = clock::duration(std::chrono::duration<long, std::micro>(10));
	clock::time_stamp b = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(10)));
	clock::time_stamp c = clock::time_stamp(std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::duration<long, std::micro>(0)));

	clock::time_stamp d = b + a;

	EXPECT_EQ(d, c);
}
/*
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
*/
int main(int ac, char* av[]) {
	::testing::InitGoogleTest(&ac, av);
 	return RUN_ALL_TESTS();
}
