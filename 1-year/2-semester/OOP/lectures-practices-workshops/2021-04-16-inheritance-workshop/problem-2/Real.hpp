#pragma once
#ifndef __REAL_HPP__
#define __REAL_HPP__

class Real {
public:
	Real(const double& number = 0);

	Real& set_real(const double& new_number) {
		this->number = new_number;

		return *this;
	}

	double get_real() const {
		return this->number;
	}

	Real& operator+(const Real& other) const;
	Real& operator-(const Real& other) const;
	Real& operator*(const Real& other) const;
	Real& operator/(const Real& other) const;
	Real& operator+=(const Real& other) const;
	Real& operator-=(const Real& other) const;

private:
	double number;
};

#endif // !__REAL_HPP__