#include "Card.h"
#include <string>
#include <cassert>

//constructor
Card::Card(Suit s, Rank r){
	suit_ = s;
	rank_ = r;
}

//suit accessor
Suit Card::getSuit() const{
	return suit_;
}

//rank accessor
Rank Card::getRank() const{
	return rank_;
}

std::string Card::getString() const{
    std::string suits[SUIT_COUNT] = {"C", "D", "H", "S"};
    std::string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "J", "Q", "K"};
    
    return ranks[getRank()] + suits[getSuit()];
};

//equality override
bool operator==(const Card &a, const Card &b){
	return a.getSuit() == b.getSuit() && a.getRank() == b.getRank();
}

//greater than override
bool operator> (const Card &a, const Card &b) {
	return a.getSuit() > b.getSuit() && a.getRank() > b.getRank();
}

//less than override
bool operator< (const Card &a, const Card &b) {
	return a.getSuit() < b.getSuit() && a.getRank() < b.getRank();
}

//output stream override - prints out card rank and suit
std::ostream &operator<<(std::ostream &out, const Card &c){
    std::string suits[SUIT_COUNT] = {"C", "D", "H", "S"};
    std::string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "J", "Q", "K"};
		
	out << ranks[c.getRank()] << suits[c.getSuit()];
	
	return out;
}

//input stream override - reads in a card
std::istream &operator>>(std::istream &in, Card &c){
	std::string suits = "CDHS", ranks = "A234567891JQK";
	
	std::string str;
	in >> str;
	assert ( !in.fail() );
	
	//Read in the rank, make sure it's valid
	c.rank_ = (Rank)ranks.find( str.at(0) );
	assert ( c.rank_ != std::string::npos );
	
	//If it's a 10, make sure the 2nd character is a 0
	if ( c.rank_ == TEN ){
		assert(str.at(1) == '0');
		str.at(1) = str.at(2);
	}
	
	//Read in the suit, make sure it's valid
	c.suit_ = (Suit)suits.find( str.at(1) );
	assert ( c.suit_ != std::string::npos );
	
	return in;
}


