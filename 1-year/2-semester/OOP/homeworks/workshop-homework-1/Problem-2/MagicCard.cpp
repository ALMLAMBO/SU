/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alexander Marinov
* @idnumber 62622
* @task 2
* @compiler VC
*/
#include "MagicCard.hpp"

MagicCard::MagicCard() {
	this->name = new char[] {'\0'};
	this->effect = new char[] {'\0'};
	this->type = MagicCardType::spell;
}

MagicCard::MagicCard(const char* name, const char* effect,
	const MagicCardType& type) {

	this->name = HelperFunctions::copy_char_array(name, 25);
	this->effect = HelperFunctions::copy_char_array(effect, 100);
	this->type = type;
}

MagicCard::MagicCard(const MagicCard& from) {
	this->copy_magic_card(from);
}

MagicCard::~MagicCard() {
	delete[] this->name;
	delete[] this->effect;
}

MagicCard& MagicCard::operator=(const MagicCard& other) {
	if (this != &other) {
		delete[] this->name;
		delete[] this->effect;

		this->copy_magic_card(other);
	}

	return *this;
}

void MagicCard::set_name(const char* new_name) {
	this->name = HelperFunctions::copy_char_array(new_name, 25);
}

void MagicCard::set_effect(const char* new_effect) {
	this->effect = HelperFunctions::copy_char_array(new_effect, 100);
}

void MagicCard::set_type(const MagicCardType& new_type) {
	this->type = new_type;
}

char* MagicCard::get_name() const {
	return this->name;
}

char* MagicCard::get_effect() const {
	return this->effect;
}

MagicCardType MagicCard::get_type() const {
	return this->type;
}

void MagicCard::copy_magic_card(const MagicCard& other) {
	this->name = HelperFunctions::copy_char_array(other.name, 25);
	this->effect = HelperFunctions::copy_char_array(other.effect, 100);
	this->type = other.type;
}