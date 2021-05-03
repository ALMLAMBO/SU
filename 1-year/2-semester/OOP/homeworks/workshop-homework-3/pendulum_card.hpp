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
#ifndef __PENDULUM_CARD_HPP__
#define __PENDULUM_CARD_HPP__

#include "monster_card.hpp"
#include "magic_card.hpp"
#include <sstream>

class PendulumCard : public MonsterCard, public MagicCard {
public:
    PendulumCard(const std::string &card_name = "", const std::string &card_effect = "",
                 const unsigned int& attack_points = 0, const unsigned int& defense_points = 0,
                 const unsigned int& pendulum_scale = 1, const MagicCardType& card_type = MagicCardType::trap);

    void set_pendulum_scale(const unsigned int& pendulum_scale);
    unsigned int get_pendulum_scale() const;

    std::string pendulum_card_to_string() const;

private:
    unsigned int pendulum_scale;
};


#endif //__PENDULUM_CARD_HPP__
