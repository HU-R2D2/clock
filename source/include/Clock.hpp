#ifndef HPP_Clock
#define HPP_Clock

#include <chrono>
#include <iostream>

/// The main Clock object, which holds Clock::Duration and Clock::TimeStamp
/// The Clock class is the main class which will be used to refer to Clock::Duration and Clock::TimeStamp.
/// \author Thijs Hendrickx, Zehna van den Berg, Waila Woe, Aydin Biber
/// \version 1.0
/// \date 31-3-2016
class Clock {
	
	public:
	
		class Duration;
	
		class TimeStamp;
	
	public:
	
		//! \returns the current TimeStamp
		static TimeStamp get_current_time();
};

class Clock::Duration {

	private: // Members
		//! \m_Duration which is a long integer in microseconds
		std::chrono::duration<long, std::micro> m_duration; 

	public: // Constructors

		//! Default empty constructor
		Duration();

		//! Default initialization constructor
		//! \param arg is a Duration(long) in microseconds.
		Duration(const std::chrono::duration<long, std::micro>& arg);

		//! Default copy constructor
		Duration(const Duration& arg) = default;

	public: //Operators
		
		//! The operator += 
		//!
		//! Used to add and assign a Duration to another Duration.
		//! \param d is a Clock::Duration
		//! \return const Clock::Duration with the calculated value in m_Duration
		const Duration& operator+=(const Duration& d);
		
		//! The operator -=
		//!
		//! Used to substract and assign a Duration with another Duration.
		//! \param d is a Clock::Duration
		//! \return const Clock::Duration with the calculated value in m_Duration
		const Duration& operator-=(const Duration& d);
		
		//! The operator *=
		//!
		//! Used to multiply and assign a Duration with another Duration.
		//! \param rhs is an integer
		//! \return const Clock::Duration with the calculated value in m_Duration
		const Duration& operator*=(const int rhs);

		//! The operator /=
		//!
		//! Used to divides and assign a Duration with another Duration.
		//! \param rhs is an integer
		//! \return const Clock::Duration with the calculated value in m_Duration
		const Duration& operator/=(const int rhs);
		
		//! The operator == (equal))
		//!
		//! Used to test if Duration is equal to another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return "true" if the comparison is true otherwise return "false"		
		bool operator==(const Duration& rhs) const;

		//! The operator != (not equal)
		//!
		//! Used to test if Duration is not equal to another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return "true" if the comparison is true otherwise return "false"		
		bool operator!=(const Duration& rhs) const;
		
		//! The operator < (smaller)
		//!
	  	//! Used to test if Duration is lesser than another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return "true" if the comparison is true otherwise return "false"		
		bool operator<(const Duration& rhs) const;
		
		//! The operator <= (smaller or equal)
		//!
		//! Used to test if Duration is lesser than or equal to another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return "true" if the comparison is true otherwise return "false"		
		bool operator<=(const Duration& rhs) const;
		
		//! The operator > (bigger)
		//!
		//! Used to test if Duration is greater than another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return "true" if the comparison is true otherwise return "false"	
		bool operator>(const Duration& rhs) const;
		
		//! The operator >= (bigger or equal)
		//!
		//! Used to test if Duration is greater than or equal to another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return "true" if the comparison is true otherwise return "false"		
		bool operator>=(const Duration& rhs) const;
		
		//! The operator + (plus)
		//!
		//! Used to add a Duration to another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return "true" if the comparison is true otherwise return "false"
		Duration operator+(const Clock::Duration& rhs) const;
		
		//! The operator - (minus)
		//!
		//! Used to substract a Duration with another Duration.
		//! \param rhs is a Clock::Duration 
		//! \return Clock::Duration object of changed value		
		Duration operator-(const Clock::Duration& rhs) const;
		
		//! The operator * (multiply)
		//!
		//! Used to multiply a Duration with another Duration.
		//! \param rhs is an integer 
		//! \return Clock::Duration object of changed value		
		Duration operator*(const int rhs) const;
		
		//! The operator / (divide)
		//!
		//! Used to divide a Duration with another Duration.
		//! \param rhs is an integer 
		//! \return Clock::Duration object of changed value		
		Duration operator/(const int rhs) const;

		friend Clock::TimeStamp& operator+=(Clock::TimeStamp& lhs, const Clock::Duration& d);
	
		friend Clock::TimeStamp& operator-=(Clock::TimeStamp& lhs, const Clock::Duration& d);
	
