#ifndef HPP_CLOCK
#define HPP_CLOCK

#include <chrono>
#include <iostream>

class clock {
	
	public:
	
		class duration;
	
		class time_stamp;
	
	public:
	
		//! \returns a time_stamp from now
	
		static time_stamp get_current_time();
};

class clock::duration {

	private: /* Members */

		std::chrono::duration<long, std::micro> m_duration; 

	public: /* Constructors */

		//! Default empty constructor

		duration();

		//! Default initialization constructor
		/*!
		  \param arg duration is a chrono argument which uses the datatype long in microseconds
		  \return the duration of arg
		*/
		duration(const std::chrono::duration<long, std::micro>& arg);

		//! Default copy constructor

		duration(const duration& arg) = default;

	public: /*Opearators*/
		
		//! The operator +=
		/*!
		  This operator adds m_duration of current duration with the given parameter d and returns the calculated value. 
		  \param d is a duration in microseconds which is a long(integer)
		  \return the calculated value
		*/
		const duration& operator+=(const duration& d);
		
		//! The operator -=
		/*!
		  This operator extracts m_duration of current duration with the given parameter d and returns the calculated value. 
		  \param d is a duration in microseconds which is a long(integer)
		  \return the calculated value
		*/
		const duration& operator-=(const duration& d);
		
		//! The operator *=
		/*!
		  This operator multiplies m_duration of current duration with the given parameter d and returns the calculated value. 
		  \param rhs is a integer
		  \return the calculated value
		*/		
		const duration& operator*=(const int rhs);

		//! The operator /=
		/*!
		  This operator devides m_duration of current duration with the given parameter d and returns the calculated value. 
		  \param rhs is a integer
		  \return the calculated value
		*/		
		const duration& operator/=(const int rhs);
		
		
		//! The operator == which returns a boolean
		/*!
		  This operator compares m_duration of current duration with the given parameter rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator==(const duration& rhs) const;

		//! The operator != which returns a boolean
		/*!
		  This operator compares m_duration of current duration with the given parameter rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator!=(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
	  	  This operator checks if the current m_duration is smaller than the given rhs m_duration
		  This operator compares m_duration wether the current m_duration is smaller than the given m_duration of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator<(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
	  	  This operator checks if the current m_duration is smaller or equal than the given m_duration of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator<=(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
	  	  This operator checks if the current m_duration is bigger than the ggiven m_duration of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator>(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
	  	  This operator checks if the current m_duration is bigger or equal than the given m_duration of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator>=(const duration& rhs) const;
		
		//! The operator +
		/*!
		  This operator adds m_duration of current duration with the given parameter rhs. 
		  \param rhs is a duration 
		  \return returns duration which contains the calculated m_duration
		*/
		duration operator+(const clock::duration& rhs) const;
		
		//! The operator -
		/*!
		  This operator extracts m_duration of current duration with the given parameter rhs. 
		  \param rhs is a duration 
		  \return returns duration which contains the calculated m_duration
		*/		
		duration operator-(const clock::duration& rhs) const;
		
		//! The operator -
		/*!
		  This operator multiplies m_duration of current duration with the given parameter rhs. 
		  \param rhs is an integer 
		  \return returns duration which contains the calculated m_duration
		*/		
		duration operator*(const int rhs) const;
		
		//! The operator /
		/*!
		  This operator devides m_duration of current duration with the given parameter rhs. 
		  \param rhs is an integer 
		  \return returns duration which contains the calculated m_duration
		*/		
		duration operator/(const int rhs) const;

		friend clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);
		friend clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);
		friend clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);
		friend clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);
		friend clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);
		friend std::ostream& operator<<(std::ostream &s, const clock::duration& rhs);
};
	
class clock::time_stamp {
		
	private: /* Members */
		
		std::chrono::time_point<std::chrono::high_resolution_clock> m_time_stamp;

	public: /* Constructors */
		
		//! Default empty constructor
		
		time_stamp();
		
		//! Initialization constructor
		
		time_stamp(const std::chrono::time_point<std::chrono::high_resolution_clock>& arg);
		
		//! Default copy constructor
		
		time_stamp(const time_stamp& arg) = default;
		
	public: /*Operators*/
	
		//! The operator == which returns a boolean 
		/*!
	  	  This operator checks if the current time_stamp is equal with the given time_stamp of rhs
		  \param rhs is a time_stamp 
		  \return returns 1 if the comparison is true otherwise 0
		*/
		bool operator==(const clock::time_stamp& rhs) const;
		
		//! The operator != which returns a boolean 
		/*!
	  	  This operator checks if the current time_stamp is not equal with the given time_stamp of rhs
		  \param rhs is a time_stamp 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator!=(const clock::time_stamp& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
	  	  This operator checks if the current time_stamp is smaller than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator<(const clock::time_stamp& rhs) const;
		
		//! The operator <= which returns a boolean
		/*!
	  	  This operator checks if the current time_stamp is smaller or equal than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/			
		bool operator<=(const clock::time_stamp& rhs) const;
		
		//! The operator <= which returns a boolean
		/*!
	  	  This operator checks if the current time_stamp is bigger than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator>(const clock::time_stamp& rhs) const;
		
		//! The operator <= which returns a boolean
		/*!
	  	  This operator checks if the current time_stamp is bigger or equal than the given time_stamp of rhs
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator>=(const clock::time_stamp& rhs) const;
		
		//! The operator - which returns duration
		/*!
		  This operator extracts the m_time_stamp of the current timestamp with the given m_time_stamp and returns a duration
		  \param rhs is a time_stamp 
		  \return returns the calculated time as duration
		*/		
		clock::duration operator-(const clock::time_stamp& rhs) const;

		friend clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);
		friend clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);
		friend clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);
		friend clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);
		friend clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);
		friend std::ostream& operator<<(std::ostream &s, const clock::time_stamp& rhs);
};

//! The operator +=
/*!
  This operater takes the lhs time_stamp and adds the duration d to it and stores the calculated value back to the lhs.
  Use this to show the time after adding duration.
  \param lhs is a time_stamp
  \param d is a duration
  \return the time after adding the given duration to it
*/
clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);

//! The operator -=
/*!
  This operater takes the lhs time_stamp and extracts the duration d to it and stores the calculated value back to the lhs.
  Use this to show the time after extracting duration.
  \param lhs is a time_stamp
  \param d is a duration
  \return the time after extracting the given duration to it
*/
clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);

//! The operator +
/*!
  This operater takes the lhs time_stamp and adds the duration d to it.
  Use this to show the time after adding duration.
  \param lhs is a time_stamp
  \param d is a duration
  \return the time after adding the given duration to it
*/
clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);

//! The operator -
/*!
  This operater takes the lhs time_stamp and extracts the duration d to it.
  Use this to show the time after extracting duration.
  \param lhs is a duration
  \param rhs is a time_stamp
  \return the time after extracting the given duration to it
*/
clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);

//! The operator +
/*!
  This operater takes the lhs duration and adds the rhs time_stamp to it.
  Use this to show the time after adding duration.
  \param lhs is a duration
  \param rhs is a time_stamp
  \return the time after adding the given duration to it
*/
clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);

	
std::ostream & operator<<(std::ostream & s, const clock::duration & rhs);
std::ostream & operator<<(std::ostream & s, const clock::time_stamp &rhs);

#endif
