#include "Login.hpp"

Login::Login() {
	this->username = new char[1]{ '\0' };
	this->password = new char[1]{ '\0' };
	this->session = 0;
}

Login::Login(const char* username) {
	this->copy_char_array(this->username, username);
	this->password = new char[1]{ '\0' };
	this->session = 0;
}

Login::Login(const char* username, const char* password) {
	this->copy_char_array(this->username, username);
	this->copy_char_array(this->password, password);
	this->session = 0;
}

Login::Login(const char* username, 
	const char* password, const int session) : Login(username, password) {

	this->session = session;
}

Login::Login(const Login& other) : 
	Login(other.username, other.password, other.session) { }

void Login::set_username(const char* new_username) {
	delete[] this->username;
	this->copy_char_array(this->username, new_username);
}

void Login::set_password(const char* new_password) {
	delete[] this->password;
	this->copy_char_array(this->password, new_password);
}

void Login::set_session(const int new_session) {
	this->session = new_session;
}

void Login::print() const {
	std::cout << this->username 
		<< " " << this->password 
		<< " " << this->session 
		<< std::endl;
}

char* Login::get_username() const {
	return username;
}

char* Login::get_password() const {
	return password;
}

int Login::get_session() const {
	return session;
}

void Login::copy_char_array(char* destination, const char* source) {
	int len = strlen(source);
	destination = new char[len + 1];
	strcpy(destination, source);
	destination[len] = '\0';
}