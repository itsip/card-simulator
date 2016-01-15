#include <iostream>
#include <vector>
#include "Card.hpp"
#ifndef DECK_H
#define DECK_H

class Deck {
private:
	std::vector<Card> cards;
public:
	Deck() {
		for (int s = 0; s < Card::numOfSuits(); s++) {
			for (int r = 0; r < Card::numOfRanks(); r++) {
				cards.push_back(Card(r, s));
			}
		}
	}

	void printAllCards() {
		for (auto &card : cards) {
			std::cout << card.getFullTitle() << std::endl;
		}
	}
};

#endif // !DECK_H

