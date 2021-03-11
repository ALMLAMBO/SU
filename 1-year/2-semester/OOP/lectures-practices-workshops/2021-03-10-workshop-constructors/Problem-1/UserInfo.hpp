#pragma once
#ifndef __USER_INFO_HPP__
#define __USER_INFO_HPP__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class UserInfo {
public:
	UserInfo();
	UserInfo(const char* username);
	UserInfo(const char* username, const char* password);
	UserInfo(const UserInfo& from);
	
	void set_username(const char* new_username);
	void set_password(const char* new_password);
	char* get_username() const;
	char* get_password() const;

private:
	char* username;
	char* password;

	void copy_char_array(char* destination, const char* source);
};

#endif // !__USER_INFO_HPP__