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

		duration(const std::chrono::duration<long, std::micro>& arg);

		//! Default copy constructor

		duration(const duration& arg) = default;

	public: /*Opearators*/

		const duration& operator+=(const duration& d);
		const duration& operator-=(const duration& d);
		const duration& operator*=(const int rhs);
		const duration& operator/=(const int rhs);
		const duration& operator%=(const int rhs);
		const duration& operator%=(const duration& rhs);

		bool operator==(const duration& rhs) const;
		bool operator!=(const duration& rhs) const;
		bool operator<(const duration& rhs) const;
		bool operator<=(const duration& rhs) const;
		bool operator>(const duration& rhs) const;
		bool operator>=(const duration& rhs) const;

		duration operator+(const clock::duration& rhs) const;
		duration operator-(const clock::duration& rhs) const;
		duration operator*(const int rhs) const;
		duration operator/(const int rhs) const;
		duration operator%(const int rhs) const;
		duration operator%(const clock::duration& rhs) const;

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