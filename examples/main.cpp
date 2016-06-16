#include "../source/include/Clock.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;
int main(int ac, char* av[]) {


/***********************          Duration               **********************/

    cout << "****************Duration**************** " << endl;
    //created  clock durations a and clock duration b
    Clock::Duration clock_a = Clock::Duration(std::chrono::duration<long,
         std::micro>(10));
    Clock::Duration clock_b = Clock::Duration(std::chrono::duration<long,
         std::micro>(5));


    //compare clock_a with 10 microseconds with clock_b with 5 microseconds
    bool comparistion_a =  clock_a == clock_b; // expected to return false
    bool comparistion_b =  clock_a >= clock_b; // expected to return true
    bool comparistion_c = clock_a <= clock_b; // expected to return false
    bool comparistion_d = clock_a != clock_b; // expected to return true

    cout << " expected to return false     returns : "<< comparistion_a << endl;
    cout << " expected to return true      returns : "<< comparistion_b << endl;
    cout << " expected to return false     returns : "<< comparistion_c << endl;
    cout << " expected to return true      returns : "<< comparistion_d << endl;



    //calculations on clock_a with 10 microseconds
    //and clock_b with 5 microseconds
    Clock::Duration calculation_a = clock_a +=
        clock_b; // 10 + 5 = 15 microseconds
    Clock::Duration calculation_b = clock_a *=
        2; // 15 * 2 = 30 microseconds
    Clock::Duration calculation_c = clock_a /= 2; // 30 / 2 = 15 microseconds
    Clock::Duration calculation_d = clock_a -=
        clock_b; // 15 - 5 = 10 microseconds

    cout << " expected to return 15 microseconds     returns : "<<
        calculation_a << endl;
    cout << " expected to return 30 microseconds     returns : "<<
        calculation_b << endl;
    cout << " expected to return 15 microseconds     returns : "<<
        calculation_c << endl;
    cout << " expected to return 10 microseconds     returns : "<<
        calculation_d << endl;




/***********************          TimeStamp             ***********************/
    cout << "****************Timestamp**************** " << endl;
    //create timestamp a and timestamp b
    Clock::TimeStamp timestamp_a = Clock::TimeStamp();
    Clock::TimeStamp timestamp_b = Clock::TimeStamp();

    //compare two timestamps created at the same time
    bool timestamp_comparistion_a =
        timestamp_a == timestamp_b; //expected to return true
    cout << " expected to return true      returns : "
        << timestamp_comparistion_a << endl;


    //create timestamp c then sleep for 1 microsecond then create timestamp d
    Clock::TimeStamp timestamp_c = Clock::TimeStamp();
    sleep(1);
    Clock::TimeStamp timestamp_d = Clock::TimeStamp();


    //compare two timestamps created with a delay of 1 microsecond of each other
    bool timestamp_comparistion_b =
        timestamp_c == timestamp_d; //expected to return false
    cout << " expected to return false     returns : "<<
        timestamp_comparistion_b << endl;


    std::chrono::high_resolution_clock::time_point t1 =
        std::chrono::high_resolution_clock::now();
    Clock::TimeStamp timestamp_e  = Clock::TimeStamp(t1);
    Clock::TimeStamp timestamp_f  = Clock::TimeStamp(t1);

    bool timestamp_comparistion_c =
        timestamp_e == timestamp_f; // expected to return true
    cout << " expected to return true      returns : "<<
        timestamp_comparistion_c << endl;

    // create timestamp g wait 5 microseconds then creat timestamp g
    Clock::TimeStamp timestamp_g = Clock::TimeStamp();
    sleep(5);
    Clock::TimeStamp timestamp_h = Clock::TimeStamp();

    //calculate the duration between two timestamps
    Clock::Duration difference = timestamp_h  -  timestamp_g;
    cout << " difference in time between timestamp h and g: "<< difference << endl;




}
