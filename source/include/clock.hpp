#ifndef HPP_CLOCK
#define HPP_CLOCK

#include <chrono>
#include <iostream>

class clock {
	
	public:
	
		class duration;
	
		class time_stamp;
	
	public:
	
		//! \returns the current time_stamp
		static time_stamp get_current_time();
};

class clock::duration {

	private: /* Members */
		//! \m_duration which is a long integer in microseconds
		std::chrono::duration<long, std::micro> m_duration; 

	public: /* Constructors */

		//! Default empty constructor
		duration();

		//! Default initialization constructor
		/*!
		  \param arg is a duration(long) in microseconds.
		*/
		duration(const std::chrono::duration<long, std::micro>& arg);

		//! Default copy constructor
		duration(const duration& arg) = default;

	public: /*Opearators*/
		
		//! The operator += 
		/*!
		  This operator adds m_duration of current clock::duration with the m_duration of the given parameter d.
		  \param d is a clock::duration
		  \return const clock::duration with the calculated value in m_duration
		*/
		const duration& operator+=(const duration& d);
		
		//! The operator -=
		/*!
		  This operator extracts m_duration of current clock::duration with the m_duration of the given parameter d.
		  \param d is a clock::duration
		  \return const clock::duration with the calculated value in m_duration
		*/
		const duration& operator-=(const duration& d);
		
		//! The operator *=
		/*!
		  This operator multiplies m_duration of current clock::duration with the m_duration of the given parameter d.
		  \param rhs is an integer
		  \return const clock::duration with the calculated value in m_duration
		*/		
		const duration& operator*=(const int rhs);

		//! The operator /=
		/*!
		  This operator divides m_duration of current clock::duration with the m_duration of the given parameter d.
		  \param rhs is an integer
		  \return const clock::duration with the calculated value in m_duration
		*/		
		const duration& operator/=(const int rhs);
		
		//! The operator == (equal))
		/*!
		  This operator compares m_duration of current clock::duration with the m_duration of the given parameter rhs
		  \param rhs is a clock::duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator==(const duration& rhs) const;

		//! The operator != (not equal)
		/*!
		  This operator compares m_duration of current clock::duration with the m_duration of the given parameter rhs
		  \param rhs is a clock::duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator!=(const duration& rhs) const;
		
		//! The operator < (smaller)
		/*!
	  	  This operator checks if the current m_duration of clock::duration is smaller than the given m_duration of rhs
		  \param rhs is a clock::duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator<(const duration& rhs) const;
		
		//! The operator <= (smaller or equal)
		/*!
	  	  This operator checks if the current m_duration of clock::duration is smaller or equal than the given m_duration of rhs
		  \param rhs is a clock::duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator<=(const duration& rhs) const;
		
		//! The operator > (bigger)
		/*!
	  	  This operator checks if the current m_duration is bigger than the ggiven m_duration of rhs
		  \param rhs is a clock::duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>(const duration& rhs) const;
		
		//! The operator >= (bigger or equal)
		/*!
	  	  This operator checks if the current m_duration of clock::duration is bigger or equal than the given m_duration of rhs
		  \param rhs is a clock::duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>=(const duration& rhs) const;
		
		//! The operator + (plus)
		/*!
	  	  This operator checks if the current m_duration of clock::duration is bigger or equal than the given m_duration of rhs
		  \param rhs is a clock::duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/
		duration operator+(const clock::duration& rhs) const;
		
		//! The operator - (minus)
		/*!
		  This operator extracts m_duration of current clock::duration with the m_duration of the given parameter rhs. 
		  \param rhs is a clock::duration 
		  \return clock::duration object of changed value
		*/		
		duration operator-(const clock::duration& rhs) const;
		
		//! The operator * (multiply)
		/*!
		  This operator multiplies m_duration of current duration with the given parameter rhs. 
		  \param rhs is an integer 
		  \return clock::duration object of changed value
		*/		
		duration operator*(const int rhs) const;
		
