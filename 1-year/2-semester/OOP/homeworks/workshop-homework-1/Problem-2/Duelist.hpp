#pragma once
#ifndef __DUELIST_HPP__
#define __DUELIST_HPP__

#include "Deck.hpp"

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
