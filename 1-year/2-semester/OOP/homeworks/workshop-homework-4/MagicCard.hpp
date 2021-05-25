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
#ifndef __MAGIC_CARD_HPP__
#define __MAGIC_CARD_HPP__

#include <string>
#include <vector>
#include "Card.hpp"

enum class MagicCardType {
    spell,
    buff,
    trap
};

class MagicCard : virtual public Card {
public:
    MagicCard() = default;
    MagicCard(const std::string& card_name, const std::string& card_effect,
              unsigned int card_rarity, MagicCardType magic_card_type);

    void set_magic_card_type(const MagicCardType& new_magic_card_type);
    MagicCardType get_magic_card_type() const;

    std::string to_string() const override;
    CardType get_card_type() const override;

    friend std::ostream& operator<<(std::ostream& out, const MagicCard& magic_card);
    friend std::istream& operator>>(std::istream& in, MagicCard& magic_card);

protected:
    MagicCardType magic_card_type;
};


#endif //__MAGIC_CARD_HPP__
