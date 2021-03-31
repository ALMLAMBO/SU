#include "User.hpp"

User::User(const std::string& name, const std::string& password,
	const unsigned int& id) {

	if (name.length() >= 4) {
		this->name = name;
	}
	else {
		std::cout << "Invalid username" << std::endl;
	}

	this->password = password;
	this->id = id;
}

bool User::login(const std::string& password) const {
	return this->password == password;
}