#pragma once
#ifndef __VECTOR_4D_HPP__
#define __VECTOR_4D_HPP__

#include <vector>
#include <limits>

class Vector4D {
public:
	Vector4D(double first = 0, double second = 0, double third = 0, double fourth = 0);

	double& operator[](const int& index);
	
	Vector4D operator+(const Vector4D& other) const;
	Vector4D& operator+=(const Vector4D& other);
	Vector4D operator-() const;
	Vector4D operator-(const Vector4D& other) const;
	Vector4D& operator-=(const Vector4D& other);

	Vector4D operator*(const double& scalar) const;
	Vector4D operator*(const Vector4D& other) const;
	Vector4D& operator*=(const double& scalar);
	Vector4D& operator*=(const Vector4D& other);

	Vector4D operator/(const Vector4D& other) const;
	Vector4D& operator/=(const Vector4D& other);

	bool operator==(const Vector4D& other) const;
	bool operator!=(const Vector4D& other) const;
	bool operator>(const Vector4D& other) const;
	bool operator<(const Vector4D& other) const;
	bool operator>=(const Vector4D& other) const;
	bool operator<=(const Vector4D& other) const;
	bool operator!() const;

private:
	std::vector<double> coordinates;
};

#endif // !__VECTOR_4D_HPP__