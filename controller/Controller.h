#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>

class Model;
class View;
class Card;

class Controller {
public:
    Controller(Model*);                         //constructor
    Controller(Model*, int);                    //constructor
    ~Controller();                              //destructor
    void shuffle();                             //shuffle deck
    void deal();                                //deal cards to players
    void addPlayer(int, std::string);           //add player to list
    void findStarter();                         //find starting player
    bool* getPlayedClubs();                     //return list of played clubs on table
    bool* getPlayedDiamonds();                  //return list of played diamonds on table
    bool* getPlayedHearts();                    //return list of played hearts on table
    bool* getPlayedSpades();                    //return list of played spades on table
    bool checkGameOver();                       //check current state of game, includes reshuffling if needed
    void resetRound();                          //resets variables for new round
    bool checkHumanPlayer();                    //check if the player is human or computer
    bool playCard(std::string);                 //human - play a card
    std::string playCard();                     //computer - play a card
    bool discardCard(std::string);              //human - discard card
    std::string discardCard();                  //computer - discard card
    bool hasLegalPlay();                        //checks if legal plays exist
    int getPlayerID();                          //returns player number
    std::vector<Card*> getDeck();               //returns list of cards in deck
    std::vector<Card*> getPlayerHand();         //return current player's hand
    std::vector<Card*> getPlayerDiscards(int);  //return player's discarded cards
    std::vector<Card*> getPlayerLegalPlays();   //return current player's legal moves
    void quit();                                //quits game - deletes pointers
    void ragequit();                            //replaces human with computer player
    int getOldScore(int);                       //returns score of previous round
    int getScoreGained(int);                    //returns score of current round
    std::vector<int> getWinners();              //returns list of winners
private:
    Model* model_;                              //access to model
};


#endif

