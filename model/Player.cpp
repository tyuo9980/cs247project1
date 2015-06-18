#include <vector>
#include "Player.h"
#include "Card.h"
using namespace std;


Player::Player() : score_(0) {}

//Player::Player(const Player& player) : score_(player.getScore()), hand_(player.getHand()), discard_(player.getDiscard()){}
Player::Player(int score, std::vector<Card*> hand, std::vector<Card*> discard) : hand_(hand), discard_(discard) {
	score_ = score;
}


const vector<Card*>&
Player::getHand() const{
	return hand_;
}

int Player::getScore() const{
	return score_;
}

void Player::dealtCard(vector<Card*> cards) {
	hand_.clear();
	discard_.clear();

	for (vector<Card*>::const_iterator it = cards.begin(); it != cards.end(); ++it){
		hand_.push_back(*it);
	}

}


const vector<Card*>& 
Player::getDiscard() const{
	return discard_;
}


void 
Player::playCard(Card card) {
	vector<Card*>::const_iterator it = findCard(card);
	if (it != hand_.end()){
		hand_.erase(it);
		return;
	}
}

void
Player::discardCard(Card card) {
	vector<Card*>::const_iterator it = findCard(card);
	if (it != hand_.end()){
		discard_.push_back(*it);
		hand_.erase(it);
		score_ += (int)card.getRank() + 1;
	}
}

vector<Card*>::const_iterator
Player::findCard(Card card) {
	for (vector<Card*>::const_iterator it = hand_.begin(); it != hand_.end(); ++it) {
		if (card == **it) {
			return it;
		}
	}
	return hand_.end();
}

//void 
//Player::setHand(std::vector<Card*>& hand) {
//	hand_ = hand;
//}
//
//void 
//Player::setDiscard(std::vector<Card*>& discard) {
//	discard_ = discard;
//}
//
//void 
//Player::setScore(int score){
//	score_ = score;
//}