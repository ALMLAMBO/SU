#include "UserInfo.hpp"

UserInfo::UserInfo() {
	this->username = new char[1]{ '\0' };
	this->password = new char[1]{ '\0' };
}

UserInfo::UserInfo(const char* username) {
	this->copy_char_array(this->username, username);
	this->password = new char[1]{ '\0' };
}

UserInfo::UserInfo(const char* username, const char* password) {
	this->copy_char_array(this->username, username);
	this->copy_char_array(this->password, password);
}

UserInfo::UserInfo(const UserInfo& from) : 
	UserInfo(from.username, from.password) {}

void UserInfo::set_username(const char* new_username) {
	delete[] this->username;
	this->copy_char_array(this->username, new_username);
}

void UserInfo::set_password(const char* new_password) {
	delete[] this->password;
	this->copy_char_array(this->password, new_password);
}

char* UserInfo::get_username() const {
	return username;
}

char* UserInfo::get_password() const {
	return password;
}

void UserInfo::copy_char_array(char* destination, const char* source) {
	int len = strlen(source);
	destination = new char[len + 1];
	strcpy(destination, source);
	destination[len] = '\0';
}