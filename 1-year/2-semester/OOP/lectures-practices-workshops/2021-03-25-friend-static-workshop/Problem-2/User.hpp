#pragma once
#ifndef __USER_HPP__
#define __USER_HPP__

#include <iostream>
#include <string>

class User {
public:
	User(const std::string& name, const std::string& password,
		const unsigned int& id);

	bool login(const std::string& password) const;

	std::string get_name() const {
		return this->name;
	}

	std::string get_password() const {
		return this->password;
	}

	unsigned int get_id() const {
		return this->id;
	}

private:
	std::string name;
	std::string password;
	unsigned int id;

};

#endif // !__USER_HPP__