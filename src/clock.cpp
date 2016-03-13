#include "clock.hpp"

int main() {
	return 0;
}

//============================================================================================================
//Class Clock
//============================================================================================================
clock::time_stamp clock::get_current_time() {
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
	m_duration += d.m_duration;
	return m_duration;
}

const clock::duration& clock::duration::operator-=(const duration &d) {
	m_duration -= d.m_duration;
	return m_duration;
}

const clock::duration& clock::duration::operator*=(const int rhs) {
	m_duration = m_duration * rhs;
	return m_duration;
}

const clock::duration& clock::duration::operator/=(const int rhs) {
	m_duration = m_duration / rhs;
	return m_duration;
}

const clock::duration& clock::duration::operator%=(const int rhs) {
	m_duration = m_duration % rhs;
	return m_duration;
}

const clock::duration& clock::duration::operator%=(const duration &rhs) {
	m_duration = m_duration % rhs.m_duration;
	return m_duration;
}


bool clock::duration::operator==(const clock::duration& rhs) const {

}

bool clock::duration::operator!=(const clock::duration& rhs) const {

}

bool clock::duration::operator<(const clock::duration& rhs) const {

}

bool clock::duration::operator<=(const clock::duration& rhs) const {

}

bool clock::duration::operator>(const clock::duration& rhs) const {
	
}

bool clock::duration::operator>=(const clock::duration& rhs) const {
	
}


clock::duration clock::duration::operator+(const clock::duration& rhs) const {

}

clock::duration clock::duration::operator-(const clock::duration& rhs) const {

}

clock::duration clock::duration::operator*(const int rhs) const {

}

clock::duration clock::duration::operator/(const int rhs) const {

}

clock::duration clock::duration::operator%(const int rhs) const {

}

clock::duration clock::duration::operator%(const clock::duration& rhs) const {

}

//============================================================================================================
//Class Clock::time_stamp
//============================================================================================================

clock::time_stamp::time_stamp() {

}

clock::time_stamp::time_stamp(const std::chrono::time_point<std::chrono::high_resolution_clock>& arg) {

}


bool clock::time_stamp::operator==(const clock::time_stamp& rhs) const {

}
bool clock::time_stamp::operator!=(const clock::time_stamp& rhs) const {

}
bool clock::time_stamp::operator<(const clock::time_stamp& rhs) const {

}
bool clock::time_stamp::operator<=(const clock::time_stamp& rhs) const {

}
bool clock::time_stamp::operator>(const clock::time_stamp& rhs) const {

}
bool clock::time_stamp::operator>=(const clock::time_stamp& rhs) const {

}


clock::duration clock::time_stamp::operator-(const clock::time_stamp& rhs) const {

}

//============================================================================================================
//Friend functies
//============================================================================================================

clock::time_stamp& operator+=(clock::time_stamp& lhs, const clock::duration& d) {

}
clock::time_stamp& operator-=(clock::time_stamp& lhs, const clock::duration& d) {

}
clock::time_stamp operator+(const clock::time_stamp& lhs, const clock::duration& rhs) {

}
clock::time_stamp operator-(const clock::time_stamp& lhs, const clock::duration& rhs) {

}
clock::time_stamp operator+(const clock::duration& lhs, const clock::time_stamp& rhs) {

}

std::ostream & operator<<(std::ostream & s, const clock::duration & rhs) {

}
std::ostream & operator<<(std::ostream & s, const clock::time_stamp &rhs) {

}