#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Deck.hpp"
using namespace std;

int main() {
	srand(time(0));

	Deck mainDeck(2);
	Deck hand1;
	Deck hand2;

	mainDeck.shuffle();
	while (mainDeck.getNumOfCards()) {
		hand1.addCard(mainDeck.takeTopCard());
		hand2.addCard(mainDeck.takeTopCard());
	}
}