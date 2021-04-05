#pragma once
#ifndef __PAIR_HPP__
#define __PAIR_HPP__

template<typename T, typename S>
class Pair {
public:
	Pair() {
		this->key = T();
		this->value = S();
	}

	Pair(const T& key, const S& value) {
		this->key = key;
		this->value = value;
	}

	T get_key() const {
		return this->key;
	}

	S get_value() const {
		return this->value;
	}

	void set_pair(const T& key, const S& value) {
		this->key = key;
		this->value = value;
	}

	bool operator==(const Pair& other) const {
		return this->key == other.key 
			&& this->value == other.value;
	}

	bool operator!=(const Pair& other) const {
		return !(*this == other);
	}

private:
	T key;
	S value;
};

#endif // !__PAIR_HPP__
