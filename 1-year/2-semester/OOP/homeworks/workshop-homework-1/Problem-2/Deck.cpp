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
#include "Deck.hpp"

Deck::Deck() : magic_cards_count(0), 
		monster_cards_count(0) { }

int Deck::get_magic_cards_count() const {
	return this->magic_cards_count;
}

int Deck::get_monster_cards_count() const {
	return this->monster_cards_count;
}

void Deck::add_monster_card(const MonsterCard& new_card) {
	int index = this->first_free_monster_card();
	
	if (index >= 0) {
		this->monster_cards[index] = new_card;
		this->monster_cards_count++;
	}
	else {
		std::cout << "Monster cards deck full" << std::endl;
	}
}

void Deck::add_magic_card(const MagicCard& new_card) {
	int index = this->first_free_magic_card();
	
	if (index >= 0) {
		this->magic_cards[index] = new_card;
		this->magic_cards_count++;
	}
	else {
		std::cout << "Magic cards deck full" << std::endl;
	}
}

void Deck::change_monster_card(int index, const char* new_name,
	const int new_attack_points, const int new_deffense_points) {

	if (0 <= index && index < 20) {
		MonsterCard new_card(new_name, 
			new_attack_points, new_deffense_points);

		if (this->empty_monster_card(this->monster_cards[index])) {
			this->monster_cards_count++;
		}
		this->monster_cards[index] = new_card;
	}
	else {
		std::cout << "Invalid index" << std::endl;
	}
}

void Deck::change_magic_card(int index, const char* new_name,
	const char* new_effect, const MagicCardType& new_type) {

	if (0 <= index && index < 20) {
		MagicCard new_card(new_name,
			new_effect, new_type);

		if (this->empty_magic_card(this->magic_cards[index])) {
			this->magic_cards_count++;
		}
		this->magic_cards[index] = new_card;
	}
	else {
		std::cout << "Invalid index" << std::endl;
	}
}

bool Deck::monster_cards_deck_full() const {
	return this->monster_cards_count == 19;
}

bool Deck::magic_cards_deck_full() const {
	return this->magic_cards_count == 19;
}

int Deck::first_free_monster_card() const {
	if (!this->monster_cards_deck_full()) {
		int index = 0;

		for (int i = 0; i < 20; i++) {
			if (this->empty_monster_card(this->monster_cards[i])) {
				index = i;
				break;
			}
		}

		return index;
	}
	else {
		return -1;
	}
}

int Deck::first_free_magic_card() const {
	if (!this->magic_cards_deck_full()) {
		int index = 0;

		for (int i = 0; i < 20; i++) {
			if (this->empty_magic_card(this->magic_cards[i])) {
				index = i;
				break;
			}
		}

		return index;
	}
	else {
		return -1;
	}
}

bool Deck::empty_monster_card(const MonsterCard& card) const {
	return strlen(card.get_name()) == 0;
}

bool Deck::empty_magic_card(const MagicCard& card) const {
	return strlen(card.get_name()) == 0;
}