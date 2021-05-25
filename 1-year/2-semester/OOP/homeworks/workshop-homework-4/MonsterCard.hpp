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
#ifndef __MONSTER_CARD_HPP__
#define __MONSTER_CARD_HPP__

#include <string>
#include <vector>
#include "Card.hpp"

class MonsterCard : virtual public Card {
public:
    MonsterCard() = default;
    MonsterCard(const std::string& card_name, const std::string& card_effect,
                unsigned int card_rarity, unsigned int attack_points,
                unsigned int defence_points);

    void set_attack_points(unsigned int new_attack_points);
    void set_defence_points(unsigned int new_defence_points);

    unsigned int get_attack_points() const;
    unsigned int get_defence_points() const;

    std::string to_string() const override;
    CardType get_card_type() const override;

    friend std::ostream& operator<<(std::ostream& out, const MonsterCard& monster_card);
    friend std::istream& operator>>(std::istream& in, MonsterCard& monster_card);

protected:
    unsigned int attack_points;
    unsigned int defence_points;
};


#endif //__MONSTER_CARD_HPP__
