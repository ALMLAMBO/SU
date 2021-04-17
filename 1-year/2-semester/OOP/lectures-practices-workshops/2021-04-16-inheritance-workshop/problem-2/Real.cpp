#include "Real.hpp"

Real& Real::operator+(const Real& other) const {
	Real result(this->number + other.number);
	
	return result;
}

Real& Real::operator-(const Real& other) const {
	Real result(this->number - other.number);

	return result;
}

Real& Real::operator*(const Real& other) const {
	Real result(this->number * other.number);

	return result;
}

Real& Real::operator/(const Real& other) const {
	Real result(this->number / other.number);

	return result;
}

Real& Real::operator+=(const Real& other) const {
	Real result(this->number + other.number);

	return result;
}

Real& Real::operator-=(const Real& other) const {
	Real result(this->number - other.number);

	return result;
}