		//! The operator / (divide)
		/*!
		  This operator devides m_duration of current duration with the given parameter rhs. 
		  \param rhs is an integer 
		  \return clock::duration object of changed value
		*/		
		duration operator/(const int rhs) const;

		//! The operator +=
		/*!
		  This operater takes the lhs time_stamp and adds the duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after adding duration.
		  \param lhs is a clock::time_stamp
		  \param d is a clock::duration
		  \return lhs which is a clock:time_stamp
		*/
		friend clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);
	
		//! The operator -=
		/*!
		  This operater takes the lhs time_stamp and extracts the duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after extracting duration.
		  \param lhs is a clock::time_stamp
		  \param d is a clock::duration
		  \return lhs which is a clock:time_stamp
		*/		
		friend clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);
	
		//! The operator +(plus)
		/*!
		  This operater takes the lhs time_stamp and adds the duration d to it. Use this to show the time after extracting duration.
		  \param lhs is a clock::time_stamp
		  \param rhs is a clock::duration
		  \return clock::time_stamp object with the changed value
		*/
		friend clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);
		
		//! The operator -(minus)
		/*!
		  This operater takes the lhs time_stamp and extracts the duration d to it. Use this to show the time after extracting duration.
		  \param lhs is a clock::time_stamp
		  \param rhs is a clock::duration
		  \return clock::time_stamp object with the changed value
		*/		
		friend clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);
		
		//! The operator -(minus)
		/*!
		  This operater takes the lhs time_stamp and extracts the duration d to it. Use this to show the time after extracting duration.
		  \param lhs is a clock::duration
		  \param rhs is a clock::time_stamp
		  \return clock::time_stamp object with the changed value
		*/		
		friend clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);
		
		//! The operator << for clock::duration
		/*!
		  This operator takes the rhs which is an clock::duration and shifts it into s which is a std::ostream
		  \param s is a std::ostream
		  \param rhs is a clock::duration
		  \return s which is a std::ostream
		*/
		friend std::ostream& operator<<(std::ostream &s, const clock::duration& rhs);
};
	
class clock::time_stamp {
		
	private: /* Members */
		
		//! \m_time_stamp is a high_resolution_clock which represents the clock with the smallest tick period.
		std::chrono::time_point<std::chrono::high_resolution_clock> m_time_stamp;

	public: /* Constructors */
		
		//! Default empty constructor
		time_stamp();
		
		//! Initialization constructor
		time_stamp(const std::chrono::time_point<std::chrono::high_resolution_clock>& arg);
		
		//! Default copy constructor
		time_stamp(const time_stamp& arg) = default;
		
	public: /*Operators*/
	
		//! The operator ==
		/*!
	  	  This operator checks if the current time_stamp is equal with the given time_stamp of rhs
		  \param rhs is a time_stamp 
		  \return "true" if the comparison is true otherwise return "false"
		*/
		bool operator==(const clock::time_stamp& rhs) const;
		
		//! The operator !=
		/*!
	  	  This operator checks if the current time_stamp is not equal with the given time_stamp of rhs
		  \param rhs is a time_stamp 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator!=(const clock::time_stamp& rhs) const;
		
		//! The operator < (smaller))
		/*!
	  	  This operator checks if the current time_stamp is smaller than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator<(const clock::time_stamp& rhs) const;
		
		//! The operator <= (smaller or equal)
		/*!
	  	  This operator checks if the current time_stamp is smaller or equal than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/			
		bool operator<=(const clock::time_stamp& rhs) const;
		
		//! The operator > (bigger)
		/*!
	  	  This operator checks if the current time_stamp is bigger than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>(const clock::time_stamp& rhs) const;
		
		//! The operator >= (bigger or equal)
		/*!
	  	  This operator checks if the current time_stamp is bigger or equal than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		bool operator>=(const clock::time_stamp& rhs) const;
		
		//! The operator -(minus)
		/*!
		  This operator extracts the m_time_stamp of the current timestamp with the given m_time_stamp and returns a duration
		  \param rhs is a time_stamp 
		  \return "true" if the comparison is true otherwise return "false"
		*/		
		clock::duration operator-(const clock::time_stamp& rhs) const;

