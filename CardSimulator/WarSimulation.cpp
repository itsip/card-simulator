#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <math.h>
#include "Deck.hpp"
using namespace std;

void playWar(Deck &hand1, Deck &hand2, Deck &warPot);

int main() {
	srand(time(0));
	vector<double> counts;
	int numOfGames;
	cout << "Number of simulations: ";
	cin >> numOfGames;
	cout << endl;

	for (int i = 0; i < numOfGames; i++) {
		double count = 0.0;
		Deck mainDeck(2);
		Deck hand1;
		Deck hand2;

		mainDeck.shuffle();
		while (mainDeck.getNumOfCards()) {
			hand1.addCard(mainDeck.takeTopCard());
			hand2.addCard(mainDeck.takeTopCard());
		}

		while (hand1.getNumOfCards() && hand2.getNumOfCards()) {
			count += 4.0;
			Deck warPot;
			playWar(hand1, hand2, warPot);
		}

		string winner = hand1.getNumOfCards() ? "Player 1" : "Player 2";

		counts.push_back(count);
		cout << "The winner: " << winner << endl;
		cout << "Game in seconds: " << count << endl;
		cout << endl;
	}
	double sum = std::accumulate(counts.begin(), counts.end(), 0.0);
	double mean = sum / counts.size();

	cout << "The average game time is " << round(mean) << endl;
}

void playWar(Deck &hand1, Deck &hand2, Deck &warPot) {
	Card hand1Play = hand1.takeTopCard();
	Card hand2Play = hand2.takeTopCard();

	if (hand1Play > hand2Play) {
		hand1.addCardToBottom(hand1Play);
		hand1.addCardToBottom(hand2Play);
		hand1.addDeckToBottom(warPot);
	}
	else if (hand1Play < hand2Play) {
		hand2.addCardToBottom(hand1Play);
		hand2.addCardToBottom(hand2Play);		
		hand2.addDeckToBottom(warPot);
	}
	else if (hand1Play == hand2Play) {
		warPot.addCardToBottom(hand1Play);
		warPot.addCardToBottom(hand2Play);
		if (hand1.getNumOfCards() > 3 && hand2.getNumOfCards() > 3) {
			for (int i = 0; i < 3; i++)
				warPot.addCardToBottom(hand1.takeTopCard());
			for (int i = 0; i < 3; i++)
				warPot.addCardToBottom(hand2.takeTopCard());
			playWar(hand1, hand2, warPot);
		}
		else if (hand1.getNumOfCards() <= 3) {
			for (int i = 0; i < hand1.getNumOfCards(); i++)
				warPot.addCardToBottom(hand1.takeTopCard());
			hand2.addDeckToBottom(warPot);
		}
		else if (hand2.getNumOfCards() <= 3) {
			for (int i = 0; i < hand2.getNumOfCards(); i++)
				warPot.addCardToBottom(hand2.takeTopCard());
			hand1.addDeckToBottom(warPot);
		}
	}
}