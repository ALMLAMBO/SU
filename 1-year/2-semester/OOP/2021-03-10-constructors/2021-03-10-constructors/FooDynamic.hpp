#pragma once
#ifndef __FOO_DYNAMIC_HPP__

class FooDynamic {
public:
	FooDynamic();
	FooDynamic(const FooDynamic& other);
	void set_value(const int new_value);
	int get_value() const;

private:
	int* value;
};

#endif // !__FOO_DYNAMIC_HPP__

