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
#ifndef __DUELIST_HPP__
#define __DUELIST_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include "Deck.hpp"

class Duelist {
public:
    Duelist() = default;
    Duelist(const std::string& duelist_name, const Deck& deck = Deck());

    void set_duelist_name(std::string& new_duelist_name);
    std::string get_duelist_name() const;
    void set_deck(const Deck& new_deck);
    Deck& get_deck();

    bool save_deck(const std::string& filename);
    bool load_deck(const std::string& filename);

    void duel(Duelist& opponent);

private:
    std::string duelist_name;
    Deck deck;
};


#endif //__DUELIST_HPP__
