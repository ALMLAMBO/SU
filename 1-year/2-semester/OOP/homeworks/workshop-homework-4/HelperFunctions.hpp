/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alexander Marinov
* @idnumber 62622
* @task 1
* @compiler VC
*/
#ifndef __HELPER_FUNCTIONS_HPP__
#define __HELPER_FUNCTIONS_HPP__

#include <vector>
#include <string>
#include <fstream>
#include "Deck.hpp"

class HelperFunctions {
public:
    static std::vector<std::string> split_string(const std::string& string, char delimiter);
    static MagicCardType string_to_card_type(const std::string& card_type_as_string);
    static std::string card_type_to_string(const MagicCardType& magic_card_type);
    static void add_monster_cards(Deck& deck, std::istream& file_to_read, unsigned int monster_cards_count);
    static void add_magic_cards(Deck& deck, std::istream& file_to_read, unsigned int magic_cards_count);
    static void add_pendulum_cards(Deck& deck, std::istream& file_to_read, unsigned int pendulum_cards_count);

    static MonsterCard vector_to_monster_card(std::vector<std::string> data);
    static MagicCard vector_to_magic_card(std::vector<std::string> data);
    static PendulumCard vector_to_pendulum_card(std::vector<std::string> data);
};


#endif //__HELPER_FUNCTIONS_HPP__