#include <iostream>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"

using namespace std;

int main() {
	MonsterCard c1("Card 1", 2000, 2000);
	cout << c1.get_name() << endl;
	cout << c1.get_attack_points() << endl;
	cout << c1.get_defense_points() << endl;

	cout << endl;

	c1.set_name("jfkals;dfjewoifl;ksdafh;asdfhlasfsagagdg");
	c1.set_attack_points(3000);
	c1.set_defense_points(1000);
	cout << c1.get_name() << endl;
	cout << c1.get_attack_points() << endl;
	cout << c1.get_defense_points() << endl << endl << endl;

	MagicCard m1("Dark soul", "adds 100pts", MagicCardType::spell);
	cout << m1.get_name() << endl;
	cout << m1.get_effect() << endl;
	cout << m1.get_type() << endl;

	m1.set_effect("dfoi;asjlkfrtoiew;lkfsdogihajkd;gasdoifhlskdfglgkhlasfasdiufoda;aewhriow;flkashfsda;fhdfasdoifk;dsfislk;v,chdsfasjk;fl");
	cout << m1.get_effect() << endl;

	Deck d;
	for (int i = 0; i < 20; i++) {
		d.add_magic_card(m1);
		d.add_monster_card(c1);
	}

	cout << d.get_magic_cards_count() << endl;
	cout << d.get_monster_cards_count() << endl;

	d.add_magic_card(m1);
	d.add_monster_card(c1);

	Deck d2;
	d2.change_magic_card(5, "AAA", "AAA", MagicCardType::trap);
	cout << d2.get_magic_cards_count() << endl;

	Duelist player1("Yugi Muto");
	player1.change_monster_card_in_deck(2, c1);
	player1.change_magic_card_in_deck(0, m1);


	return 0;
}