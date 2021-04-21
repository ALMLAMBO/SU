#pragma once
#ifndef __TRANSPORT_HPP__
#define __TRANSPORT_HPP__

#include "Vehicle.hpp"
#include <string>

//virtual because of diamond problem
class Transport : virtual public Vehicle {
public:


private:
	std::string license_id;
	int max_allowed_passengers;
};

#endif // !__TRANSPORT_HPP__