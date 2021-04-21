#include "Route.hpp"

Route::Route(const std::string& start, 
	const std::string& end) {

	this->start = start;
	this->end = end;
}

std::string Route::get_start() const {
	return this->start;
}

std::string Route::get_end() const {
	return this->end;
}