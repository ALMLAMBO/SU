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
#ifndef __DUELIST_HPP__
#define __DUELIST_HPP__

#include "Deck.hpp"
#include "HelperFunctions.hpp"

class Duelist {
public:
	Duelist();
	Duelist(const char* name);
	Duelist(const Duelist& from);
	~Duelist();
	Duelist& operator=(const Duelist& from);

	void change_monster_card_in_deck(int index, 
		const MonsterCard& new_card);

	void change_magic_card_in_deck(int index,
		const MagicCard& new_card);

private:
	char* name;
	Deck deck;

	void copy_duelist(const Duelist& other);
};

#endif // !__DUELIST_HPP__
