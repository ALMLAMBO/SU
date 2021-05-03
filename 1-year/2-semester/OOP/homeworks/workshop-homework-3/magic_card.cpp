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
#include "magic_card.hpp"

MagicCard::MagicCard(const std::string &card_name, const std::string &card_effect,
                     const MagicCardType &card_type) : Card(card_name, card_effect) {

    this->card_type = card_type;
}

MagicCardType MagicCard::get_card_type() const {
    return this->card_type;
}

void MagicCard::set_card_type(const MagicCardType& card_type) {
    this->card_type = card_type;
}

std::string MagicCard::magic_card_to_string() const {
    return this->card_to_string() + "|" + this->get_card_type_to_string();
}

std::string MagicCard::get_card_type_to_string() const {
    std::string result;

    switch (this->card_type) {
        case MagicCardType::trap: result = "trap";break;
        case MagicCardType::buff: result = "buff";break;
        case MagicCardType::spell: result = "spell";break;
    }

    return result;
}

