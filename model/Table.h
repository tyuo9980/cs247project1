#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>

#include "Card.h"

using namespace std;

class Table {
public:
	Table();
	bool playCard(Card*);
	//std::vector<std::vector<Card*>> playedCards();
	void print() const;
private:
	// set everything to falses
	// nothing is on the table when game starts (i.e. table is instantiated)
	bool clubs_[RANK_COUNT];
	bool diamonds_[RANK_COUNT];
	bool hearts_[RANK_COUNT];
	bool spades_[RANK_COUNT];
};

#endif


