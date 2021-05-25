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
*/#include "Card.hpp"

Card::Card(const std::string& card_name, const std::string& card_effect,
           unsigned int card_rarity) {

    this->card_name = card_name;
    this->card_effect = card_effect;
    this->card_rarity = card_rarity;
}

void Card::set_card_name(const std::string& new_card_name) {
    this->card_name = new_card_name;
}

void Card::set_card_effect(const std::string& new_card_effect) {
    this->card_effect = new_card_effect;
}

void Card::set_card_rarity(unsigned int new_card_rarity) {
    this->card_rarity = new_card_rarity;
}

std::string Card::get_card_name() const {
    return this->card_name;
}

std::string Card::get_card_effect() const {
    return this->card_effect;
}

unsigned int Card::get_card_rarity() const {
    return this->card_rarity;
}

bool Card::operator>(const Card &other) const {
    return this->card_rarity > other.card_rarity;
}

bool Card::operator<(const Card &other) const {
    return !(*this > other);
}