#include "Armor.hpp"

Armor::Armor() : deffense(0), gear_score(0) {
	this->armor_type = ArmorType::cloth;
}

Armor::Armor(const unsigned int& deffense, const ArmorType& armor_type) {
	this->deffense = deffense;
	this->armor_type = armor_type;
	this->gear_score = 0;
}

unsigned int Armor::get_gear_score() const {
	return this->calculate_gear_score();
}

Armor& Armor::add_effect(std::pair<std::string, unsigned int>& new_effect) {
	new_effect.first = this->to_lower(new_effect.first);

	this->effects.insert(new_effect);
	this->gear_score = this->calculate_gear_score();

	return *this;
}

Armor& Armor::remove_effect(std::string& effect_name) {
	effect_name = this->to_lower(effect_name);

	if (this->effects.find(effect_name) != this->effects.end()) {
		this->effects.erase(effect_name);
	}

	return *this;
}

Armor& Armor::change_effect_power(std::string& effect_name,
	const unsigned int& new_effect_power) {

	effect_name = this->to_lower(effect_name);

	if (this->effects.find(effect_name) != this->effects.end()) {
		this->effects[effect_name] = new_effect_power;

		this->gear_score = this->calculate_gear_score();
	}

	return *this;
}

unsigned int Armor::calculate_gear_score() const {
	unsigned int score = 0;

	for (std::pair<std::string, unsigned int> pair : this->effects) {
		score += pair.second;
	}

	return score;
}

std::string Armor::to_lower(const std::string& string_to_convert) {
	std::string result = "";

	std::transform(string_to_convert.begin(), string_to_convert.end(),
		result.begin(),
		[](char c) {
			return std::tolower(c);
		});

	return result;
}