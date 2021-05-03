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
#ifndef __DUELIST_HPP__
#define __DUELIST_HPP__

#include "deck.hpp"
#include "helper_functions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iterator>

class Duelist {
public:
    Duelist(const std::string& duelist_name = "", const Deck& deck = Deck());

    Duelist& set_deck(const Deck& deck);
    Duelist& set_duelist_name(const std::string &duelist_name);
    std::string get_duelist_name() const;

    Deck& get_deck();
    bool save_deck(const std::string& filename) const;
    bool load_deck(const std::string& filename);

private:
    std::string duelist_name;
    Deck deck;
};


#endif //__DUELIST_HPP__
