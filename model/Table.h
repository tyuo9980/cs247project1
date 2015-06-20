#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <set>
#include "Card.h"

using namespace std;

class Table {
	friend ostream &operator<<(std::ostream &sout, const Table &t); //output stream override
public:
	Table();                                //constructor
	bool playCard(Card);                    //plays card to table
	bool* getClubs();                       //list of played clubs accessor
	bool* getDiamonds();                    //list of played diamonds accessor
	bool* getHearts();                      //list of played hearts accessor
	bool* getSpades();                      //list of played spades accessor
	vector<Card> currLegalPlays() const;    //returns list of legal plays
    void resetTable();                      //clears table
private:
	// set everything to falses
	// nothing is on the table when game starts (i.e. table is instantiated)
    // tracks played cards
	bool clubs_[RANK_COUNT];
	bool diamonds_[RANK_COUNT];
	bool hearts_[RANK_COUNT];
	bool spades_[RANK_COUNT];
};

#endif


