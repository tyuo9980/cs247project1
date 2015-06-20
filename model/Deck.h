#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include "Card.h"
#include <random>
using namespace std;

class Deck {
	friend std::ostream &operator<<(std::ostream &sout, const Deck &deck);  //prints deck - ostream override
public:
	Deck();                             //constructor
	~Deck();                            //destructor
	vector<Card*> getDeck() const;      //deck accessor
	void shuffle();                     //shuffles deck
	void setSeed(int);                  //seed setter
	static const int CARD_COUNT = 52;   //const - number of cards
private:
	int seed_;                          //seed member var
	vector<Card*> deck_;                //list of cards
};



#endif