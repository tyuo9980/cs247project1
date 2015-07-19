#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <map>
#include <string>
#include "Subject.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Deck.h"
#include "Table.h"
#include "Player.h"

using namespace std;

const int NUMBER_PLAYERS = 4;               //max number of players
const string ranks[RANK_COUNT] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" }; //maps card rank
const string suits = "CDHS";                //maps card suit

class Model : public Subject{
public:
    Model();                                //constructor
	~Model();                               //destructor
    int getPlayerID();                      //player id accessor
    bool* getClubs();                       //list of clubs played accessor
    bool* getDiamonds();                    //list of diamonds played accessor
    bool* getHearts();                      //list of hearts played accessor
    bool* getSpades();                      //list of spades played accessor
    int getOldScore(int);                   //old score accessor
    int getScoreGained(int);                //current score accessor
    bool isHuman(int);                      //check if player is human
    vector<Card*> getPlayerHand();          //get current player's hand accessor
    vector<Card*> getPlayerLegalPlays();    //get current player's legal plays accessor
    vector<Card*> getPlayerDiscards(int);   //get current player's discarded cards accessor
    vector<int> getWinners();               //returns list of winners
    bool isGameOver();                      //check game state for round/game end
    bool isLegalPlay(Card);                 //check if card is a legal play
    bool hasLegalPlays();                   //check if current player has legal plays
    void quit();                            //quit game
    void rageQuit(int);                     //replace human player with computer player
    void newGame(int, char[]);              //starts new game
    void cardAction(int);                   //decides whether to play or discard a card
    
private:
    void shuffle();                         //shuffle deck
    void deal();                            //deal cards
    void addHuman(int);                     //add human player to game
    void addComputer(int);                  //add computer player to game
    void findStarter();                     //find starting player
    void computerPlayCard();                //play card for computer players
    void computerDiscardCard();             //discard card for computer players
    void resetRound();                      //resets round - clears table, reshuffle deck, redeal cards
    void resetGame();                       //resets game - resets round and players
    bool isHuman();                         //check if current player is human
    vector<Card*> getDeck();                //deck accessor
    void checkPlayer();                     //keeps track of current player
    void setSeed(int);                      //seed setter function for shuffle
    void playCard(Card);                    //plays a given card
    void discardCard(Card);                 //discards a certain card
    void incrementPlayer();                 //changes game state, updates current player
    void checkGameOver();                   //checks if game/round is over

	Table* table_;                          //table data member
    Deck* deck_;                            //deck data member
	Player* players_[NUMBER_PLAYERS];       //list of players data member
	int currPlayer_;                        //current player data member
    bool inProgress_;                       //game is current in progress
	int validRank(string);                  //check if rank is in range
	int validSuit(char);                    //check if suit is valid
};


#endif