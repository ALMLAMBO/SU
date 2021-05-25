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
#include "MonsterCard.hpp"
#include "HelperFunctions.hpp"

MonsterCard::MonsterCard(const std::string &card_name, const std::string &card_effect,
                         unsigned int card_rarity,unsigned int attack_points,
                         unsigned int defence_points) :

                         Card(card_name, card_effect, card_rarity) {

    this->attack_points = attack_points;
    this->defence_points = defence_points;
}

void MonsterCard::set_attack_points(unsigned int new_attack_points) {
    this->attack_points = new_attack_points;
}

void MonsterCard::set_defence_points(unsigned int new_defence_points) {
    this->defence_points = new_defence_points;
}

unsigned int MonsterCard::get_attack_points() const {
    return this->attack_points;
}

unsigned int MonsterCard::get_defence_points() const {
    return this->defence_points;
}

std::string MonsterCard::to_string() const {
    std::stringstream ss;

    ss << this->card_name << "|" << this->card_effect << "|"
        << this->card_rarity << "|"
        << this->attack_points << "|" << this->defence_points;

    return ss.str();
}

CardType MonsterCard::get_card_type() const {
    return CardType::monster;
}

std::ostream& operator<<(std::ostream& out, const MonsterCard& monster_card) {
    out << monster_card.to_string();

    return out;
}

std::istream& operator>>(std::istream& in, MonsterCard& monster_card) {
    std::string monster_card_as_string;
    std::getline(in, monster_card_as_string);
    std::vector<std::string> monster_card_data_as_string = HelperFunctions::
            split_string(monster_card_as_string, '|');

    monster_card = HelperFunctions::vector_to_monster_card(monster_card_data_as_string);

    return in;
}
