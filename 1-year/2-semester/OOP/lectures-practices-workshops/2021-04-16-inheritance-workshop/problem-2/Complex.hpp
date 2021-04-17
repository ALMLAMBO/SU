#pragma once
#ifndef __COMPLEX_HPP__

#include "Real.hpp"

class Complex : public Real {
public:
	Complex& set_real(const double& new_real);
	Complex& set_imag(const double& new_imag);
	double get_imag() const;

	Complex& operator+(const Complex& other) const;
	Complex& operator-(const Complex& other) const;
	Complex& operator*(const Complex& other) const;
	Complex& operator/(const Complex& other) const;
	Complex& operator+=(const Complex& other) const;
	Complex& operator-=(const Complex& other) const;

private:
	Real imag;
};

#endif // !__COMPLEX_HPP__