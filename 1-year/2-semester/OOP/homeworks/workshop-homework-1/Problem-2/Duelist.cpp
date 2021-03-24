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
#include "Duelist.hpp"

Duelist::Duelist() {
	this->name = new char[1]{ '\0' };
}

Duelist::Duelist(const char* name) {
	this->name = HelperFunctions::copy_char_array(name, 0);
}

Duelist::Duelist(const Duelist& from) {
	this->copy_duelist(from);
}

Duelist::~Duelist() {
	delete[] this->name;
}

Duelist& Duelist::operator=(const Duelist& from) {
	if (this != &from) {
		delete[] this->name;
		this->copy_duelist(from);
	}

	return *this;
}

void Duelist::change_monster_card_in_deck(int index,
	const MonsterCard& new_card) {

	this->deck.change_monster_card(index, new_card.get_name(),
		new_card.get_attack_points(), new_card.get_defense_points());
}

void Duelist::change_magic_card_in_deck(int index,
	const MagicCard& new_card) {

	this->deck.change_magic_card(index, new_card.get_name(),
		new_card.get_effect(), new_card.get_type());
}