#pragma once
#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

#include <cmath>
#include <string>

class Rational {
public:
    Rational();
    Rational(const int num, const int denom);

    Rational add(const Rational& other) const;
    Rational subtract(const Rational& other) const;
    Rational multiply(const Rational& other) const;
    Rational divide(const Rational& other) const;

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    bool operator==(const Rational& other) const;

    double to_real() const;
    std::string to_string() const;

private:
    int numerator;
    int denominator;
};

#endif // !__RATIONAL_HPP__