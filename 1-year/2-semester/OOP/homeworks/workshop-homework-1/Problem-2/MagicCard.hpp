#pragma once
#ifndef __MAGIC_CARD_HPP__
#define __MAGIC_CARD_HPP__

enum MagicCardType {
	trap,
	buff,
	spell
};

class MagicCard {
public:
	MagicCard();
	MagicCard(const char* name, const char* effect,
		const MagicCardType& type);

	MagicCard(const MagicCard& from);
	~MagicCard();
	MagicCard& operator=(const MagicCard& other); 

	void set_name(const char* new_name);
	void set_effect(const char* new_effect);
	void set_type(const MagicCardType& new_type);

	char* get_name() const;
	char* get_effect() const;
	MagicCardType get_type() const;

private:
	char* name;
	char* effect;
	MagicCardType type;

	void copy_magic_card(const MagicCard& other);
};

#endif // !__MAGIC_CARD_HPP__