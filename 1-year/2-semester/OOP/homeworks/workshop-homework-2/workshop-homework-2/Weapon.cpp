#include "Weapon.hpp"

Weapon::Weapon() {
	this->weapon_score = 0;
	this->weapon_type = WeaponType::one_handed;
	this->weapon_kind = "";
}

Weapon::Weapon(const std::pair<unsigned int, unsigned int>& hit_damage,
	const WeaponType& weapon_type,
	const std::string& weapon_kind) {

	this->hit_damage = hit_damage;
	this->weapon_score = 0;
	this->weapon_kind = this->to_lower(weapon_kind);
	this->weapon_type = weapon_type;
}

Weapon& Weapon::change_kind(std::string& new_kind) {
	new_kind = this->to_lower(new_kind);
	
	if (new_kind == "staff") {
		this->weapon_type = WeaponType::two_handed;
		this->weapon_score = this->calculate_weapon_score();
	}
	else if (new_kind == "dagger") {
		this->weapon_type = WeaponType::one_handed;
		this->weapon_score = this->calculate_weapon_score();
	}

	this->weapon_kind = new_kind;
	return *this;
}

Weapon& Weapon::change_type(const WeaponType& new_type) {
	if (this->weapon_kind != "staff" && this->weapon_kind != "dagger") {
		this->weapon_type = new_type;
		this->weapon_score = this->calculate_weapon_score();
	}

	return *this;
}

Weapon& Weapon::add_effect(std::pair<std::string, unsigned int>& new_effect) {
	new_effect.first = this->to_lower(new_effect.first);
	
	this->effects.insert(new_effect);
	this->weapon_score = this->calculate_weapon_score();

	return *this;
}

Weapon& Weapon::remove_effect(std::string& effect_name) {
	effect_name = this->to_lower(effect_name);

	if (this->effects.find(effect_name) != this->effects.end()) {
		this->effects.erase(effect_name);
	}

	return *this;
}

Weapon& Weapon::change_effect_power(std::string& effect_name,
	const unsigned int& new_effect_power) {
	
	effect_name = this->to_lower(effect_name);

	if (this->effects.find(effect_name) != this->effects.end()) {
		this->effects[effect_name] = new_effect_power;

		this->weapon_score = this->calculate_weapon_score();
	}

	return *this;
}

double Weapon::get_weapon_score() const {
	return this->weapon_score;
}

int Weapon::get_slots() const {
	return this->weapon_type == WeaponType::one_handed ? 1 : 2;
}

double Weapon::calculate_weapon_score() const {
	double score = (this->hit_damage.first + this->hit_damage.second) / 2;
	
	for (std::pair<std::string, unsigned int> pair : this->effects) {
		score += pair.second;
	}

	double multiplier = 0;

	if (this->weapon_type == WeaponType::one_handed) {
		multiplier = 0.75;
	}
	else if (this->weapon_type == WeaponType::two_handed) {
		multiplier = 1.5;
	}

	score *= multiplier;

	return score;
}

std::string Weapon::to_lower(const std::string& string_to_convert) {
	std::string result = "";
	
	for (int i = 0; i < string_to_convert.size(); i++) {
		result += std::tolower(string_to_convert[i]);
	}

 	return result;
}