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
#include <iostream>
#include "pendulum_card.hpp"
#include "deck.hpp"
#include "duelist.hpp"

using namespace std;

int main() {
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);

    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", MagicCardType::spell);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", MagicCardType::trap);

    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, MagicCardType::spell);

    Deck deck("Magician Deck");
    deck
        .add_monster_card(dragon)
        .add_monster_card(magician)
        .add_magic_card(swords)
        .add_magic_card(cylinder)
        .add_pendulum_card(timegazer);

    cout << deck.to_string() << endl;

    Duelist first_duelist("Ivan Ivanov", deck);

    cout << boolalpha << first_duelist.save_deck("deck.txt") << endl;
    first_duelist.load_deck("deck.txt");

    return 0;
}
