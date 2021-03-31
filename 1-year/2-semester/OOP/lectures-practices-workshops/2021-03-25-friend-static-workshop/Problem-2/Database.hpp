#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__

#include <list>
#include <string>
#include <algorithm>
#include "User.hpp"

class Database {
public:
	User find_by_id(const int& id) const;
	User find_by_username(const std::string& username) const;

	void add_user(const User& user);
private:
	std::list<User> users;
};

#endif // !__DATABASE_HPP__
