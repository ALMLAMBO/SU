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
#include "duelist.hpp"

Duelist::Duelist(const std::string &duelist_name, const Deck& deck) {
    this->duelist_name = duelist_name;
    this->deck = deck;
}

std::string Duelist::get_duelist_name() const {
    return this->duelist_name;
}

Duelist& Duelist::set_deck(const Deck& deck) {
    this->deck = deck;

    return *this;
}

Duelist& Duelist::set_duelist_name(const std::string &duelist_name) {
    this->duelist_name = duelist_name;

    return *this;
}

Deck& Duelist::get_deck() {
    return this->deck;
}

bool Duelist::save_deck(const std::string &filename) const {
    std::ofstream file_to_write(filename);

    if(file_to_write.is_open()) {
        file_to_write << this->deck.to_string();
    }
    else {
        return false;
    }

    file_to_write.close();

    return true;
}

bool Duelist::load_deck(const std::string &filename) {
    std::ifstream file_to_read(filename);

    if(file_to_read.is_open()) {
        this->deck.clear();

        Deck result_deck;
        std::string deck_info_as_string;

        std::getline(file_to_read, deck_info_as_string);
        std::vector<std::string> deck_info_data_as_string = HelperFunctions::split_string(
                deck_info_as_string, '|');

        this->deck.set_deck_name(deck_info_data_as_string[0]);
        unsigned int monster_cards_count = std::stoi(deck_info_data_as_string[1]);
        unsigned int magic_cards_count = std::stoi(deck_info_data_as_string[2]);
        unsigned int pendulum_cards_count = std::stoi(deck_info_data_as_string[3]);

        HelperFunctions::add_monster_cards(
                this->deck, file_to_read, monster_cards_count);

        HelperFunctions::add_magic_cards(
                this->deck, file_to_read, magic_cards_count);

        HelperFunctions::add_pendulum_cards(
                this->deck, file_to_read, pendulum_cards_count);
    }
    else {
        return false;
    }

    return true;
}
