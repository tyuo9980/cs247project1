#include "Deck.h"

Deck::Deck() {
	for (int i = 0; i < SUIT_COUNT; i++){
		for (int j = 0; j < RANK_COUNT; j++){
			deck_.push_back(new Card(static_cast<Suit>(i), static_cast<Rank>(j)));
		}
	}
}
Deck::~Deck(){
	for (vector<Card*>::const_iterator it = deck_.begin(); it != deck_.end(); ++it) {
		delete *it;
	}
}


void 
Deck::shuffle(){
	int seed = 0;
	static mt19937 rng(seed);

	int n = CARD_COUNT;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card *c = deck_[n];
		deck_[n] = deck_[k];
		deck_[k] = c;
	}
}

vector<Card*> Deck::getDeck() const{
	return deck_;
}

ostream &operator<<(std::ostream &sout, const Deck &deck) {
	int counter = 0;
	for (vector<Card*>::const_iterator it = deck.deck_.begin(); it != deck.deck_.end(); ++it) {
		sout << **it;
		if (counter < 12) {
			sout << " ";
			counter++;
		}
		else {
			sout << endl;
			counter = 0;
		}
	}
	return sout;
}