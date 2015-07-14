#include "Controller.h"
#include "../model/Model.h"
#include "../model/Table.h"

//constructor
Controller::Controller(Model* m) : model_(m){}

//shuffle deck
void Controller::shuffle(){
    model_->shuffle();
}

//deal cards to players
void Controller::deal(){
    model_->deal();
}

//add player to list
void Controller::addPlayer(int i, char type){
    if (type == 'h'){
        model_->addHuman(i);
    }
    else{
        model_->addComputer(i);
    }
}

//find starting player
void Controller::findStarter(){
    model_->findStarter();
}

//return list of played clubs on table
bool* Controller::getPlayedClubs(){
    return model_->getClubs();
}

//return list of played diamonds on table
bool* Controller::getPlayedDiamonds(){
    return model_->getDiamonds();
}

//return list of played hearts on table
bool* Controller::getPlayedHearts(){
    return model_->getHearts();
}

//return list of played spades on table
bool* Controller::getPlayedSpades(){
    return model_->getSpades();
}

//check current state of game, includes reshuffling if needed
bool Controller::checkGameOver(){
    return model_->isGameOver();
}

//resets variables for new round
void Controller::resetRound(){
    model_->resetRound();
}

//return current player's hand
std::vector<Card*> Controller::getPlayerHand(){
    return model_->getPlayerHand();
}

//return player's discarded cards
std::vector<Card*> Controller::getPlayerDiscards(int player){
    return model_->getPlayerDiscards(player);
}

//return current player's legal moves
std::vector<Card*> Controller::getPlayerLegalPlays(){
    return model_->getPlayerLegalPlays();
}

//check if the player is human or computer
bool Controller::checkHumanPlayer(){
    return model_->isHuman();
}

//human - play a card
bool Controller::playCard(std::string card){
    return model_->playCard(card);
}

//computer - play a card
std::string Controller::playCard(){
    return model_->computerPlayCard();
}

//human - discard card
bool Controller::discardCard(std::string card){
	return model_->discardCard(card);
}

//computer - discard card
std::string Controller::discardCard(){
    return model_->computerDiscardCard();
}

//checks if legal plays exist
bool Controller::hasLegalPlay(){
    return model_->hasLegalPlays();
}

//returns player number
int Controller::getPlayerID(){
    return model_->getPlayerID();
}

//returns the list of cards in deck
std::vector<Card*> Controller::getDeck(){
    return model_->getDeck();
}

//quits game - deletes pointers
void Controller::quit(){
    model_->quit();
}

//ragequit - replace human with computer
void Controller::ragequit(){
    model_->rageQuit();
}

//returns score of previous round
int Controller::getOldScore(int player){
    return model_->getOldScore(player);
}

//returns score of current round
int Controller::getScoreGained(int player){
    return model_->getScoreGained(player);
}

//returns list of winners
std::vector<int> Controller::getWinners(){
    return model_->getWinners();
}



