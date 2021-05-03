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
#include "monster_card.hpp"

MonsterCard::MonsterCard(const std::string &card_name, const std::string &card_effect,
                         const unsigned int &attack_points, const unsigned int &defense_points) :

                         Card(card_name, card_effect) {

    this->attack_points = attack_points;
    this->defense_points = defense_points;
}

void MonsterCard::set_attack_points(const unsigned int& attack_points) {
    this->attack_points = attack_points;
}

void MonsterCard::set_defense_points(const unsigned int& defense_points) {
    this->defense_points = defense_points;
}

unsigned int MonsterCard::get_attack_points() const {
    return this->attack_points;
}

unsigned int MonsterCard::get_defense_points() const {
    return this->defense_points;
}

std::string MonsterCard::monster_card_to_string() const {
    return this->card_to_string() + "|" + std::to_string(this->attack_points) +
        "|" + std::to_string(this->defense_points);
}
