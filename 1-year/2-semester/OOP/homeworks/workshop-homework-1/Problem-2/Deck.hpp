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
#pragma once
#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <iostream>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class Deck {
public:
	Deck();

	int get_magic_cards_count() const;
	int get_monster_cards_count() const;
	void add_monster_card(const MonsterCard& new_card);
	void add_magic_card(const MagicCard& new_card);
	void change_monster_card(int index, const char* new_name, 
		const int new_attack_points, const int new_deffense_points);
	
	void change_magic_card(int index, const char* new_name,
		const char* new_effect, const MagicCardType& new_type);

private:
	MonsterCard monster_cards[20];
	MagicCard magic_cards[20];
	int monster_cards_count;
	int magic_cards_count;

	bool monster_cards_deck_full() const;
	bool magic_cards_deck_full() const;
	int first_free_monster_card() const;
	int first_free_magic_card() const;
	bool empty_monster_card(const MonsterCard& card) const;
	bool empty_magic_card(const MagicCard& card) const;
};

#endif // !__DECK_HPP__