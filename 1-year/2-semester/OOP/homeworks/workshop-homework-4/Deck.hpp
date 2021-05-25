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
#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <iterator>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"

class Deck {
public:
    Deck() = default;
    Deck(const std::string& deck_name);
    Deck(const Deck& from);
    ~Deck();
    Deck& operator=(const Deck& from);

    void set_deck_name(const std::string& new_deck_name);
    std::string get_deck_name() const;
    void set_cards(const std::vector<Card *>& new_cards);
    std::vector<Card *> get_cards() const;

    int get_cards_count() const;
    int get_monster_cards_count() const;
    int get_magic_cards_count() const;
    int get_pendulum_cards_count() const;

    void add_card(Card* card);
    void change_card(unsigned int index, Card* card);
    void clear();
    void shuffle();

    std::string to_string() const;
    bool operator==(const Deck& deck) const;

    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
    friend std::istream& operator>>(std::istream& in, Deck& deck);

private:
    std::string deck_name;
    std::vector<Card *> cards;
};

#endif //__DECK_HPP__