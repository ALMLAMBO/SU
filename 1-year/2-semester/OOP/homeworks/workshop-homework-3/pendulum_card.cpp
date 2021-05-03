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
#include "pendulum_card.hpp"

PendulumCard::PendulumCard(const std::string &card_name, const std::string &card_effect,
                           const unsigned int &attack_points, const unsigned int &defense_points,
                           const unsigned int& pendulum_scale, const MagicCardType &card_type) :

                            Card(card_name, card_effect) {

    this->set_attack_points(attack_points);
    this->set_defense_points(defense_points);
    this->set_card_type(card_type);
    this->set_pendulum_scale(pendulum_scale);
}

unsigned int PendulumCard::get_pendulum_scale() const {
    return this->pendulum_scale;
}

void PendulumCard::set_pendulum_scale(const unsigned int& pendulum_scale) {
    if(pendulum_scale >= 1 && pendulum_scale <= 13) {
        this->pendulum_scale = pendulum_scale;
    }
}

std::string PendulumCard::pendulum_card_to_string() const {
    std::stringstream ss;

    ss << this->monster_card_to_string() << "|"
        << this->pendulum_scale << "|" << this->get_card_type_to_string();

    return ss.str();
}