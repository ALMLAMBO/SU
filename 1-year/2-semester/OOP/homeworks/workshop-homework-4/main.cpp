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
#include <iostream>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Duelist.hpp"

using namespace std;

int main() {
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, MagicCardType::spell);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, MagicCardType::trap);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, MagicCardType::spell);

    Duelist first_duelist("Yugi Muto");
    first_duelist.get_deck().set_deck_name("Magician Deck");
    first_duelist.get_deck().add_card(&dragon);
    first_duelist.get_deck().add_card(&magician);
    first_duelist.get_deck().add_card(&swords);
    first_duelist.get_deck().add_card(&cylinder);
    first_duelist.get_deck().add_card(&timegazer);

    first_duelist.get_deck().shuffle();
    first_duelist.save_deck("magician_deck.txt");

    MagicCard box("Mystic Box", "Destroy one monster", 0, MagicCardType::spell);
    first_duelist.get_deck().change_card(1, &box);

    Duelist second_duelist("Seto Kaiba");
    second_duelist.get_deck().add_card(&dragon);
    second_duelist.get_deck().add_card(&magician);
    second_duelist.get_deck().add_card(&swords);
    second_duelist.get_deck().add_card(&cylinder);
    second_duelist.get_deck().add_card(&timegazer);

    first_duelist.duel(second_duelist);

    return 0;
}
