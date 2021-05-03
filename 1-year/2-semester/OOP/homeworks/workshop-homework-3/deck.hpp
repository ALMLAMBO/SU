/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alexander Marinov
* @idnumber 62622
* @task 1
* @compiler VC
*/
#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <vector>
#include <string>
#include "monster_card.hpp"
#include "magic_card.hpp"
#include "pendulum_card.hpp"

class Deck {
public:
    Deck(const std::string& deck_name = "");

    Deck& set_deck_name(const std::string &deck_name);

    std::string& get_deck_name();
    unsigned int get_monster_cards_count() const;
    unsigned int get_magic_cards_count() const;
    unsigned int get_pendulum_cards_count() const;

    Deck& add_monster_card(const MonsterCard& monster_card);
    Deck& add_magic_card(const MagicCard& monster_card);
    Deck& add_pendulum_card(const PendulumCard& monster_card);

    Deck& change_monster_card(const int& index, const MonsterCard& monster_card);
    Deck& change_magic_card(const int& index, const MagicCard& magic_card);
    Deck& change_pendulum_card(const int& index, const PendulumCard& pendulum_card);

    Deck& clear();

    std::string to_string() const;

private:
    std::string deck_name;
    std::vector<MonsterCard> monster_cards;
    std::vector<MagicCard> magic_cards;
    std::vector<PendulumCard> pendulum_cards;

    std::string get_monster_cards_as_string() const;
    std::string get_magic_cards_as_string() const;
    std::string get_pendulum_cards_as_string() const;
};

#endif //__DECK_HPP__