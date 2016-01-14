#include <string>
#ifndef CARD_H
#define CARD_H

class Card {
private:
	enum Rank {
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		ace
	};
	enum Suit {
		hearts,
		diamonds,
		clubs,
		spades
	};
	std::string ranks[13] = {
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten",
		"Jack",
		"Queen",
		"King",
		"Ace"
	};
	std::string suits[4] = {
		"Hearts",
		"Diamonds",
		"Clubs",
		"Spades"
	};

	Rank rank;
	Suit suit;
public:
	Card(int const& r, int const& s) : rank(Rank(r)), suit(Suit(s)) {}

	Rank getRank() const { return rank; }
	Suit getSuit() const { return suit; }

	std::string getStringRank() const { return ranks[rank]; }
	std::string getStringSuit() const { return suits[suit]; }
};

#endif // !CARD_H