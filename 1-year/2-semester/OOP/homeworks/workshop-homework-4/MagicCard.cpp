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
#include "MagicCard.hpp"
#include "HelperFunctions.hpp"

MagicCard::MagicCard(const std::string& card_name, const std::string& card_effect,
                     unsigned int card_rarity, MagicCardType magic_card_type) :

                     Card(card_name, card_effect, card_rarity){

    this->magic_card_type = magic_card_type;
}

void MagicCard::set_magic_card_type(const MagicCardType& new_magic_card_type) {
    this->magic_card_type = new_magic_card_type;
}

MagicCardType MagicCard::get_magic_card_type() const {
    return this->magic_card_type;
}

std::string MagicCard::to_string() const {
    std::stringstream ss;

    ss << this->card_name << "|" << this->card_effect << "|"
        << HelperFunctions::card_type_to_string(this->magic_card_type);

    return ss.str();
}

CardType MagicCard::get_card_type() const {
    return CardType::magic;
}

std::ostream& operator<<(std::ostream& out, const MagicCard& magic_card) {
    out << magic_card.to_string();

    return out;
}

std::istream& operator>>(std::istream& in, MagicCard& magic_card) {
    std::string magic_card_as_string;
    std::getline(in, magic_card_as_string);

    std::vector<std::string> magic_card_data_as_string = HelperFunctions::
            split_string(magic_card_as_string, '|');

    magic_card = HelperFunctions::vector_to_magic_card(magic_card_data_as_string);

    return in;
}