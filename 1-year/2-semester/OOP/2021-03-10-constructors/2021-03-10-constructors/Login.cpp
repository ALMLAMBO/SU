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

Login::Login(const Login& other) {

}

void Login::set_username(const char*) {

}

void Login::set_password(const char*) {

}

void Login::set_session(const int) {

}

void Login::print() const {

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

}