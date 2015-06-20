#include <vector>
#include "Player.h"
#include "Card.h"

using namespace std;

//constructor
Player::Player() : currScore_(0), oldScore_(0) {}

//Player::Player(const Player& player) : score_(player.getScore()), hand_(player.getHand()), discard_(player.getDiscard()){}
//copy constructor
Player::Player(int score, int oldScore, std::vector<Card*> hand, std::vector<Card*> discard) : hand_(hand), discard_(discard) {
	currScore_ = score;
	oldScore_ = oldScore;
}

//accessor for list of cards in hand
const vector<Card*>& Player::getHand() const{
	return hand_;
}

//current score accessor
int Player::getCurrScore() const{
	return currScore_;
}

//old score accessor
int Player::getOldScore() const {
	return oldScore_;
}

//accessor for list of discarded cards
const vector<Card*>& Player::getDiscard() const{
	return discard_;
}

//plays card
void Player::playCard(Card card) {
	vector<Card*>::const_iterator it = findCard(card);
	if (it != hand_.end()){
		hand_.erase(it);
        //delete *it;
		return;
	}
}

//discards card
void Player::discardCard(Card card) {
	vector<Card*>::const_iterator it = findCard(card);
	if (it != hand_.end()){
		discard_.push_back(*it);
		hand_.erase(it);
		currScore_ += (int)card.getRank() + 1;
	}
}

//find if card exists in hand
vector<Card*>::const_iterator Player::findCard(Card card) {
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

//add card to player's hand
void Player::addCards(Card* card){
	hand_.push_back(card);
}

//reset hand, score, and discard
void Player::resetPlayer() {
	oldScore_ = currScore_;
	currScore_ = 0;
	hand_.clear();
	discard_.clear();
}