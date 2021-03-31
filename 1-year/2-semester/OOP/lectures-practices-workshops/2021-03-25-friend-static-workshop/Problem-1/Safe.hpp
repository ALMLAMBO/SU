#pragma once
#ifndef __SAFE_HPP__
#define __SAFE_HPP__

#include "Hacker.hpp"

class Safe {
public:
	Safe();
	
	friend void generate_number(Safe& safe);
	friend class Hacker;

private:
	int number;
};

#endif // !__SAFE_HPP__
