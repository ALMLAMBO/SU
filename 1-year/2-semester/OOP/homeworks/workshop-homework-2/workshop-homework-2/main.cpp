#include <iostream>
#include <vector>
#include <utility>
#include "Inventory.hpp"

using namespace std;

int main() {
	pair<unsigned int, unsigned int> hit_damage(100, 300);
	Weapon w(hit_damage, WeaponType::one_handed, "axe");

	pair<string, unsigned int> a("adds 100 damage", 100);
	w.add_effect(a);

	cout << w.get_weapon_score() << endl;

	//Inventory<Backpack<Materials>> inventory;
	Equipment<Weapon> weapons;
	weapons.add(w);
	weapons.remove();

	Inventory<Backpack<Money>> inventory;

	return 0;
}