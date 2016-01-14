#ifndef CARD_H
#define CARD_H

class Card {
public:
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
		king
	};
	std::string suits[] = {"hearts", "diamonds", "clubs", "spades"}
	
};

#endif // !CARD_H
