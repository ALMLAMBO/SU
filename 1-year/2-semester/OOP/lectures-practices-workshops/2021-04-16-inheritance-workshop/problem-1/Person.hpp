#pragma once
#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <string>

class Person {
public:
	Person(const std::string& first_name = "", 
		const std::string& last_name = "", const unsigned int& age = 1,
		const std::string& town = "", const std::string& street = "");

	Person& set_first_name(const std::string& new_first_name);
	Person& set_last_name(const std::string& new_last_name);
	Person& set_age(const unsigned int& new_age);
	Person& set_town(const std::string& new_town);
	Person& set_street(const std::string& new_street);

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_town() const;
	std::string get_street() const;
	unsigned int get_age() const;

private:
	std::string first_name;
	std::string last_name;
	unsigned int age;
	std::string town;
	std::string street;
};

#endif // !__PERSON_HPP__