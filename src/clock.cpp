#include "clock.hpp"

//============================================================================================================
//Class Clock
//============================================================================================================
clock::time_stamp clock::get_current_time()
{
	return time_stamp();
}

//============================================================================================================
//Class Clock::duration
//============================================================================================================

clock::duration::duration() {

}

clock::duration::duration(const std::chrono::duration<long, std::micro>& arg) {

}

const clock::duration& clock::duration::operator+=(const duration &d) {
	this->m_duration += d.m_duration;
	return *this;
}

const clock::duration& clock::duration::operator-=(const duration &d) {
	this->m_duration -= d.m_duration;
	return *this;
}

const clock::duration& clock::duration::operator*=(const int rhs) {
	this->m_duration = m_duration * rhs;
	return *this;
}

const clock::duration& clock::duration::operator/=(const int rhs) {
	this->m_duration = m_duration / rhs;
	return *this;
}

const clock::duration& clock::duration::operator%=(const int rhs) {
	this->m_duration = m_duration % rhs;
	return *this;
}

const clock::duration& clock::duration::operator%=(const duration &rhs) {
	this->m_duration = m_duration % rhs.m_duration;
	return *this;
}

bool clock::duration::operator==(const duration & rhs) const {

	return this->m_duration == rhs.m_duration;
}

bool clock::duration::operator!=(const duration & rhs) const {
	return !(this->m_duration == rhs.m_duration);
}

bool clock::duration::operator<(const duration & rhs) const {
	return this->m_duration < rhs.m_duration;
}

bool clock::duration::operator<=(const duration & rhs) const {
	return this->m_duration <= rhs.m_duration;
}

bool clock::duration::operator>(const duration & rhs) const {
	return this->m_duration > rhs.m_duration;
}

bool clock::duration::operator>=(const duration & rhs) const {
	return this->m_duration >= rhs.m_duration;
}

clock::duration clock::duration::operator+(const clock::duration & rhs) const {
	return this->m_duration + rhs.m_duration;
}

clock::duration clock::duration::operator-(const clock::duration & rhs) const {
	//duration d;
	//d.m_duration = this->m_duration - rhs.m_duration;
	return this->m_duration - rhs.m_duration;
}

clock::duration clock::duration::operator*(const int rhs) const {
	return this->m_duration * rhs;
}

clock::duration clock::duration::operator/(const int rhs) const {
	return this->m_duration / rhs;
}

clock::duration clock::duration::operator%(const int rhs) const {
	return this->m_duration % rhs;
}

clock::duration clock::duration::operator%(const clock::duration & rhs) const {
	return this->m_duration % rhs.m_duration;
}

//============================================================================================================
//Class Clock::time_stamp
//============================================================================================================

clock::time_stamp::time_stamp() {

}

clock::time_stamp::time_stamp(const std::chrono::time_point<std::chrono::high_resolution_clock>& arg) {

}


bool clock::time_stamp::operator==(const clock::time_stamp& rhs) const {
	return this->m_time_stamp == rhs.m_time_stamp;
}
bool clock::time_stamp::operator!=(const clock::time_stamp& rhs) const {
	return !(this->m_time_stamp == rhs.m_time_stamp);
}
bool clock::time_stamp::operator<(const clock::time_stamp& rhs) const {
	return this->m_time_stamp < rhs.m_time_stamp;
}
bool clock::time_stamp::operator<=(const clock::time_stamp& rhs) const {
	return this->m_time_stamp <= rhs.m_time_stamp;
}
bool clock::time_stamp::operator>(const clock::time_stamp& rhs) const {
	return this->m_time_stamp > rhs.m_time_stamp;
}
bool clock::time_stamp::operator>=(const clock::time_stamp& rhs) const {
	return this->m_time_stamp >= rhs.m_time_stamp;
}


clock::duration clock::time_stamp::operator-(const clock::time_stamp& rhs) const {

}

//============================================================================================================
//Friend functies
//============================================================================================================

clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d) {
	lhs.m_time_stamp = lhs.m_time_stamp + d.m_duration;
	return lhs;
}

clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d) {
	lhs.m_time_stamp = lhs.m_time_stamp - d.m_duration;
	return lhs;
}

clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs) {
	return lhs.m_time_stamp + rhs.m_duration;
}

clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs) {
	return lhs.m_time_stamp - rhs.m_duration;
}

clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs) {
	return lhs.m_duration + rhs.m_time_stamp;
}


std::ostream & operator<<(std::ostream & s, const clock::duration & rhs) {
	s << rhs.m_duration.count();
	return s;
}

std::ostream & operator<<(std::ostream & s, const clock::time_stamp &rhs) {
	std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(rhs.m_time_stamp.time_since_epoch());
	s << ms.count();
	return s;
}
