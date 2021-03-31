#include "Database.hpp"

User Database::find_by_id(const int& id) const {
	std::list<User>::const_iterator it = std::find_if(
		this->users.begin(), this->users.end(),
		[id](const User& user) {
			return user.get_id() == id;
		});

	return *it;
}

User Database::find_by_username(const std::string& username) const {
	std::list<User>::const_iterator it = std::find_if(
		this->users.begin(), this->users.end(),
		[username](const User& user) {
			return user.get_name() == username;
		});

	return *it;
}

void Database::add_user(const User& user) {
	this->users.push_back(user);
}