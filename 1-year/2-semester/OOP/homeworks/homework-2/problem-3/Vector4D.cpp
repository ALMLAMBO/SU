#include "Vector4D.hpp"

Vector4D::Vector4D(double first, double second, 
	double third, double fourth) {
	
	this->coordinates.push_back(first);
	this->coordinates.push_back(second);
	this->coordinates.push_back(third);
	this->coordinates.push_back(fourth);
}

/// <summary>
/// returns value at given index
/// </summary>
/// <param name="index">index to get value</param>
/// <returns>DBL_MIN if invalid index</returns>
double& Vector4D::operator[](const int& index) {
	if (0 <= index && index < this->coordinates.size()) {
		return this->coordinates[index];
	}

	double min_value = std::numeric_limits<double>::min();

	return min_value;
}

Vector4D Vector4D::operator+(const Vector4D& other) const {
	Vector4D result;
	std::vector<double> result_values;

	for (int i = 0; i < 4; i++) {
		result_values.push_back(
			this->coordinates[i] + other.coordinates[i]);
	}

	result.coordinates = std::vector<double>(result_values);

	return result;
}

Vector4D& Vector4D::operator+=(const Vector4D& other) {
	for (int i = 0; i < 4; i++) {
		this->coordinates[i] += other.coordinates[i];
	}

	return *this;
}

Vector4D Vector4D::operator-() const {
	Vector4D result;

	std::vector<double> result_values;
	
	for (int i = 0; i < 4; i++) {
		result_values.push_back(-this->coordinates[i]);
	}

	result.coordinates = std::vector<double>(result_values);

	return result;
}

Vector4D Vector4D::operator-(const Vector4D& other) const {
	Vector4D result;
	std::vector<double> result_values;

	for (int i = 0; i < 4; i++) {
		result_values.push_back(
			this->coordinates[i] - other.coordinates[i]);
	}

	result.coordinates = std::vector<double>(result_values);

	return result;
}

Vector4D& Vector4D::operator-=(const Vector4D& other) {
	for (int i = 0; i < 4; i++) {
		this->coordinates[i] -= other.coordinates[i];
	}

	return *this;
}

Vector4D Vector4D::operator*(const double& scalar) const {
	Vector4D result;
	std::vector<double> result_values;

	for (int i = 0; i < 4; i++) {
		result_values.push_back(
			this->coordinates[i] * scalar);
	}

	result.coordinates = std::vector<double>(result_values);

	return result;
}

Vector4D Vector4D::operator*(const Vector4D& other) const {
	Vector4D result;
	std::vector<double> result_values;

	for (int i = 0; i < 4; i++) {
		result_values.push_back(
			this->coordinates[i] * other.coordinates[i]);
	}

	result.coordinates = std::vector<double>(result_values);

	return result;
}

Vector4D& Vector4D::operator*=(const double& scalar) {
	for (int i = 0; i < 4; i++) {
		this->coordinates[i] *= scalar;
	}

	return *this;
}

Vector4D& Vector4D::operator*=(const Vector4D& other) {
	for (int i = 0; i < 4; i++) {
		this->coordinates[i] *= other.coordinates[i];
	}

	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& other) const {
	Vector4D result;
	std::vector<double> result_values;

	for (int i = 0; i < 4; i++) {
		result_values.push_back(
			this->coordinates[i] / other.coordinates[i]);
	}

	result.coordinates = std::vector<double>(result_values);

	return result;
}

Vector4D& Vector4D::operator/=(const Vector4D& other) {
	for (int i = 0; i < 4; i++) {
		this->coordinates[i] -= other.coordinates[i];
	}

	return *this;
}

bool Vector4D::operator==(const Vector4D& other) const {
	for (int i = 0; i < 4; i++) {
		if (this->coordinates[i] != other.coordinates[i]) {
			return false;
		}
	}

	return true;
}

bool Vector4D::operator!=(const Vector4D& other) const {
	return !(*this == other);
}

bool Vector4D::operator>(const Vector4D& other) const {
	for (int i = 0; i < 4; i++) {
		if (!(this->coordinates[i] > other.coordinates[i])) {
			return false;
		}
	}

	return true;
}

bool Vector4D::operator<(const Vector4D& other) const {
	return !(*this > other);
}

bool Vector4D::operator>=(const Vector4D& other) const {
	for (int i = 0; i < 4; i++) {
		if (!(this->coordinates[i] >= other.coordinates[i])) {
			return false;
		}
	}

	return true;
}

bool Vector4D::operator<=(const Vector4D& other) const {
	return !(*this >= other);
}

bool Vector4D::operator!() const {
	return *this == Vector4D();
}