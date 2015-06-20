#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <map>
#include <string>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Deck.h"
#include "Table.h"
#include "Player.h"

using namespace std;

const int NUMBER_PLAYERS = 4;               //max number of players
const string ranks[RANK_COUNT] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" }; //maps card rank
const string suits = "CDHS";                //maps card suit

class Model {
public:
    Model();                                //constructor
	~Model();                               //destructor
	void shuffle();                         //shuffle deck
	void deal();                            //deal cards
	void addHuman(int);                     //add human player to game
	void addComputer(int);                  //add computer player to game
	void findStarter();                     //find starting player
	void quit();                            //quit game
	void rageQuit();                        //replace human player with computer player
	int getPlayerID();                      //player id accessor
	int getOldScore(int);                   //old score accessor
	int getScoreGained(int);                //current score accessor
	bool playCard(string);                  //play card for human players
	bool discardCard(string);               //discard card for human players
	string computerPlayCard();              //play card for computer players
	string computerDiscardCard();           //discard card for computer players
	bool* getClubs();                       //list of clubs played accessor
	bool* getDiamonds();                    //list of diamonds played accessor
	bool* getHearts();                      //list of hearts played accessor
	bool* getSpades();                      //list of spades played accessor
	bool isGameOver();                      //check game state for round/game end
    void resetRound();                      //resets round - clears table, reshuffle deck, redeal cards
	bool isHuman();                         //check if current player is human
	bool hasLegalPlays();                   //check if current player has legal plays
	vector<Card*> getPlayerHand();          //get current player's hand accessor
	vector<Card*> getPlayerLegalPlays();    //get current player's legal plays accessor
	vector<Card*> getPlayerDiscards(int);   //get current player's discarded cards accessor
	vector<Card*> getDeck();                //deck accessor
	void checkPlayer();                     //keeps track of current player
	void setSeed(int);                      //seed setter function for shuffle
    vector<int> getWinners();               //returns list of winners
private:
	Table* table_;                          //table data member
    Deck* deck_;                            //deck data member
	Player* players_[NUMBER_PLAYERS];       //list of players data member
	int currPlayer_;                        //current player data member
	int validRank(string);                  //check if rank is in range
	int validSuit(char);                    //check if suit is valid
	bool isLegalPlay(Card);                 //check if card is a legal play
};


#endif