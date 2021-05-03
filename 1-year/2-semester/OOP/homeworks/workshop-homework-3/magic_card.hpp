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
#ifndef __MAGIC_CARD_HPP__
#define __MAGIC_CARD_HPP__

#include <string>
#include "card.hpp"

enum class MagicCardType {
    trap,
    buff,
    spell
};

class MagicCard : virtual public Card {
public:
    MagicCard(const std::string &card_name = "", const std::string &card_effect = "",
              const MagicCardType& card_type = MagicCardType::trap);

    void set_card_type(const MagicCardType& card_type);
    MagicCardType get_card_type() const;

    std::string magic_card_to_string() const;

protected:
    MagicCardType card_type;

    std::string get_card_type_to_string() const;
};


#endif //__MAGIC_CARD_HPP__
