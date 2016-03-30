#include <iostream>
#include "windows.h"
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
*/

TEST(ConstructorTimeStamp, Default){ // TODO Moet nog gedaan worden, weet momenteel niet zogoed hoe ik zijn returnwaarde moet testen/printen
	clock::time_stamp a = clock::time_stamp();
}

TEST(ConstructorTimeStamp, Copy){
	clock::time_stamp a = clock::time_stamp(); //Vanaf standaard constructor
	clock::time_stamp b = a;
	
	EXPECT_EQ(a, b) << "Copy constructor maakt gelijke objecten";
}

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