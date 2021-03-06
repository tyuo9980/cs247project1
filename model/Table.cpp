#include <cassert>
#include <iostream>
#include <string>
#include "Table.h"
// if return true: the card is played and added on the tbale successfully
// return false: the suit of the card goes weird
//constructor
Table::Table(){
    resetTable();
}

//clears table - sets all played cards to false
void Table::resetTable(){
    for (int i = 0; i < RANK_COUNT; i++) {
        clubs_[i] = false;
        diamonds_[i] = false;
        hearts_[i] = false;
        spades_[i] = false;
    }
}

//play a card to the table
bool Table::playCard(Card card) {
	Suit suit = card.getSuit();
	Rank rank = card.getRank();
    
    //sets played card to true
	switch(suit) {
		case CLUB:
			assert (clubs_[rank] == false);
			clubs_[rank] = true;
			return true;
		case DIAMOND:
			assert(diamonds_[rank] == false);
			diamonds_[rank] = true;
			return true;
		case HEART:
			assert(hearts_[rank] == false);
			hearts_[rank] = true;
			return true;
		case SPADE:
			assert(spades_[rank] == false);
			spades_[rank] = true;
			return true;
		default:
			return false;
	}
}

//output override - prints cards on table
ostream &operator<<(std::ostream &sout, const Table &table) {
	string ranks[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	sout << "Clubs:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (table.clubs_[i])
			sout << " " << ranks[i];
	}
	sout << endl << "Diamonds:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (table.diamonds_[i])
			sout << " " << ranks[i];
	}
	sout << endl << "Hearts:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (table.hearts_[i])
			sout << " " << ranks[i];
	}
	sout << endl << "Spades:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (table.spades_[i])
			sout << " " << ranks[i];
	}
	sout << endl;
	return sout;
}

//finds current turn's legal plays based on cards on table
vector<Card> Table::currLegalPlays() const{
	vector<Card> legal;
    
	// if 7S is not yet played, then its the only legal play
	if (spades_[SEVEN] == false)  {
		legal.push_back(Card(SPADE, SEVEN));
		return legal;
	}

    //allows all other 7's
	if (clubs_[SEVEN] == false) 
		legal.push_back(Card(CLUB, SEVEN));
	if (diamonds_[SEVEN] == false) 
		legal.push_back(Card(DIAMOND, SEVEN));
	if (hearts_[SEVEN] == false) 
		legal.push_back(Card(HEART, SEVEN));

    //finds all adjacent cards
	for (int i = 0; i < RANK_COUNT; i++) {
		if (clubs_[i]) {
			if (i != RANK_COUNT - 1) legal.push_back(Card(CLUB, static_cast<Rank>(i + 1)));
			if (i != 0) legal.push_back(Card(CLUB, static_cast<Rank>(i - 1)));
		}
		if (diamonds_[i]) {
			if (i != RANK_COUNT - 1) legal.push_back(Card(DIAMOND, static_cast<Rank>(i + 1)));
			if (i != 0) legal.push_back(Card(DIAMOND, static_cast<Rank>(i - 1)));
		}
		if (hearts_[i]) {
			if (i != RANK_COUNT - 1) legal.push_back(Card(HEART, static_cast<Rank>(i + 1)));
			if (i != 0) legal.push_back(Card(HEART, static_cast<Rank>(i - 1)));
		}
		if (spades_[i]) {
			if (i != RANK_COUNT - 1) legal.push_back(Card(SPADE, static_cast<Rank>(i + 1)));
			if (i != 0) legal.push_back(Card(SPADE, static_cast<Rank>(i - 1)));
		}
	}
	return legal;
}

//accessor for played cards on table
bool* Table::getClubs() {
	return clubs_;
}
bool* Table::getDiamonds(){
	return diamonds_;
}
bool* Table::getHearts(){
	return hearts_;
}
bool* Table::getSpades(){
	return spades_;
}