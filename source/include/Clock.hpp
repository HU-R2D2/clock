#ifndef HPP_Clock
#define HPP_Clock

#include <chrono>
#include <iostream>

class Clock {
	
	public:
	
		class Duration;
	
		class TimeStamp;
	
	public:
	
		//! \returns the current TimeStamp
		static TimeStamp get_current_time();
};

class Clock::Duration {

	private: /* Members */
		//! \m_Duration which is a long integer in microseconds
		std::chrono::duration<long, std::micro> m_duration; 

	public: /* Constructors */

		//! Default empty constructor
		Duration();

		//! Default initialization constructor
		/*!
		  \param arg is a Duration(long) in microseconds.
		*/
		Duration(const std::chrono::duration<long, std::micro>& arg);

		//! Default copy constructor
		Duration(const Duration& arg) = default;

	public: /*Operators*/
		
		//! The operator += 
		/*!
		  This operator adds m_Duration of current Clock::Duration with the m_Duration of the given parameter d.
		  \param d is a Clock::Duration
		  \return const Clock::Duration with the calculated value in m_Duration
		*/
		const Duration& operator+=(const Duration& d);
		
		//! The operator -=
		/*!
		  This operator subtracts m_Duration of current Clock::Duration with the m_Duration of the given parameter d.
		  \param d is a Clock::Duration
		  \return const Clock::Duration with the calculated value in m_Duration
		*/
		const Duration& operator-=(const Duration& d);
		
		//! The operator *=
		/*!
		  This operator multiplies m_Duration of current Clock::Duration with the m_Duration of the given parameter d.
		  \param rhs is an integer
		  \return const Clock::Duration with the calculated value in m_Duration
		*/		
		const Duration& operator*=(const int rhs);

		//! The operator /=
		/*!
		  This operator divides m_Duration of current Clock::Duration with the m_Duration of the given parameter d.
		  \param rhs is an integer
		  \return const Clock::Duration with the calculated value in m_Duration
		*/		
		const Duration& operator/=(const int rhs);
		
		//! The operator == (equal))
		/*!
		  This operator compares m_Duration of current Clock::Duration with the m_Duration of the given parameter rhs
		  \param rhs is a Clock::Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator==(const Duration& rhs) const;

		//! The operator != (not equal)
		/*!
		  This operator compares m_Duration of current Clock::Duration with the m_Duration of the given parameter rhs
		  \param rhs is a Clock::Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator!=(const Duration& rhs) const;
		
		//! The operator < (smaller)
		/*!
	  	  This operator checks if the current m_Duration of Clock::Duration is smaller than the given m_Duration of rhs
		  \param rhs is a Clock::Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator<(const Duration& rhs) const;
		
		//! The operator <= (smaller or equal)
		/*!
	  	  This operator checks if the current m_Duration of Clock::Duration is smaller or equal than the given m_Duration of rhs
		  \param rhs is a Clock::Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator<=(const Duration& rhs) const;
		
		//! The operator > (bigger)
		/*!
	  	  This operator checks if the current m_Duration is bigger than the ggiven m_Duration of rhs
		  \param rhs is a Clock::Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>(const Duration& rhs) const;
		
		//! The operator >= (bigger or equal)
		/*!
	  	  This operator checks if the current m_Duration of Clock::Duration is bigger or equal than the given m_Duration of rhs
		  \param rhs is a Clock::Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>=(const Duration& rhs) const;
		
		//! The operator + (plus)
		/*!
	  	  This operator checks if the current m_Duration of Clock::Duration is bigger or equal than the given m_Duration of rhs
		  \param rhs is a Clock::Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/
		Duration operator+(const Clock::Duration& rhs) const;
		
		//! The operator - (minus)
		/*!
		  This operator subtracts m_Duration of current Clock::Duration with the m_Duration of the given parameter rhs. 
		  \param rhs is a Clock::Duration 
		  \return Clock::Duration object of changed value
		*/		
		Duration operator-(const Clock::Duration& rhs) const;
		
		//! The operator * (multiply)
		/*!
		  This operator multiplies m_Duration of current Duration with the given parameter rhs. 
		  \param rhs is an integer 
		  \return Clock::Duration object of changed value
		*/		
		Duration operator*(const int rhs) const;
		
		//! The operator / (divide)
		/*!
		  This operator devides m_Duration of current Duration with the given parameter rhs. 
		  \param rhs is an integer 
		  \return Clock::Duration object of changed value
		*/		
		Duration operator/(const int rhs) const;

