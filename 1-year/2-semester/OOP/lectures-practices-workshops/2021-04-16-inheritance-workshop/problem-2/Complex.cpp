#include "Complex.hpp"

Complex& Complex::set_real(const double& new_real) {
	this->set_real(new_real);

	return *this;
}

Complex& Complex::set_imag(const double& new_imag) {
	this->imag.set_real(new_imag);

	return *this;
}

double Complex::get_imag() const {
	return this->imag.get_real();
}

Complex& Complex::operator+(const Complex& other) const {
	Complex result;

	result
		.set_real(this->get_real() + other.get_real())
		.set_imag(this->get_imag() + other.get_imag());

	return result;
}

Complex& Complex::operator-(const Complex& other) const {
	Complex result;

	result
		.set_real(this->get_real() - other.get_real())
		.set_imag(this->get_imag() - other.get_imag());

	return result;
}

Complex& Complex::operator*(const Complex& other) const {
	Complex result;

	result
		.set_real(this->get_real() * other.get_real() - 
			this->get_imag() * other.get_imag())

		.set_imag(this->get_real() * other.get_imag() + 
			other.get_real() * this->get_imag());

	return result;
}

Complex& Complex::operator/(const Complex& other) const {
	Complex result;

	return result;
}

Complex& Complex::operator+=(const Complex& other) const {
	Complex result;

	result
		.set_real(this->get_real() + other.get_real())
		.set_imag(this->get_imag() + other.get_imag());

	return result;
}

Complex& Complex::operator-=(const Complex& other) const {
	Complex result;

	result
		.set_real(this->get_real() - other.get_real())
		.set_imag(this->get_imag() - other.get_imag());

	return result;
}