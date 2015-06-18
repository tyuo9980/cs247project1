#include <cassert>
#include <iostream>
#include <string>
#include "Table.h"
// if return true: the card is played and added on the tbale successfully
// return false: the suit of the card goes weird
Table::Table(){
	for (int i = 0; i < RANK_COUNT; i++) {
		clubs_[i] = false;
		diamonds_[i] = false;
		hearts_[i] = false;
		spades_[i] = false;
	}
}
bool
Table::playCard(Card* card) {
	Suit suit = card->getSuit();
	Rank rank = card->getRank();
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

void 
Table::print() const{
	string ranks[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	cout << "Clubs:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (clubs_[i])
			cout << " " << ranks[i];
	}
	cout<< endl<< "Diamonds:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (diamonds_[i])
			cout << " " << ranks[i];
	}
	cout << endl << "Hearts:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (hearts_[i])
			cout << " " << ranks[i];
	}
	cout << endl << "Spades:";
	for (int i = 0; i < RANK_COUNT; i++) {
		if (spades_[i])
			cout << " " << ranks[i];
	}
	cout << endl;
	string a;
	cin >> a;
}

