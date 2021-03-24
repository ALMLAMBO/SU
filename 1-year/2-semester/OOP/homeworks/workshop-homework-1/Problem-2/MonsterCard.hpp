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
#ifndef __MONSTER_CARD_HPP__
#define __MONSTER_CARD_HPP__

#include "HelperFunctions.hpp"

class MonsterCard {
public:
	MonsterCard();
	MonsterCard(const char* name,
		const unsigned int& attact_points,
		const unsigned int& defense_points);

	MonsterCard(const MonsterCard& from);
	~MonsterCard();
	MonsterCard& operator=(const MonsterCard& other);

	void set_name(const char* new_name);
	void set_attack_points(const unsigned int& new_attack_points);
	void set_defense_points(const unsigned int& new_defense_points);

	char* get_name() const;
	unsigned int get_attack_points() const;
	unsigned int get_defense_points() const;

private:
	char* name;
	unsigned int attack_points;
	unsigned int defense_points;

	void copy_monster_card(const MonsterCard& other);
};

#endif // !__MONSTER_CARD_HPP__