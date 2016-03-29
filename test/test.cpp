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

TEST(ConstructorTimeStamp, Default){ // TODO Moet nog gedaan worden, weet momenteel niet zogoed hoe ik zijn returnwaarde moet testen/printen
	clock::time_stamp a = clock::time_stamp::time_stamp();
}

TEST(ConstructorTimeStamp, Copy){
	clock::time_stamp a = clock::time_stamp::time_stamp(); //Vanaf standaard constructor
	clock::time_stamp b = a;
	
	EXPECT_EQ(a, b) << "Copy constructor maakt gelijke objecten";
}

TEST(IsEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp(); //Vanaf standaard constructor
	clock::time_stamp b = a;
	
	
	EXPECT_TRUE(a == b) << "Default copy constructor gelijk";
	
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp::time_stamp(t1);
	b = clock::time_stamp::time_stamp(t1);
	
	EXPECT_TRUE(a == b) << "Equal vanaf time_point constructor";
	
	b = clock::time_stamp::time_stamp();
	EXPECT_FALSE(a == b) << "Returns false voor verschillende timestamps";
}

TEST(IsNotEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp();
	int x = 1;
	for(int i= 0; i< 1000; ++i){
		x++;
	}
	clock::time_stamp b = clock::time_stamp::time_stamp();
	
	EXPECT_TRUE(a != b) << "2 default constructors ongelijk met forloop ertussen";
	
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp::time_stamp(t1);
	b = clock::time_stamp::time_stamp(t1);
	EXPECT_FALSE(a != b) << "2 gelijke timestamps geven false terug";
}

TEST(LessThanTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp();
	int x = 1;
	for(int i= 0; i< 1000; ++i){
		x++;
	}
	clock::time_stamp b = clock::time_stamp::time_stamp();
	EXPECT_TRUE(a < b) << "Returns true als a < b";
	EXPECT_FALSE(b < a) << "Returns false bij b < a";
	
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp::time_stamp(t1);
	b = clock::time_stamp::time_stamp(t1);
	
	EXPECT_FALSE(a < b) << "Returns false bij gelijke waarde";
}

TEST(LessOrEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp a = clock::time_stamp::time_stamp();
	int x = 1;
	for(int i= 0; i< 1000; ++i){
		x++;
	}
	clock::time_stamp b = clock::time_stamp::time_stamp();
	EXPECT_TRUE(a <= b) << "Returns true als a <= b";
	EXPECT_FALSE(b <= a) << "Returns false als b <= a";
	
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp::time_stamp(t1);
	b = clock::time_stamp::time_stamp(t1);
	
	EXPECT_TRUE(a <= b) << "Returns true bij gelijke waarde";
}

TEST(GreaterThanTimeStamp, ConstTimeStamp) {
	clock::time_stamp b = clock::time_stamp::time_stamp();
	int x = 1;
	for(int i= 0; i< 1000; ++i){
		x++;
	}
	clock::time_stamp a = clock::time_stamp::time_stamp();
	EXPECT_TRUE(a > b) << "Returns true als a > b";
	EXPECT_FALSE(b > a) << "Returns false als b > a";
	
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp::time_stamp(t1);
	b = clock::time_stamp::time_stamp(t1);
	
	EXPECT_FALSE(a > b) << "Returns false bij gelijke waarde";
}

TEST(GreaterOrEqualTimeStamp, ConstTimeStamp) {
	clock::time_stamp b = clock::time_stamp::time_stamp();
	int x = 1;
	for(int i= 0; i< 1000; ++i){
		x++;
	}
	clock::time_stamp a = clock::time_stamp::time_stamp();
	EXPECT_TRUE(a >= b) << "Returns true als a >= b";
	EXPECT_FALSE(b >= a) << "Returns false als b >= a";
	
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Vergelijking vanaf voorgedefineerde tijd
	a = clock::time_stamp::time_stamp(t1);
	b = clock::time_stamp::time_stamp(t1);
	
	EXPECT_TRUE(a >= b) << "Returns true bij gelijke waarde";
}

TEST(DifferenceTimeStamp, ConstTimeStamp) {
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now();
	int x = 1;
	for(int i= 0; i< 1000; ++i){
		x++;
	}
	std::chrono::high_resolution_clock::time_point t2 = high_resolution_clock::now();
	
	clock::time_stamp a = clock::time_stamp::time_stamp(t1);
	clock::time_stamp b = clock::time_stamp::time_stamp(t2);
	
	clock::duration d1 = clock::duration(std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1));
	clock::duration	d2 = t2 - t1;
	EXPECT_EQ(d1 , d2) << "De clock::duration van het verschil tussen de time_stamps is gelijk aan de duration cast";
	
	d2 = t1 - t2;
	EXPECT_NE(d1 , d2) << "De volgorde van aftrekken omdraaien om andere negatieve duration te krijgen";
	
	d1 = clock::duration(std::chrono::duration_cast<std::chrono::microseconds>(t1 - t2));
	EXPECT_EQ(d1 , d2) << "De clock::duration van het verschil tussen de time_stamps is gelijk aan de duration cast geinverteerd";
	
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