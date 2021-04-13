#pragma once
#ifndef __MATERIALS_HPP__
#define __MATERIALS_HPP__

#include <map>

enum class MaterialType {
	herbs,
	ores,
	cloth,
	essence
};

class Materials {
public:
	void add_material_quantity(const MaterialType& material_type,
		const unsigned int& quantity);

	unsigned int get_material_quantity(const MaterialType& material_type) const;
private:
	std::map<MaterialType, unsigned int> materials_quantity;
};

#endif //__MATERIALS_HPP__