#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <map>
#include <string>
#include <algorithm>

enum class WeaponType {
	one_handed,
	two_handed
};

class Weapon {
public:
	Weapon();
	Weapon(const std::pair<unsigned int, unsigned int>& hit_damage,
		const WeaponType& weapon_type, 
		const std::string& weapon_kind);

	Weapon& change_kind(std::string& new_kind);
	Weapon& change_type(const WeaponType& new_type);
	Weapon& add_effect(std::pair<std::string, unsigned int>& new_effect);
	Weapon& remove_effect(std::string& effect_name);
	Weapon& change_effect_power(std::string& effect_name,
		const unsigned int& new_effect_power);

	double get_weapon_score() const;
	int get_slots() const;

private:
	std::pair<unsigned int, unsigned int> hit_damage;
	double weapon_score;
	std::map<std::string, unsigned int> effects;
	WeaponType weapon_type;
	std::string weapon_kind;

	double calculate_weapon_score() const;
	std::string to_lower(const std::string& string_to_convert);
};

#endif //__WEAPON_HPP__