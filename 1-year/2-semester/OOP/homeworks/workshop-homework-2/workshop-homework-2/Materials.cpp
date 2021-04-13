#include "Materials.hpp"

void Materials::add_material_quantity(const MaterialType& material_type,
	const unsigned int& quantity) {

	if (this->materials_quantity.find(material_type) == 
		this->materials_quantity.end()) {

		this->materials_quantity.insert(
			std::pair< MaterialType, unsigned int>(
				material_type, quantity));
	}
	else {
		this->materials_quantity[material_type] += quantity;
	}
}

unsigned int Materials::get_material_quantity(
	const MaterialType& material_type) const {

	unsigned int quantity = 0;

	if (this->materials_quantity.find(material_type) ==
		this->materials_quantity.end()) {

		quantity = this->materials_quantity.at(material_type);
	}

	return quantity;
}