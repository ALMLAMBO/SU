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
#include "Duelist.hpp"
#include "HelperFunctions.hpp"

Duelist::Duelist(const std::string& duelist_name, const Deck& deck) {
    this->duelist_name = duelist_name;
    this->deck = deck;
}

void Duelist::set_duelist_name(std::string& new_duelist_name) {
    this->duelist_name = new_duelist_name;
}

std::string Duelist::get_duelist_name() const {
    return this->duelist_name;
}

void Duelist::set_deck(const Deck& new_deck) {
    this->deck = new_deck;
}

Deck& Duelist::get_deck() {
    return this->deck;
}

bool Duelist::save_deck(const std::string &filename) {
    std::ofstream file_to_write(filename);

    if(file_to_write.is_open()) {
        file_to_write << this->deck;
    }
    else {
        return false;
    }

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
        unsigned int monster_cards_count = std::stoi(deck_info_data_as_string[2]);
        unsigned int magic_cards_count = std::stoi(deck_info_data_as_string[3]);
        unsigned int pendulum_cards_count = std::stoi(deck_info_data_as_string[4]);

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

void Duelist::duel(Duelist &opponent) {
    if(this->deck == opponent.deck) {
        this->deck.shuffle();
        opponent.deck.shuffle();

        int first_duelist_score = 0;
        int second_duelist_score = 0;

        for(int i = 0; i < this->deck.get_cards_count(); i++) {
            if(*this->deck.get_cards()[i] > *opponent.deck.get_cards()[i]) {
                first_duelist_score++;
            }
            else if(*this->deck.get_cards()[i] < *opponent.deck.get_cards()[i]) {
                second_duelist_score++;
            }
        }

        if(first_duelist_score > second_duelist_score) {
            std::cout << this->duelist_name << std::endl;
        }
        else if(first_duelist_score < second_duelist_score) {
            std::cout << opponent.duelist_name << std::endl;
        }
        else {
            std::cout << "Equal points" << std::endl;
        }
    }
}
