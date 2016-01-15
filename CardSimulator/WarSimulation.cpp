#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Deck.hpp"
using namespace std;

int main() {
	srand(time(0));

	Deck mainDeck(1);
	Deck hand1;
	Deck hand2;

	mainDeck.shuffle();
	while (mainDeck.getNumOfCards()) {

	}
}