		//! The operator +=
		/*!
		  This operater takes the lhs time_stamp and adds the duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after adding duration.
		  \param lhs is a clock::time_stamp
		  \param d is a clock::duration
		  \return lhs which is a clock:time_stamp
		*/
		friend clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);
		//! The operator -=
		/*!
		  This operater takes the lhs time_stamp and extracts the duration d to it and stores the calculated value back to the lhs.
		  Use this to show the time after extracting duration.
		  \param lhs is a clock::time_stamp
		  \param d is a clock::duration
		  \return lhs which is a clock:time_stamp
		*/		
		friend clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);
	
		//! The operator +(plus)
		/*!
		  This operater takes the lhs time_stamp and adds the duration d to it. Use this to show the time after extracting duration.
		  \param lhs is a clock::time_stamp
		  \param rhs is a clock::duration
		  \return clock::time_stamp object with the changed value
		*/
		friend clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);
		
		//! The operator -(minus)
		/*!
		  This operater takes the lhs time_stamp and extracts the duration d to it. Use this to show the time after extracting duration.
		  \param lhs is a clock::time_stamp
		  \param rhs is a clock::duration
		  \return clock::time_stamp object with the changed value
		*/		
		friend clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);
		
		//! The operator -(minus)
		/*!
		  This operater takes the lhs time_stamp and extracts the duration d to it. Use this to show the time after extracting duration.
		  \param lhs is a clock::duration
		  \param rhs is a clock::time_stamp
		  \return clock::time_stamp object with the changed value
		*/		
		friend clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);
		
		//! The operator << for clock::time_stamp
		/*!
		  This operator takes the rhs which is an clock::time_stamp and shifts it into s which is a std::ostream
		  \param s is a std::ostream
		  \param rhs is a clock::time_stamp
		  \return s which is a std::ostream
		*/		
		friend std::ostream& operator<<(std::ostream &s, const clock::time_stamp& rhs);
};

//! The operator +=
/*!
  This operater takes the lhs time_stamp and adds the duration d to it and stores the calculated value back to the lhs.
  Use this to show the time after adding duration.
  \param lhs is a clock::time_stamp
  \param d is a clock::duration
  \return lhs which is a clock:time_stamp
*/
clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);

//! The operator -=
/*!
  This operater takes the lhs time_stamp and extracts the duration d to it and stores the calculated value back to the lhs.
  Use this to show the time after extracting duration.
  \param lhs is a clock::time_stamp
  \param d is a clock::duration
  \return lhs which is a clock:time_stamp
*/
clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);

//! The operator +
/*!
  This operater takes the lhs time_stamp and adds the duration d to it. Use this to show the time after adding duration.
  \param lhs is a clock::time_stamp
  \param d is a clock::duration
  \return clock::time_stamp object with the changed value
*/
clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);

//! The operator -
/*!
  This operater takes the lhs time_stamp and extracts the duration d to it. Use this to show the time after extracting duration.
  \param lhs is a clock::duration
  \param rhs is a clock::time_stamp
  \return clock::time_stamp object with the changed value
*/
clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);

//! The operator +(plus)
/*!
  This operater takes the lhs duration and adds the rhs time_stamp to it. Use this to show the time after adding duration.
  \param lhs is a clock::duration
  \param rhs is a clock::time_stamp
  \return clock::time_stamp object with the changed value
*/
clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);

//! The operator << for clock::duration
/*!
  This operator takes the rhs which is an clock::duration and shifts it into s which is a std::ostream
  \param s is a std::ostream
  \param rhs is a clock::duration
  \return s which is a std::ostream
*/	
std::ostream & operator<<(std::ostream & s, const clock::duration & rhs);

//! The operator << for clock::time_stamp
/*!
  This operator takes the rhs which is an clock::time_stamp and shifts it into s which is a std::ostream
  \param s is a std::ostream
  \param rhs is a clock::time_stamp
  \return s which is a std::ostream
*/
std::ostream & operator<<(std::ostream & s, const clock::time_stamp &rhs);

#endif
