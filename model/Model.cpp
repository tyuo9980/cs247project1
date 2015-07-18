#include <cassert>
#include <algorithm>
#include "Model.h"

using namespace std;

//constructor
Model::Model() : table_(new Table), deck_(new Deck){
	for (int i = 0; i < NUMBER_PLAYERS; i++) {
		players_[i] = NULL;
	}
}

//destructor
Model::~Model() {
	quit();
}

void Model::newGame(int seed, bool players[]) {
	quit();
	table_ = new Table();
	deck_ = new Deck();
	for (int i = 0; i < 4; i++){
        if (players[i] == true) addHuman(i);
        else addComputer(i);
    }
    // set seeds
	shuffle();
	deal();
	findStarter();
	notify();
}


//shuffle deck
void Model::shuffle() {
	deck_->shuffle();
}

//deal cards to players
void Model::deal() {
	for (int i = 0; i < deck_->CARD_COUNT; ++i) {
		players_[i / RANK_COUNT]->addCards(deck_->getDeck().at(i));
	}
}

//current player id accessor
int Model::getPlayerID() {
	return (currPlayer_ + 1);
}

//add human player to game
void Model::addHuman(int i) {
	HumanPlayer* player = new HumanPlayer();
	players_[i] = player;
}

//add computer player to game
void Model::addComputer(int i){
	ComputerPlayer* player = new ComputerPlayer();
	players_[i] = player;
}

//find starting player - searches for 7 of spades
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

//list of played clubs accessor
bool* Model::getClubs() {
	return table_->getClubs();
}

//list of played diamonds accessor
bool* Model::getDiamonds() {
	return table_->getDiamonds();
}

//list of played hearts accessor
bool* Model::getHearts() {
	return table_->getHearts();
}

//list of played spades accessor
bool* Model::getSpades() {
	return table_->getSpades();
}

//checks if the round is over
bool Model::isGameOver(){
    // check all cards are played
	for (int i = 0; i < NUMBER_PLAYERS; ++i) {
        if (players_[i]->getHand().size() != 0){
            return false;
        }
	}
    
    return true;
}

//resets the round - shuffles deck, deals cards, clears table
void Model::resetRound(){
    table_->resetTable();
    
    for (int i = 0; i < NUMBER_PLAYERS; ++i) {
        players_[i]->resetPlayer();
    }
    
    deck_->shuffle();
    deal();
    findStarter();
}

//returns list of winners - searches for lowest score
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

//current player's hand accessor
vector<Card*> Model::getPlayerHand() {
	return players_[currPlayer_]->getHand();
}

//finds list of current player's legal plays
vector<Card*> Model::getPlayerLegalPlays() {
	vector<Card> legalPlay = table_->currLegalPlays();
	vector<Card*> playerLegalPlay;
	for (vector<Card*>::const_iterator it = players_[currPlayer_]->getHand().begin(); it != players_[currPlayer_]->getHand().end(); ++it){
		if (std::find(legalPlay.begin(), legalPlay.end(), **it) != legalPlay.end()) {
			playerLegalPlay.push_back(*it);
		}
	} 
	return playerLegalPlay;
}

//checks if player is human
bool Model::isHuman() {
	return players_[currPlayer_]->isHuman();
}

//checks if rank is valid/within range
int Model::validRank(string rank) {
    for (int i = 0; i < RANK_COUNT; i++) {
        if (rank == ranks[i])
            return i;
    }
    return -1;
}

//checks if suit is valid
int Model::validSuit(char suit) {
    for (int i = 0; i < SUIT_COUNT; i++) {
        if (suit == suits[i])
            return i;
    }
    return -1;
}

//plays card for human player - removes card from hand and moves to table
bool Model::playCard(string card){
	if (!(card.length() == 2 || card.length() == 3)) return false;
	int rank = validRank(card.substr(0, card.length() - 1));
	int suit = validSuit(card[card.length() - 1]);

	if (rank == -1 || suit == -1) return false;

	Card cCard = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
	if (!isLegalPlay(cCard)) return false;
    
	players_[currPlayer_]->playCard(cCard);
	table_->playCard(cCard);
    notify();
	
	++currPlayer_;
	checkPlayer();
    return true;
}

//plays card for computer player - removes first card from hand and moves to table
string Model::computerPlayCard(){
	vector<Card*> legalPlays = getPlayerLegalPlays();
    Card* card = legalPlays.at(0);
    int rank = static_cast<int>(card->getRank());
    int suit = static_cast<int>(card->getSuit());
    
    players_[currPlayer_]->playCard(*card);
    table_->playCard(*card);
	
	++currPlayer_;
	checkPlayer();
    
    return ranks[rank] + suits[suit];
}

//checks if card is a legal play
bool Model::isLegalPlay(Card card) {
	vector<Card*> legalPlays = getPlayerLegalPlays();
	for (vector<Card*>::iterator it = legalPlays.begin(); it != legalPlays.end(); ++it) {
		if (**it == card) return true;
	}
	return false;
}

//checks if player has legal plays
bool Model::hasLegalPlays() {
	vector<Card*> legalPlays = getPlayerLegalPlays();
	return (legalPlays.size() != 0);
}

//discard card for human player - removes card from hand and moves it to the discarded pile
bool Model::discardCard(string card) {
    if (hasLegalPlays()) return false;
    if (!(card.length() == 2 || card.length() == 3)) return false;
	int rank = validRank(card.substr(0, card.length() - 1));
	int suit = validSuit(card[card.length() - 1]);

	if (rank == -1 || suit == -1) return false;

	Card cCard = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
	players_[currPlayer_]->discardCard(cCard);
    notify();

	++currPlayer_;
	checkPlayer();
    
    return true;
}

//discard card for computer player - removes first card from hand and moves it to the discarded pile
string Model::computerDiscardCard() {
	Card* card = players_[currPlayer_]->getHand().at(0);
	int rank = static_cast<int>(card->getRank());
	int suit = static_cast<int>(card->getSuit());
    players_[currPlayer_]->discardCard(*card);
    
    ++currPlayer_;
    checkPlayer();
    
	return ranks[rank] + suits[suit];
}

//deck accessor
vector<Card*> Model::getDeck() {
	return deck_->getDeck();
}

//quit game, removes pointers to players
void Model::quit() {
	delete table_;
	delete deck_;
	for (int i = 0; i < NUMBER_PLAYERS; ++i) {
		delete players_[i];
		players_[i] = NULL;
	}

	notify();
}

//ragequit - copies human player and creates a new computer player
void Model::rageQuit() {
	Player* formerPlayer = players_[currPlayer_];
	HumanPlayer* humanPlayer = dynamic_cast<HumanPlayer*>(formerPlayer);
	ComputerPlayer* newPlayer = new ComputerPlayer(*humanPlayer);
	delete formerPlayer;
	players_[currPlayer_] = newPlayer;
	notify();
}

//updates current player
void Model::checkPlayer() {
    currPlayer_ %= NUMBER_PLAYERS;
}

//seed setter
void Model::setSeed(int s){
	deck_->setSeed(s);
}

//current player's old score accessor
int Model::getOldScore(int player) {
	return players_[player - 1]->getOldScore();
}

//current player's current score accessor
int Model::getScoreGained(int player) {
	return players_[player - 1]->getCurrScore();
}

//returns current player's discarded cards
vector<Card*> Model::getPlayerDiscards(int player) {
	return players_[player - 1]->getDiscard();
}



