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
#include "deck.hpp"

Deck::Deck(const std::string& deck_name) {
    this->deck_name = deck_name;
}

std::string& Deck::get_deck_name() {
    return this->deck_name;
}

Deck& Deck::set_deck_name(const std::string &deck_name) {
    this->deck_name = deck_name;

    return *this;
}

unsigned int Deck::get_monster_cards_count() const {
    return this->monster_cards.size();
}

unsigned int Deck::get_magic_cards_count() const {
    return this->magic_cards.size();
}

unsigned int Deck::get_pendulum_cards_count() const {
    return this->pendulum_cards.size();
}

Deck &Deck::add_monster_card(const MonsterCard &monster_card) {
    this->monster_cards.push_back(monster_card);

    return *this;
}

Deck &Deck::add_magic_card(const MagicCard &magic_card) {
    this->magic_cards.push_back(magic_card);

    return *this;
}

Deck &Deck::add_pendulum_card(const PendulumCard &pendulum_card) {
    this->pendulum_cards.push_back(pendulum_card);

    return *this;
}

Deck &Deck::change_monster_card(const int &index, const MonsterCard &monster_card) {
    if(0 <= index && index < this->get_monster_cards_count()) {
        this->monster_cards[index] = monster_card;
    }

    return *this;
}

Deck &Deck::change_magic_card(const int &index, const MagicCard &magic_card) {
    if(0 <= index && index < this->get_magic_cards_count()) {
        this->magic_cards[index] = magic_card;
    }

    return *this;
}

Deck &Deck::change_pendulum_card(const int &index, const PendulumCard &pendulum_card) {
    if(0 <= index && index < this->get_pendulum_cards_count()) {
        this->pendulum_cards[index] = pendulum_card;
    }

    return *this;
}

Deck &Deck::clear() {
    this->monster_cards.clear();
    this->magic_cards.clear();
    this->pendulum_cards.clear();
    this->deck_name.clear();

    return *this;
}

std::string Deck::to_string() const {
    std::stringstream ss;

    ss << this->deck_name << "|" << this->get_monster_cards_count() << "|"
        << this->get_magic_cards_count() << "|" << this->get_pendulum_cards_count()
        << std::endl;

    ss << this->get_monster_cards_as_string();
    ss << this->get_magic_cards_as_string();
    ss << this->get_pendulum_cards_as_string();

    return ss.str();
}

std::string Deck::get_monster_cards_as_string() const {
    std::stringstream ss;

    for(const MonsterCard& monster_card : this->monster_cards) {
        ss << monster_card.monster_card_to_string() << std::endl;
    }

    return ss.str();
}

std::string Deck::get_magic_cards_as_string() const {
    std::stringstream ss;

    for(const MagicCard& magic_card : this->magic_cards) {
        ss << magic_card.magic_card_to_string() << std::endl;
    }

    return ss.str();
}

std::string Deck::get_pendulum_cards_as_string() const {
    std::stringstream ss;

    for(const PendulumCard& pendulum_card : this->pendulum_cards) {
        ss << pendulum_card.pendulum_card_to_string() << std::endl;
    }

    return ss.str();
}
