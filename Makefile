cardsim:  main.o
	g++ -std=c++11 -o cardsim main.o
main.o:  src/main.cpp src/Card.hpp src/Deck.hpp
	g++ -std=c++11 -c src/main.cpp
clean:
	rm -f cardsim *.o
