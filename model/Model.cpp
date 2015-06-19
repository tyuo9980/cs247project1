#include <cassert>
#include "Model.h"


Model::Model() : table_(new Table), deck_(new Deck){
	for (int i = 0; i < NUMBER_PLAYERS; i++) {
		players_[i] = NULL;
	}
}

Model::~Model() {
	quit();
}
void Model::shuffle() {
	deck_->shuffle();
}

void Model::deal() {
	for (int i = 0; i < deck_->CARD_COUNT; ++i) {
		players_[i / RANK_COUNT]->addCards(deck_->getDeck().at(i));
	}
}
int Model::getPlayerID() {
	return (currPlayer_ + 1);
}

void Model::addHuman(int i) {
	HumanPlayer* player = new HumanPlayer();
	players_[i-1] = player;
}
void Model::addComputer(int i){
	ComputerPlayer* player = new ComputerPlayer();
	players_[i-1] = player;
}
void Model::findStarter() {
	vector<Card*> currDeck = deck_->getDeck();
	Card starterCard = Card(SPADE, SEVEN);
	for (int i = 0; i < deck_->CARD_COUNT; ++i) {
		if (*currDeck.at(i) == starterCard) {
			currPlayer_ = i / RANK_COUNT;
			return;
		}
	}
}

bool* Model::getClubs() {
	return table_->getClubs();
}
bool* Model::getDiamonds() {
	return table_->getDiamonds();
}
bool* Model::getHearts() {
	return table_->getHearts();
}
bool* Model::getSpades() {
	return table_->getSpades();
}

bool Model::isGameOver(){
	for (int i = 0; i < NUMBER_PLAYERS; ++i) {
        if (players_[i]->getHand().size() != 0){
            return false;
        }
	}
    
	return true;
}

vector<int> Model::getWinners(){
    vector<int> winners;
    bool gameOver = false;
    int lowest = 9001;
    
    for (int i = 0; i < NUMBER_PLAYERS; ++i){
        int score = players_[i]->getCurrScore() + players_[i]->getOldScore();
        
        if (score < lowest){
            lowest = score;
        }
        
        if (score >= 80){
            gameOver = true;
        }
    }
    
    if (gameOver){
        for (int i = 0; i < NUMBER_PLAYERS; ++i){
            int score = players_[i]->getCurrScore() + players_[i]->getOldScore();
            
            if (score == lowest){
                winners.push_back(i + 1);
            }
        }
    }
    
    return winners;
}

vector<Card*> Model::getPlayerHand() {
	return players_[currPlayer_]->getHand();
}

vector<Card*> Model::getPlayerLegalPlays() {
	vector<Card> legalPlay = table_->currLegalPlays();
	vector<Card*> playerLegalPlay;
	for (vector<Card*>::const_iterator it = players_[currPlayer_]->getHand().begin(); it != players_[currPlayer_]->getHand().end(); ++it){
		if (find(legalPlay.begin(), legalPlay.end(), **it) != legalPlay.end()) {
			playerLegalPlay.push_back(*it);
		}
	} 
	return playerLegalPlay;
}

bool Model::isHuman() {
	return players_[currPlayer_]->isHuman();
}

bool Model::playCard(string card){
	if (card.length() != 2) return false;
	int rank = validRank(card[0]);
	int suit = validSuit(card[1]);

	if (rank == -1 || suit == -1) return false;

	Card cCard = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
	if (!isLegalPlay(cCard)) return false;
	players_[currPlayer_]->playCard(cCard);
	table_->playCard(cCard);
	++currPlayer_;
	checkPlayer();
    return true;
}

int Model::validRank(char rank) {
	for (int i = 0; i < RANK_COUNT; i++) {
		if (rank == ranks[i][0])
			return i;
	}
	return -1;
}
int Model::validSuit(char suit) {
	for (int i = 0; i < SUIT_COUNT; i++) {
		if (suit == suits[i])
			return i;
	}
	return -1;
}

string Model::computerPlayCard(){
	vector<Card*> legalPlays = getPlayerLegalPlays();
	if (legalPlays.size() != 0) {
		Card* card = legalPlays.at(0);
		int rank = static_cast<int>(card->getRank());
		int suit = static_cast<int>(card->getSuit());
		return ranks[rank] + suits[suit];
	}
	currPlayer_++;
	checkPlayer();
	return "";
}

bool Model::isLegalPlay(Card card) {
	vector<Card*> legalPlays = getPlayerLegalPlays();
	for (vector<Card*>::iterator it = legalPlays.begin(); it != legalPlays.end(); ++it) {
		if (**it == card) return true;
	}
	return false;
}

bool Model::hasLegalPlays() {
	vector<Card*> legalPlays = getPlayerLegalPlays();
	return (legalPlays.size() != 0);
}

bool Model::discardCard(string card){
	if (card.length() != 2) return false;
	int rank = validRank(card[0]);
	int suit = validSuit(card[1]);

	if (rank == -1 || suit == -1) return false;

	Card cCard = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
	
	players_[currPlayer_]->discardCard(cCard);
	++currPlayer_;
	checkPlayer();
    return true;
}

string Model::computerDiscardCard() {
	Card* card = players_[currPlayer_]->getHand().at(0);
	int rank = static_cast<int>(card->getRank());
	int suit = static_cast<int>(card->getSuit());
	return ranks[rank] + suits[suit];
}

vector<Card*> Model::getDeck() {
	return deck_->getDeck();
}

void Model::quit() {
	delete table_;
	delete deck_;
	for (int i = 0; i < NUMBER_PLAYERS; ++i)
		delete players_[i];

}

void Model::rageQuit() {
	Player* formerPlayer = players_[currPlayer_];
	HumanPlayer* humanPlayer = dynamic_cast<HumanPlayer*>(formerPlayer);
	ComputerPlayer* newPlayer = new ComputerPlayer(*humanPlayer);
	delete formerPlayer;
	delete humanPlayer;
	players_[currPlayer_] = newPlayer;

}

void Model::checkPlayer() {
	if (currPlayer_ > NUMBER_PLAYERS - 1)
		currPlayer_ = 0;
}

void Model::setSeed(int s){
	deck_->setSeed(s);
}

int Model::getOldScore(int player) {
	return players_[player - 1]->getOldScore();
}

int Model::getScoreGained(int player) {
	return players_[player - 1]->getCurrScore();
}

vector<Card*> Model::getPlayerDiscards(int player) {
	return players_[player - 1]->getDiscard();
}



