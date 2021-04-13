#pragma once
#ifndef __ARMOR_HPP__
#define __ARMOR_HPP__

#include <map>
#include <string>
#include <algorithm>

enum class ArmorType {
	cloth,
	leather,
	mail
};

class Armor {
public:
	Armor();
	Armor(const unsigned int& deffense, const ArmorType& armor_type);
	unsigned int get_gear_score() const;
	Armor& add_effect(std::pair<std::string, unsigned int>& new_effect);
	Armor& remove_effect(std::string& effect_name);
	Armor& change_effect_power(std::string& effect_name,
		const unsigned int& new_effect_power);

private:
	unsigned int deffense;
	std::map<std::string, unsigned int> effects;
	unsigned int gear_score;
	ArmorType armor_type;

	unsigned int calculate_gear_score() const;
	std::string to_lower(const std::string& string_to_convert);
};

#endif // !__ARMOR_HPP__