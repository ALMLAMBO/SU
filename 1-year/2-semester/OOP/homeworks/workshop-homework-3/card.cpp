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
#include "card.hpp"

Card::Card(const std::string &card_name, const std::string &card_effect) {
    this->card_name = card_name;
    this->card_effect = card_effect;
}

void Card::set_card_name(const std::string &card_name) {
    this->card_name = card_name;
}

void Card::set_card_effect(const std::string &card_effect) {
    this->card_effect = card_effect;
}

std::string Card::get_card_name() const {
    return this->card_name;
}

std::string Card::get_card_effect() const {
    return this->card_effect;
}

std::string Card::card_to_string() const {
    return this->card_name + "|" + this->card_effect;
}
