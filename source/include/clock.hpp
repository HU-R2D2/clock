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
		  This operator adds the current m_duration with the given parameter d.
		  \param d is a duration in microseconds which is a long(integer)
		  \return the calculated value
		*/
		const duration& operator+=(const duration& d);
		
		//! The operator -=
		/*!
		  This operator extracts the current m_duration with the given parameter d.
		  \param d is a duration in microseconds which is a long(integer)
		  \return the calculated value
		*/
		const duration& operator-=(const duration& d);
		
		//! The operator *=
		/*!
		  This operator multiplies the current m_duration with the given parameter d.
		  \param rhs is a number which is an integer
		  \return the calculated value
		*/		
		const duration& operator*=(const int rhs);

		//! The operator /=
		/*!
		  This operator devides the current m_duration with the given parameter d.
		  \param rhs is a number which is an integer
		  \return the calculated value
		*/		
		const duration& operator/=(const int rhs);
		
		//! The operator == which returns a boolean
		/*!
		  This operator checks wether the current m_duration is equal with the given parameter
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator==(const duration& rhs) const;

		//! The operator != which returns a boolean
		/*!
		  This operator checks wether the current m_duration is not equal with the given parameter
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator!=(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
		  This operator compares wether the current m_duration is smaller than the given parameter
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator<(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
		  This operator compares wether the current m_duration is smaller or equal than the given parameter
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator<=(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
		  This operator compares wether the current m_duration is bigger than the given parameter
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator>(const duration& rhs) const;
		
		//! The operator < which returns a boolean
		/*!
		  This operator compares wether the current m_duration is bigger or equal than the given parameter
		  \param rhs is a duration 
		  \return returns 1 if the comparison is true otherwise 0
		*/		
		bool operator>=(const duration& rhs) const;
		
		//! The operator +
		/*!
		  This operator adds m_duration of current duration with the given duration rhs. 
		  \param rhs is a duration 
		  \return returns duration which contains the calculated m_duration
		*/
		duration operator+(const clock::duration& rhs) const;
		
		//! The operator -
		/*!
		  This operator extracts m_duration of current duration with the given duration rhs. 
		  \param rhs is a duration 
		  \return returns duration which contains the calculated m_duration
		*/		
		duration operator-(const clock::duration& rhs) const;
		
		//! The operator -
		/*!
		  This operator multiplies m_duration of current duration with the given duration rhs. 
		  \param rhs is an integer 
		  \return returns duration which contains the calculated m_duration
		*/		
		duration operator*(const int rhs) const;
		
		//! The operator /
		/*!
		  This operator devides m_duration of current duration with the given duration rhs. 
		  \param rhs is an integer 
		  \return returns duration which contains the calculated m_duration
		*/		
		duration operator/(const int rhs) const;

		//! The operator -=
		/*!
		  This operator extracts the current m_duration with the given parameter d.
		  \param d is a duration in microseconds which is a long(integer)
		  \return the calculated value
		*/
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
		bool operator==(const clock::time_stamp& rhs) const;
		bool operator!=(const clock::time_stamp& rhs) const;
		bool operator<(const clock::time_stamp& rhs) const;
		bool operator<=(const clock::time_stamp& rhs) const;
		bool operator>(const clock::time_stamp& rhs) const;
		bool operator>=(const clock::time_stamp& rhs) const;
		
		clock::duration operator-(const clock::time_stamp& rhs) const;

		friend clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);
		friend clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);
		friend clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);
		friend clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);
		friend clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);
		friend std::ostream& operator<<(std::ostream &s, const clock::time_stamp& rhs);
};
	
clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d);
clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d);
clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs);
clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs);
clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs);
	
std::ostream & operator<<(std::ostream & s, const clock::duration & rhs);
std::ostream & operator<<(std::ostream & s, const clock::time_stamp &rhs);

#endif