		friend Clock::TimeStamp operator+(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
		
		friend Clock::TimeStamp operator-(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
			
		friend Clock::TimeStamp operator+(const Clock::Duration& lhs, const Clock::TimeStamp& rhs);
		
		friend std::ostream& operator<<(std::ostream &s, const Clock::Duration& rhs);
};
	
class Clock::TimeStamp {		

	public: // Constructors

		//! \m_time_stamp is a high_resolution_clock which represents the Clock with the smallest tick period.
		std::chrono::time_point<std::chrono::high_resolution_clock> m_time_stamp;
		
		//! Default empty constructor
		TimeStamp();
		
		//! Initialization constructor
		TimeStamp(const std::chrono::time_point<std::chrono::high_resolution_clock>& arg);
		
		//! Default copy constructor
		TimeStamp(const TimeStamp& arg) = default;

	public: /*Operators*/
	
		//! The operator ==
		//!
		//! Used to test if TimeStamp is equal to another TimeStamp.
		//! \param rhs is a TimeStamp 
		//! \return "true" if the comparison is true otherwise return "false"
		bool operator==(const Clock::TimeStamp& rhs) const;
		
		//! The operator !=
		//!
		//! Used to test if TimeStamp is not equal to another TimeStamp.
		//! \param rhs is a TimeStamp 
		//! \return "true" if the comparison is true otherwise return "false"		
		bool operator!=(const Clock::TimeStamp& rhs) const;
		
		//! The operator < (smaller)
		//!
		//! Used to test if TimeStamp is lesser than another TimeStamp.
		//! \param rhs is a Duration 
		//! \return "true" if the comparison is true otherwise return "false"	
		bool operator<(const Clock::TimeStamp& rhs) const;
		
		//! The operator <= (smaller or equal)
		//!
		//! Used to test if TimeStamp is lesser than or equal to another TimeStamp.
		//! \param rhs is a Duration 
		//! \return "true" if the comparison is true otherwise return "false"		
		bool operator<=(const Clock::TimeStamp& rhs) const;
		
		//! The operator > (bigger)
		//!
		//! Used to test if TimeStamp is greater than another TimeStamp.
		//! \param rhs is a Duration 
		//! \return "true" if the comparison is true otherwise return "false"	
		bool operator>(const Clock::TimeStamp& rhs) const;
		
		//! The operator >= (bigger or equal)
		//!
		//! Used to test if TimeStamp is greater than or equal to another TimeStamp.
		//! \param rhs is a Duration 
		//! \return "true" if the comparison is true otherwise return "false"	
		bool operator>=(const Clock::TimeStamp& rhs) const;
		
		//! The operator -(minus)
		//!
		//! Used to substract a TimeStamp with another TimeStamp to get a Duration value between them.
		//! \param rhs is a TimeStamp 
		//! \return "true" if the comparison is true otherwise return "false"	
		Clock::Duration operator-(const Clock::TimeStamp& rhs) const;

		friend Clock::TimeStamp& operator+=(Clock::TimeStamp& lhs, const Clock::Duration& d);

		friend Clock::TimeStamp& operator-=(Clock::TimeStamp& lhs, const Clock::Duration& d);
	
		friend Clock::TimeStamp operator+(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
			
		friend Clock::TimeStamp operator-(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
		
		friend Clock::TimeStamp operator+(const Clock::Duration& lhs, const Clock::TimeStamp& rhs);
		
		friend std::ostream& operator<<(std::ostream &s, const Clock::TimeStamp& rhs);
};

//! The operator +=
//!
//! Used to add and assign a Duration to a TimeStamp
//! \param lhs is a Clock::TimeStamp
//! \param d is a Clock::Duration
//! \return lhs which is a Clock:TimeStamp
Clock::TimeStamp& operator+=(Clock::TimeStamp& lhs, const Clock::Duration& d);

//! The operator -=
//!
//! Used to substract and assign a TimeStamp with a Duration
//! \param lhs is a Clock::TimeStamp
//! \param d is a Clock::Duration
//! \return lhs which is a Clock:TimeStamp
Clock::TimeStamp& operator-=(Clock::TimeStamp& lhs, const Clock::Duration& d);

//! The operator +
//!
//! Used to add a Duration to a TimeStamp
//! \param lhs is a Clock::TimeStamp
//! \param d is a Clock::Duration
//! \return Clock::TimeStamp object with the changed value
Clock::TimeStamp operator+(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);

//! The operator -
//!
//! Used to substract a TimeStamp with a Duration
//! \param lhs is a Clock::Duration
//! \param rhs is a Clock::TimeStamp
//! \return Clock::TimeStamp object with the changed value
Clock::TimeStamp operator-(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);

//! The operator +(plus)
//!
//! Used to add a Duration to a TimeStamp
//! \param lhs is a Clock::Duration
//! \param rhs is a Clock::TimeStamp
//! \return Clock::TimeStamp object with the changed value
Clock::TimeStamp operator+(const Clock::Duration& lhs, const Clock::TimeStamp& rhs);

//! The operator << for Clock::Duration
//!
//! Used to shift a Duration in an ostream
//! \param s is a std::ostream
//! \param rhs is a Clock::Duration
//! \return s which is a std::ostream
std::ostream & operator<<(std::ostream & s, const Clock::Duration & rhs);

//! The operator << for Clock::TimeStamp
//!
//! Used to shift a TimeStamp in an ostream
//! \param s is a std::ostream
//! \param rhs is a Clock::TimeStamp
//! \return s which is a std::ostream
std::ostream & operator<<(std::ostream & s, const Clock::TimeStamp &rhs);

#endif
