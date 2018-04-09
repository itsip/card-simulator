#include <string>
#ifndef CARD_H
#define CARD_H

class Card {
    private:
        static const int NUM_OF_RANKS = 13;
        static const int NUM_OF_SUITS = 4;

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

        const std::string ranks[NUM_OF_RANKS] = {
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

        const std::string suits[NUM_OF_SUITS] = {
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

        std::string getFullTitle() const {
            return ranks[rank] + " of " + suits[suit];
        }

        static int numOfRanks() { return NUM_OF_RANKS; }
        static int numOfSuits() { return NUM_OF_SUITS; }

        Card& operator= (Card const& original)
        {
            if (this == &original)
                return *this;

            rank = original.rank;
            suit = original.suit;

            return *this;
        }
};


bool operator< (Card const& lhs, Card const& rhs) {
    return lhs.getRank() < rhs.getRank();
}

bool operator> (Card const& lhs, Card const& rhs) { return rhs < lhs; }
bool operator<=(Card const& lhs, Card const& rhs) { return !(lhs > rhs); }
bool operator>=(Card const& lhs, Card const& rhs) { return !(lhs < rhs); }

bool operator==(Card const& lhs, Card const& rhs) {
    return lhs.getRank() == rhs.getRank();
}

bool operator!=(Card const& lhs, Card const& rhs) { return !(lhs == rhs); }

#endif // !CARD_H
