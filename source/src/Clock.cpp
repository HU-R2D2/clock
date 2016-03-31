#include "../include/Clock.hpp"

//============================================================================================================
//Class Clock
//============================================================================================================
Clock::TimeStamp Clock::get_current_time()
{
	return TimeStamp();
}

//============================================================================================================
//Class Clock::Duration
//============================================================================================================

Clock::Duration::Duration() :
	m_duration(std::chrono::microseconds(0))
{}

Clock::Duration::Duration(const std::chrono::duration<long, std::micro>& arg) :
	m_duration(arg)
{}

const Clock::Duration& Clock::Duration::operator+=(const Duration &d) {
	this->m_duration += d.m_duration;
	return *this;
}

const Clock::Duration& Clock::Duration::operator-=(const Duration &d) {
	this->m_duration -= d.m_duration;
	return *this;
}

const Clock::Duration& Clock::Duration::operator*=(const int rhs) {
	this->m_duration = m_duration * rhs;
	return *this;
}

const Clock::Duration& Clock::Duration::operator/=(const int rhs) {
	this->m_duration = m_duration / rhs;
	return *this;
}

bool Clock::Duration::operator==(const Duration & rhs) const {
	return this->m_duration == rhs.m_duration;
}

bool Clock::Duration::operator!=(const Duration & rhs) const {
	return !(this->m_duration == rhs.m_duration);
}

bool Clock::Duration::operator<(const Duration & rhs) const {
	return this->m_duration < rhs.m_duration;
}

bool Clock::Duration::operator<=(const Duration & rhs) const {
	return this->m_duration <= rhs.m_duration;
}

bool Clock::Duration::operator>(const Duration & rhs) const {
	return this->m_duration > rhs.m_duration;
}

bool Clock::Duration::operator>=(const Duration & rhs) const {
	return this->m_duration >= rhs.m_duration;
}

Clock::Duration Clock::Duration::operator+(const Clock::Duration & rhs) const {
	return this->m_duration + rhs.m_duration;
}

Clock::Duration Clock::Duration::operator-(const Clock::Duration & rhs) const {
	return this->m_duration - rhs.m_duration;
}

Clock::Duration Clock::Duration::operator*(const int rhs) const {
	return this->m_duration * rhs;
}

Clock::Duration Clock::Duration::operator/(const int rhs) const {
	return this->m_duration / rhs;
}

//============================================================================================================
//Class Clock::TimeStamp
//============================================================================================================

Clock::TimeStamp::TimeStamp() :
	m_time_stamp(std::chrono::high_resolution_clock::now())
{}

Clock::TimeStamp::TimeStamp
(const std::chrono::time_point<std::chrono::high_resolution_clock>& arg) :
	m_time_stamp(arg)
{}

bool Clock::TimeStamp::operator==(const Clock::TimeStamp& rhs) const {
	return this->m_time_stamp == rhs.m_time_stamp;
}
bool Clock::TimeStamp::operator!=(const Clock::TimeStamp& rhs) const {
	return !(this->m_time_stamp == rhs.m_time_stamp);
}
bool Clock::TimeStamp::operator<(const Clock::TimeStamp& rhs) const {
	return this->m_time_stamp < rhs.m_time_stamp;
}
bool Clock::TimeStamp::operator<=(const Clock::TimeStamp& rhs) const {
	return this->m_time_stamp <= rhs.m_time_stamp;
}
bool Clock::TimeStamp::operator>(const Clock::TimeStamp& rhs) const {
	return this->m_time_stamp > rhs.m_time_stamp;
}
bool Clock::TimeStamp::operator>=(const Clock::TimeStamp& rhs) const {
	return this->m_time_stamp >= rhs.m_time_stamp;
}


Clock::Duration Clock::TimeStamp::operator-
(const Clock::TimeStamp& rhs) const {
	return Duration(std::chrono::duration_cast<std::chrono::microseconds>
		(this->m_time_stamp - rhs.m_time_stamp));
}

//============================================================================================================
//Friend functies
//============================================================================================================

Clock::TimeStamp& operator+=
(Clock::TimeStamp& lhs, const Clock::Duration& d) {
	lhs.m_time_stamp = lhs.m_time_stamp + d.m_duration;
	return lhs;
}

Clock::TimeStamp& operator-=
(Clock::TimeStamp& lhs, const Clock::Duration& d) {
	lhs.m_time_stamp = lhs.m_time_stamp - d.m_duration;
	return lhs;
}

Clock::TimeStamp operator+
(const Clock::TimeStamp& lhs, const Clock::Duration& rhs) {
	return lhs.m_time_stamp + rhs.m_duration;
}

Clock::TimeStamp operator-
(const Clock::TimeStamp& lhs, const Clock::Duration& rhs) {
	return lhs.m_time_stamp - rhs.m_duration;
}

Clock::TimeStamp operator+
(const Clock::Duration& lhs, const Clock::TimeStamp& rhs) {
	return rhs.m_time_stamp + lhs.m_duration;
}


std::ostream & operator<<(std::ostream & s, const Clock::Duration & rhs) {
	s << rhs.m_duration.count();
	return s;
}

std::ostream & operator<<(std::ostream & s, const Clock::TimeStamp &rhs) {
	std::chrono::microseconds ms = 
		std::chrono::duration_cast<std::chrono::microseconds>(rhs.m_time_stamp.time_since_epoch());
	s << ms.count();
	return s;
}
