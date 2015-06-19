#include "Controller.h"
#include "../model/Model.h"
#include "../model/Table.h"

Controller::Controller(Model* m) : model_(m){

}

void Controller::shuffle(){
    model_->deck_->shuffle();
}

void Controller::deal(){

}

void addPlayer(std::string){

}

void findStarter(){

}

bool* getPlayedClubs(){
    return model_->getTable()->getClubs();
}

bool* getPlayedDiamonds(){
    return model_->getTable()->getDiamonds();
}

bool* getPlayedHearts(){
    return model_->getTable()->getHearts();
}

bool* getPlayedSpades(){
    return model_->getTable()->getSpades();
}

bool checkGameOver(){

}

std::vector<Card*> getPlayerHand(){

}

std::vector<Card*> getPlayerLegalPlays(){

}


bool checkHumanPlayer(){

}

bool playCard(std::string){

}

std::string playCard(){

}

bool discardCard(std::string){

}

std::string discardCard(){

}

bool hasLegalPlay(){

}

int getPlayerID(){

}

std::vector<Card*> getDeck(){

}

void quit(){

}

void ragequit(){

}



