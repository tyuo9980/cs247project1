#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <set>
#include "Card.h"

using namespace std;

class Table {
	friend ostream &operator<<(std::ostream &sout, const Table &t);
public:
	Table();
	bool playCard(Card*);
	set<Card> currLegalPlays() const;
	//std::vector<std::vector<Card*>> playedCards();
private:
	// set everything to falses
	// nothing is on the table when game starts (i.e. table is instantiated)
	bool clubs_[RANK_COUNT];
	bool diamonds_[RANK_COUNT];
	bool hearts_[RANK_COUNT];
	bool spades_[RANK_COUNT];
};

#endif


