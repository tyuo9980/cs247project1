#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <map>
#include <string>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "subject.h"
#include "Deck.h"
#include "Table.h"
#include "Player.h"

using namespace std;

const int NUMBER_PLAYERS = 4;
const string ranks[RANK_COUNT] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const string suits[SUIT_COUNT] = { "C", "D", "H", "S" };

class Model {
public:
    Model();
	~Model();
	void shuffle();
	void deal();
	void addHuman(int);
	void addComputer(int);
	void findStarter();
	void quit();
	void rageQuit();
	int getPlayerID();
	bool playCard(string);
	bool discardCard(string);
	string computerPlayCard();
	string computerDiscardCard();
	bool* getClubs();
	bool* getDiamonds();
	bool* getHearts();
	bool* getSpades();
	bool isGameOver();
	bool isHuman();
	bool hasLegalPlays();
	vector<Card*> getPlayerHand();
	vector<Card*> getPlayerLegalPlays();
	vector<Card*> getDeck();
private:
	Table* table_;
    Deck* deck_;
	Player* players_[NUMBER_PLAYERS];
	int currPlayer_;
	vector<Card*> currHand_;
	int counter_;
	int validRank(char);
	int validSuit(char);
	bool isLegalPlay(Card);
};


#endif