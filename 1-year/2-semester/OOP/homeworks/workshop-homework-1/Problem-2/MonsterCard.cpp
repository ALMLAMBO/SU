#include "MonsterCard.hpp"

MonsterCard::MonsterCard() : 
	attack_points(0), defense_points(0) {

	this->name = new char[1]{ '\0' };
}

MonsterCard::MonsterCard(const char* name,
	const unsigned int& attack_points,
	const unsigned int& defense_points) {

	this->attack_points = attack_points;
	this->defense_points = defense_points;
	this->name = HelperFunctions::copy_char_array(name, 25);
}

MonsterCard::MonsterCard(const MonsterCard& from) {
	this->copy_monster_card(from);
}

MonsterCard::~MonsterCard() {
	delete this->name;
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other) {
	if (this != &other) {
		delete[] this->name;
		this->copy_monster_card(other);
	}

	return *this;
}

void MonsterCard::set_name(const char* new_name) {
	this->name = HelperFunctions::copy_char_array(new_name, 25);
}

void MonsterCard::set_attack_points(const unsigned int& new_attack_points) {
	this->attack_points = new_attack_points;
}

void MonsterCard::set_defense_points(const unsigned int& new_defense_points) {
	this->defense_points = new_defense_points;
}

char* MonsterCard::get_name() const {
	return this->name;
}

unsigned int MonsterCard::get_attack_points() const {
	return this->attack_points;
}

unsigned int MonsterCard::get_defense_points() const {
	return this->defense_points;
}

void MonsterCard::copy_monster_card(const MonsterCard& other) {
	this->attack_points = other.attack_points;
	this->defense_points = other.defense_points;
	this->name = HelperFunctions::copy_char_array(other.name, 25);
}