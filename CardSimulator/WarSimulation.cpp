#include <iostream>
#include <string>
#include "Card.hpp"
using namespace std;

int main() {
	Card twoOfHearts(1, 3);
	cout << twoOfHearts.getStringRank() << " of " << twoOfHearts.getStringSuit() << endl;
}