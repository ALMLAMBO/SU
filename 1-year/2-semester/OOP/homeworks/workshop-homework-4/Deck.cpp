/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alexander Marinov
* @idnumber 62622
* @task 1
* @compiler VC
*/
#include "Deck.hpp"
#include "HelperFunctions.hpp"

Deck::Deck(const std::string& deck_name) {
    this->deck_name = deck_name;
}

Deck::Deck(const Deck& from) {
    this->deck_name = from.deck_name;
    for(Card* card : from.cards) {
        this->add_card(card);
    }
}

Deck::~Deck() {
    for(Card* card : this->cards) {
        delete card;
    }
}

Deck &Deck::operator=(const Deck& from) {
    if(this != &from) {
        this->deck_name = from.deck_name;

        this->set_cards(from.cards);
    }

    return *this;
}

void Deck::set_deck_name(const std::string& new_deck_name) {
    this->deck_name = new_deck_name;
}

std::string Deck::get_deck_name() const {
    return this->deck_name;
}

void Deck::set_cards(const std::vector<Card *>& new_cards) {
    for(Card* card : this->cards) {
        delete card;
    }

    for(Card* card : new_cards) {
        this->add_card(card);
    }
}

std::vector<Card *> Deck::get_cards() const {
    return this->cards;
}

int Deck::get_cards_count() const {
    return this->cards.size();
}

int Deck::get_monster_cards_count() const {
    return std::count_if(
            this->cards.begin(),
            this->cards.end(),
            [](Card* card) {
                return card->get_card_type() == CardType::monster;
            });
}

int Deck::get_magic_cards_count() const {
    return std::count_if(
            this->cards.begin(),
            this->cards.end(),
            [](Card* card) {
                return card->get_card_type() == CardType::magic;
            });
}

int Deck::get_pendulum_cards_count() const {
    return std::count_if(
            this->cards.begin(),
            this->cards.end(),
            [](Card* card) {
                return card->get_card_type() == CardType::pendulum;
            });;
}

void Deck::add_card(Card *card) {
    if(card->get_card_type() == CardType::monster) {
        this->cards.push_back(new MonsterCard(
                *dynamic_cast<MonsterCard*>(card)));
    }
    else if(card->get_card_type() == CardType::magic) {
        this->cards.push_back(new MagicCard(
                *dynamic_cast<MagicCard*>(card)));
    }
    else if(card->get_card_type() == CardType::pendulum) {
        this->cards.push_back(new PendulumCard(
                *dynamic_cast<PendulumCard*>(card)));
    }
}

void Deck::change_card(unsigned int index, Card *card) {
    if(index < this->cards.size()) {
        if(this->cards[index]->get_card_type() == card->get_card_type()) {
            delete this->cards[index];
            if(card->get_card_type() == CardType::monster) {
                this->cards[index] = new MonsterCard(
                        *dynamic_cast<MonsterCard*>(card));
            }
            else if(card->get_card_type() == CardType::magic) {
                this->cards[index] = new MagicCard(
                        *dynamic_cast<MagicCard*>(card));
            }
            else if(card->get_card_type() == CardType::pendulum) {
                this->cards[index] = new PendulumCard(
                        *dynamic_cast<PendulumCard*>(card));
            }
        }
    }
}

void Deck::clear() {
    this->deck_name.clear();

    for(Card* card : this->cards) {
        delete card;
    }

    this->cards.clear();
}

void Deck::shuffle() {
    std::default_random_engine engine;

    std::shuffle(this->cards.begin(), this->cards.end(), engine);
}

std::string Deck::to_string() const {
    std::stringstream ss;

    ss << this->deck_name << "|"
        << this->get_cards_count() << "|"
        << this->get_monster_cards_count() << "|"
        << this->get_magic_cards_count() << "|"
        << this->get_pendulum_cards_count() << "\n";

    for(Card* card : this->cards) {
        if(card->get_card_type() == CardType::monster) {
            ss << card->to_string() << "\n";
        }
    }

    for(Card* card : this->cards) {
        if(card->get_card_type() == CardType::magic) {
            ss << card->to_string() << "\n";
        }
    }

    for(Card* card : this->cards) {
        if(card->get_card_type() == CardType::pendulum) {
            ss << card->to_string() << "\n";
        }
    }

    return ss.str();
}

bool Deck::operator==(const Deck& deck) const {
    return this->get_cards_count() == deck.get_cards_count();
}

std::ostream &operator<<(std::ostream& out, const Deck& deck) {
    out << deck.to_string();

    return out;
}

std::istream &operator>>(std::istream& in, Deck& deck) {
    deck.clear();

    std::string deck_info_as_string;

    std::getline(in, deck_info_as_string);
    std::vector<std::string> deck_info_data_as_string = HelperFunctions::split_string(
            deck_info_as_string, '|');

    deck.set_deck_name(deck_info_data_as_string[0]);
    unsigned int monster_cards_count = std::stoi(deck_info_data_as_string[2]);
    unsigned int magic_cards_count = std::stoi(deck_info_data_as_string[3]);
    unsigned int pendulum_cards_count = std::stoi(deck_info_data_as_string[4]);

    HelperFunctions::add_monster_cards(
            deck, in, monster_cards_count);

    HelperFunctions::add_magic_cards(
            deck, in, magic_cards_count);

    HelperFunctions::add_pendulum_cards(
            deck, in, pendulum_cards_count);

    return in;
}