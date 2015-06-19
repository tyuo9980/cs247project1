#include <vector>
#include "Player.h"
#include "Card.h"
using namespace std;


Player::Player() : currScore_(0), oldScore_(0) {}

//Player::Player(const Player& player) : score_(player.getScore()), hand_(player.getHand()), discard_(player.getDiscard()){}
Player::Player(int score, int oldScore, std::vector<Card*> hand, std::vector<Card*> discard) : hand_(hand), discard_(discard) {
	currScore_ = score;
	oldScore_ = oldScore;
}


const vector<Card*>&
Player::getHand() const{
	return hand_;
}

int Player::getCurrScore() const{
	return currScore_;
}
int Player::getOldScore() const {
	return oldScore_;
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
		currScore_ += (int)card.getRank() + 1;
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

void Player::addCards(Card* card){
	hand_.push_back(card);
}

void Player::resetPlayer() {
	oldScore_ = currScore_;
	currScore_ = 0;
	hand_.clear();
	discard_.clear();
}