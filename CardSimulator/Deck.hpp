#include <iostream>
#include <vector>
#include <algorithm>
#include "Card.hpp"
#ifndef DECK_H
#define DECK_H

class Deck {
private:
	std::vector<Card> cards;
public:
	Deck() {}

	Deck(int numOfDecks) {
		for (int i = 0; i < numOfDecks; i++)
			for (int s = 0; s < Card::numOfSuits(); s++)
				for (int r = 0; r < Card::numOfRanks(); r++)
					cards.push_back(Card(r, s));
	}

	void addCard(Card const& card) {
		cards.push_back(card);
	}

	Card takeTopCard() {
		Card topCard = cards[0];
		cards.erase(cards.begin());
		return topCard;
	}

	void shuffle() {
		std::random_shuffle(cards.begin(), cards.end());
	}

	int const getNumOfCards() {
		return cards.size();
	}

	void printAllCards() const {
		for (auto &card : cards)
			std::cout << card.getFullTitle() << std::endl;
	}
};

#endif // !DECK_H