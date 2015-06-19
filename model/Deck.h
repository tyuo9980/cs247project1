#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include "Card.h"
#include <random>
using namespace std;

class Deck {
	friend std::ostream &operator<<(std::ostream &sout, const Deck &deck);
public:
	Deck();
	~Deck();
	vector<Card*> getDeck() const;
	void shuffle();
	void setSeed(int);
	static const int CARD_COUNT = 52;
private:
	int seed_;
	vector<Card*> deck_;
};



#endif