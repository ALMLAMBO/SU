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
#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <string>

class Card {
public:
    Card(const std::string &card_name = "", const std::string &card_effect = "");

    void set_card_name(const std::string &card_name);
    void set_card_effect(const std::string &card_name);

    std::string get_card_name() const;
    std::string get_card_effect() const;

protected:
    std::string card_name;
    std::string card_effect;

    std::string card_to_string() const;
};

#endif //__CARD_HPP__