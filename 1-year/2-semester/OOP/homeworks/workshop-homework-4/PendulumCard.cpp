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
#include "PendulumCard.hpp"
#include "HelperFunctions.hpp"

PendulumCard::PendulumCard(const std::string& card_name, const std::string& card_effect, unsigned int card_rarity,
                           unsigned int attack_points, unsigned int defence_points, unsigned int pendulum_scale,
                           const MagicCardType& magic_card_type) : Card(card_name, card_effect, card_rarity) {

    this->attack_points = attack_points;
    this->defence_points = defence_points;
    this->set_pendulum_scale(pendulum_scale);
    this->magic_card_type = magic_card_type;
}

void PendulumCard::set_pendulum_scale(unsigned int new_pendulum_scale) {
    if(new_pendulum_scale >= 1 && new_pendulum_scale <= 13) {
        this->pendulum_scale = new_pendulum_scale;
    }
}

unsigned int PendulumCard::get_pendulum_scale() const {
    return this->pendulum_scale;
}

std::string PendulumCard::to_string() const {
    std::stringstream ss;

    ss << MonsterCard::to_string() << "|"
        << this->pendulum_scale << "|"
        << HelperFunctions::card_type_to_string(this->magic_card_type);

    return ss.str();
}

CardType PendulumCard::get_card_type() const {
    return CardType::pendulum;
}

std::ostream& operator<<(std::ostream& out, const PendulumCard& pendulum_card) {
    out << pendulum_card.to_string();

    return out;
}

std::istream& operator>>(std::istream& in, PendulumCard& pendulum_card) {
    std::string pendulum_card_as_string;
    std::getline(in, pendulum_card_as_string);

    std::vector<std::string> pendulum_card_data_as_string = HelperFunctions::
            split_string(pendulum_card_as_string, '|');

    pendulum_card = HelperFunctions::vector_to_pendulum_card(pendulum_card_data_as_string);

    return in;
}
