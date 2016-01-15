#include <iostream>
#include <string>
#include "Deck.hpp"
using namespace std;

int main() {
	Deck deck(1);
	deck.shuffle();
	deck.printAllCards();
}