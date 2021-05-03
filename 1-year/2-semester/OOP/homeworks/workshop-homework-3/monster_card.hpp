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
#ifndef __MONSTER_CARD_HPP__
#define __MONSTER_CARD_HPP__

#include "card.hpp"
#include <string>

class MonsterCard : virtual public Card {
public:
    MonsterCard(const std::string &card_name = "", const std::string &card_effect = "",
                const unsigned int& attack_points = 0, const unsigned int& defense_points = 0);

    void set_attack_points(const unsigned int& attack_points);
    void set_defense_points(const unsigned int& defense_points);

    unsigned int get_attack_points() const;
    unsigned int get_defense_points() const;

    std::string monster_card_to_string() const;

protected:
    unsigned int attack_points;
    unsigned int defense_points;
};


#endif //__MONSTER_CARD_HPP__
