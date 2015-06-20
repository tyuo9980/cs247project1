#ifndef _CARD_
#define _CARD_

#include <ostream>
#include <istream>

enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
			EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT };

class Card{
	friend std::istream &operator>>(std::istream &, Card &);

public:
	Card(Suit, Rank);                                       //constructor
	Suit getSuit() const;                                   //suit accessor
	Rank getRank() const;                                   //rank accessor
	
private:
	Suit suit_;                                             //suit member var
	Rank rank_;                                             //rank member var
};

bool operator==(const Card &, const Card &);                //equality override
bool operator> (const Card &, const Card &);                //greater than override
bool operator< (const Card &, const Card &);                //less than override
//output/input Card in the format <rank><suit>
std::ostream &operator<<(std::ostream &, const Card &);     //output card
std::istream &operator>>(std::istream &, Card &);           //input card

#endif
