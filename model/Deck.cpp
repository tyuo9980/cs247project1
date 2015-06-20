#include "Deck.h"

//constructor
Deck::Deck() {
	for (int i = 0; i < SUIT_COUNT; i++){
		for (int j = 0; j < RANK_COUNT; j++){
			deck_.push_back(new Card(static_cast<Suit>(i), static_cast<Rank>(j)));
		}
	}
}

//destructor
Deck::~Deck(){
    for (int i = 0; i < deck_.size(); i++){
        delete deck_.at(i);
    }
}

//shuffles deck
void Deck::shuffle(){
	static mt19937 rng(seed_);

	int n = CARD_COUNT;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card *c = deck_[n];
		deck_[n] = deck_[k];
		deck_[k] = c;
	}
}

//deck accessor
vector<Card*> Deck::getDeck() const{
	return deck_;
}

//ostream override - prints out deck
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

//seed setter
void Deck::setSeed(int s) {
	seed_ = s;
}