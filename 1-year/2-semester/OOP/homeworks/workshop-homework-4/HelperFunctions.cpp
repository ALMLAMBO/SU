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
#include "HelperFunctions.hpp"

std::vector<std::string> HelperFunctions::split_string(
        const std::string &string, char delimiter) {

    std::vector<std::string> split_string;
    std::stringstream ss(string);

    while(ss.good()) {
        std::string temp;
        std::getline(ss, temp, delimiter);
        split_string.push_back(temp);
    }

    return split_string;
}

MagicCardType HelperFunctions::string_to_card_type(const std::string &card_type_as_string) {
    MagicCardType card_type = MagicCardType::trap;

    if(card_type_as_string == "spell") {
        card_type = MagicCardType::spell;
    }
    else if(card_type_as_string == "trap") {
        card_type = MagicCardType::trap;
    }
    else if(card_type_as_string == "buff") {
        card_type = MagicCardType::buff;
    }

    return card_type;
}

void HelperFunctions::add_monster_cards(Deck &deck, std::istream &file_to_read,
                                        unsigned int monster_cards_count) {

    for(int i = 0; i < monster_cards_count; i++) {
        MonsterCard monster_card;
        file_to_read >> monster_card;

        deck.add_card(&monster_card);
    }
}

void HelperFunctions::add_magic_cards(Deck &deck, std::istream &file_to_read,
                                      unsigned int magic_cards_count) {

    for(int i = 0; i < magic_cards_count; i++) {
        MagicCard magic_card;
        file_to_read >> magic_card;

        deck.add_card(&magic_card);
    }
}

void HelperFunctions::add_pendulum_cards(Deck &deck, std::istream &file_to_read,
                                         unsigned int pendulum_cards_count) {

    for(int i = 0; i < pendulum_cards_count; i++) {
        PendulumCard pendulum_card;
        file_to_read >> pendulum_card;

        deck.add_card(&pendulum_card);
    }
}

MonsterCard HelperFunctions::vector_to_monster_card(std::vector<std::string> data) {
    MonsterCard monster_card;

    monster_card.set_card_name(data[0]);
    monster_card.set_card_effect(data[1]);
    monster_card.set_attack_points(std::stoi(data[2]));
    monster_card.set_defence_points(std::stoi(data[3]));

    return monster_card;
}

MagicCard HelperFunctions::vector_to_magic_card(std::vector<std::string> data) {
    MagicCard magic_card;

    magic_card.set_card_name(data[0]);
    magic_card.set_card_effect(data[1]);
    MagicCardType card_type = HelperFunctions::string_to_card_type(
            data[2]);

    magic_card.set_magic_card_type(card_type);

    return magic_card;
}

PendulumCard HelperFunctions::vector_to_pendulum_card(std::vector<std::string> data) {
    MonsterCard monster_card = HelperFunctions::vector_to_monster_card(data);
    PendulumCard pendulum_card;

    pendulum_card.set_card_name(monster_card.get_card_name());
    pendulum_card.set_card_effect(monster_card.get_card_effect());
    pendulum_card.set_attack_points(monster_card.get_attack_points());
    pendulum_card.set_defence_points(monster_card.get_defence_points());
    pendulum_card.set_pendulum_scale(std::stoi(data[4]));
    pendulum_card.set_magic_card_type(HelperFunctions::string_to_card_type(data[5]));

    return pendulum_card;
}

std::string HelperFunctions::card_type_to_string(const MagicCardType &magic_card_type) {
    std::string result;

    switch(magic_card_type) {
        case MagicCardType::spell: result = "spell"; break;
        case MagicCardType::buff: result = "buff"; break;
        case MagicCardType::trap: result = "trap"; break;
    }

    return result;
}
