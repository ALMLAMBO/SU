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
#ifndef __PENDULUM_CARD_HPP__
#define __PENDULUM_CARD_HPP__

#include <string>
#include <vector>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard {
public:
    PendulumCard() = default;
    PendulumCard(const std::string& card_name, const std::string& card_effect,
                 unsigned int card_rarity, unsigned int attack_points, unsigned int defence_points,
                 unsigned int pendulum_scale, const MagicCardType& magic_card_type);

    void set_pendulum_scale(unsigned int new_pendulum_scale);
    unsigned int get_pendulum_scale() const;

    std::string to_string() const override;
    CardType get_card_type() const override;

    friend std::ostream& operator<<(std::ostream& out, const PendulumCard& pendulum_card);
    friend std::istream& operator>>(std::istream& in, PendulumCard& pendulum_card);
private:
    unsigned int pendulum_scale;
};

#endif //__PENDULUM_CARD_HPP__