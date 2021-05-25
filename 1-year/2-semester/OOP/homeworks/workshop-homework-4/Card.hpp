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
#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <string>

enum class CardType {
    monster,
    magic,
    pendulum
};

class Card {
public:
    Card() = default;
    Card(const std::string& card_name, const std::string& card_effect,
         unsigned int card_rarity);

    virtual ~Card() = default;

    void set_card_name(const std::string& new_card_name);
    void set_card_effect(const std::string& new_card_effect);
    void set_card_rarity(unsigned int new_card_rarity);

    std::string get_card_name() const;
    std::string get_card_effect() const;
    unsigned int get_card_rarity() const;

    bool operator>(const Card& other) const;
    bool operator<(const Card& other) const;

    virtual std::string to_string() const = 0;
    virtual CardType get_card_type() const = 0;

protected:
    std::string card_name;
    std::string card_effect;
    unsigned int card_rarity;
};

#endif //__CARD_HPP__