#include <iostream>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

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

	return 0;
}