		//! The operator +=
		/*!
		  This operater takes the lhs TimeStamp and adds the Duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after adding Duration.
		  \param lhs is a Clock::TimeStamp
		  \param d is a Clock::Duration
		  \return lhs which is a Clock:TimeStamp
		*/
		friend Clock::TimeStamp& operator+=(Clock::TimeStamp& lhs, const Clock::Duration& d);
	
		//! The operator -=
		/*!
		  This operater takes the lhs TimeStamp and subtracts the Duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after extracting Duration.
		  \param lhs is a Clock::TimeStamp
		  \param d is a Clock::Duration
		  \return lhs which is a Clock:TimeStamp
		*/		
		friend Clock::TimeStamp& operator-=(Clock::TimeStamp& lhs, const Clock::Duration& d);
	
		//! The operator +(plus)
		/*!
		  This operater takes the lhs TimeStamp and adds the Duration d to it. Use this to show the time after extracting Duration.
		  \param lhs is a Clock::TimeStamp
		  \param rhs is a Clock::Duration
		  \return Clock::TimeStamp object with the changed value
		*/
		friend Clock::TimeStamp operator+(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
		
		//! The operator -(minus)
		/*!
		  This operater takes the lhs TimeStamp and subtracts the Duration d to it. Use this to show the time after extracting Duration.
		  \param lhs is a Clock::TimeStamp
		  \param rhs is a Clock::Duration
		  \return Clock::TimeStamp object with the changed value
		*/		
		friend Clock::TimeStamp operator-(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
		
		//! The operator -(minus)
		/*!
		  This operater takes the lhs TimeStamp and subtracts the Duration d to it. Use this to show the time after extracting Duration.
		  \param lhs is a Clock::Duration
		  \param rhs is a Clock::TimeStamp
		  \return Clock::TimeStamp object with the changed value
		*/		
		friend Clock::TimeStamp operator+(const Clock::Duration& lhs, const Clock::TimeStamp& rhs);
		
		//! The operator << for Clock::Duration
		/*!
		  This operator takes the rhs which is an Clock::Duration and shifts it into s which is a std::ostream
		  \param s is a std::ostream
		  \param rhs is a Clock::Duration
		  \return s which is a std::ostream
		*/
		friend std::ostream& operator<<(std::ostream &s, const Clock::Duration& rhs);
};
	
class Clock::TimeStamp {		

	public: /* Constructors */

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
		/*!
	  	  This operator checks if the current TimeStamp is equal with the given TimeStamp of rhs
		  \param rhs is a TimeStamp 
		  \return "true" if the comparison is true otherwise return "false"
		*/
		bool operator==(const Clock::TimeStamp& rhs) const;
		
		//! The operator !=
		/*!
	  	  This operator checks if the current TimeStamp is not equal with the given TimeStamp of rhs
		  \param rhs is a TimeStamp 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator!=(const Clock::TimeStamp& rhs) const;
		
		//! The operator < (smaller))
		/*!
	  	  This operator checks if the current TimeStamp is smaller than the given TimeStamp of rhs
		  \param rhs is a Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator<(const Clock::TimeStamp& rhs) const;
		
		//! The operator <= (smaller or equal)
		/*!
	  	  This operator checks if the current TimeStamp is smaller or equal than the given TimeStamp of rhs
		  \param rhs is a Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/			
		bool operator<=(const Clock::TimeStamp& rhs) const;
		
		//! The operator > (bigger)
		/*!
	  	  This operator checks if the current TimeStamp is bigger than the given TimeStamp of rhs
		  \param rhs is a Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>(const Clock::TimeStamp& rhs) const;
		
		//! The operator >= (bigger or equal)
		/*!
	  	  This operator checks if the current TimeStamp is bigger or equal than the given TimeStamp of rhs
		  \param rhs is a Duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>=(const Clock::TimeStamp& rhs) const;
		
		//! The operator -(minus)
		/*!
		  This operator subtracts the m_time_stamp of the current timestamp with the given m_time_stamp and returns a Duration
		  \param rhs is a TimeStamp 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		Clock::Duration operator-(const Clock::TimeStamp& rhs) const;

		//! The operator +=
		/*!
		  This operater takes the lhs TimeStamp and adds the Duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after adding Duration.
		  \param lhs is a Clock::TimeStamp
		  \param d is a Clock::Duration
		  \return lhs which is a Clock:TimeStamp
		*/
		friend Clock::TimeStamp& operator+=(Clock::TimeStamp& lhs, const Clock::Duration& d);
		//! The operator -=
		/*!
		  This operater takes the lhs TimeStamp and subtracts the Duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after extracting Duration.
		  \param lhs is a Clock::TimeStamp
		  \param d is a Clock::Duration
		  \return lhs which is a Clock:TimeStamp
		*/		
		friend Clock::TimeStamp& operator-=(Clock::TimeStamp& lhs, const Clock::Duration& d);
	
		//! The operator +(plus)
		/*!
		  This operater takes the lhs TimeStamp and adds the Duration d to it. Use this to show the time after extracting Duration.
		  \param lhs is a Clock::TimeStamp
		  \param rhs is a Clock::Duration
		  \return Clock::TimeStamp object with the changed value
		*/
		friend Clock::TimeStamp operator+(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
		
		//! The operator -(minus)
		/*!
		  This operater takes the lhs TimeStamp and subtracts the Duration d to it. Use this to show the time after extracting Duration.
		  \param lhs is a Clock::TimeStamp
		  \param rhs is a Clock::Duration
		  \return Clock::TimeStamp object with the changed value
		*/		
		friend Clock::TimeStamp operator-(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);
		
		//! The operator +(plus)
		/*!
		  This operater takes the lhs TimeStamp and subtracts the Duration d to it. Use this to show the time after extracting Duration.
		  \param lhs is a Clock::Duration
		  \param rhs is a Clock::TimeStamp
		  \return Clock::TimeStamp object with the changed value
		*/		
		friend Clock::TimeStamp operator+(const Clock::Duration& lhs, const Clock::TimeStamp& rhs);
		
		//! The operator << for Clock::TimeStamp
		/*!
		  This operator takes the rhs which is an Clock::TimeStamp and shifts it into s which is a std::ostream
		  \param s is a std::ostream
		  \param rhs is a Clock::TimeStamp
		  \return s which is a std::ostream
		*/		
		friend std::ostream& operator<<(std::ostream &s, const Clock::TimeStamp& rhs);
};

//! The operator +=
/*!
  This operater takes the lhs TimeStamp and adds the Duration d to it and stores the calculated value back to the lhs.
  Use this to show the time after adding Duration.
  \param lhs is a Clock::TimeStamp
  \param d is a Clock::Duration
  \return lhs which is a Clock:TimeStamp
*/
Clock::TimeStamp& operator+=(Clock::TimeStamp& lhs, const Clock::Duration& d);

//! The operator -=
/*!
  This operater takes the lhs TimeStamp and subtracts the Duration d to it and stores the calculated value back to the lhs.
  Use this to show the time after extracting Duration.
  \param lhs is a Clock::TimeStamp
  \param d is a Clock::Duration
  \return lhs which is a Clock:TimeStamp
*/
Clock::TimeStamp& operator-=(Clock::TimeStamp& lhs, const Clock::Duration& d);

//! The operator +
/*!
  This operater takes the lhs TimeStamp and adds the Duration d to it. Use this to show the time after adding Duration.
  \param lhs is a Clock::TimeStamp
  \param d is a Clock::Duration
  \return Clock::TimeStamp object with the changed value
*/
Clock::TimeStamp operator+(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);

//! The operator -
/*!
  This operater takes the lhs TimeStamp and subtracts the Duration d to it. Use this to show the time after extracting Duration.
  \param lhs is a Clock::Duration
  \param rhs is a Clock::TimeStamp
  \return Clock::TimeStamp object with the changed value
*/
Clock::TimeStamp operator-(const Clock::TimeStamp& lhs, const Clock::Duration& rhs);

//! The operator +(plus)
/*!
  This operater takes the lhs Duration and adds the rhs TimeStamp to it. Use this to show the time after adding Duration.
  \param lhs is a Clock::Duration
  \param rhs is a Clock::TimeStamp
  \return Clock::TimeStamp object with the changed value
*/
Clock::TimeStamp operator+(const Clock::Duration& lhs, const Clock::TimeStamp& rhs);

//! The operator << for Clock::Duration
/*!
  This operator takes the rhs which is an Clock::Duration and shifts it into s which is a std::ostream
  \param s is a std::ostream
  \param rhs is a Clock::Duration
  \return s which is a std::ostream
*/	
std::ostream & operator<<(std::ostream & s, const Clock::Duration & rhs);

//! The operator << for Clock::TimeStamp
/*!
  This operator takes the rhs which is an Clock::TimeStamp and shifts it into s which is a std::ostream
  \param s is a std::ostream
  \param rhs is a Clock::TimeStamp
  \return s which is a std::ostream
*/
std::ostream & operator<<(std::ostream & s, const Clock::TimeStamp &rhs);

#endif
