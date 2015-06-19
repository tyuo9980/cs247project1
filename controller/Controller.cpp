#include "Controller.h"
#include "../model/Model.h"
#include "../model/Table.h"

Controller::Controller(Model* m) : model_(m){

}

void Controller::shuffle(){
    model_->shuffle();
}

void Controller::deal(){
    model_->deal();
}

void Controller::addPlayer(std::string type){
    if (type == "h"){
        model_->addHuman();
    }
    else{
        model_->addComputer();
    }
}

void Controller::findStarter(){
    model_->findStarter();
}

bool* Controller::getPlayedClubs(){
    return model_->getClubs();
}

bool* Controller::getPlayedDiamonds(){
    return model_->getDiamonds();
}

bool* Controller::getPlayedHearts(){
    return model_->getHearts();
}

bool* Controller::getPlayedSpades(){
    return model_->getSpades();
}

bool Controller::checkGameOver(){
    return model_->isGameOver();
}

std::vector<Card*> Controller::getPlayerHand(){
    return model_->getPlayerHand();
}

std::vector<Card*> Controller::getPlayerLegalPlays(){
    return model_->getPlayerLegalPlays();
}


bool Controller::checkHumanPlayer(){
    return model_->isHuman();
}

bool Controller::playCard(std::string card){
    return model_->playCard(card);
}

std::string Controller::playCard(){
    return model_->computerPlayCard();
}

bool Controller::discardCard(std::string card){
    return model_->discardCard(card)
}

std::string Controller::discardCard(){
    return model_->computerDiscardCard();
}

bool Controller::hasLegalPlay(){
    return model_->hasLegalPlays();
}

int Controller::getPlayerID(){
    return model_->getPlayerID();
}

std::vector<Card*> Controller::getDeck(){
    return model_->getDeck();
}

void Controller::quit(){
    model_->quit();
}

void Controller::ragequit(){
    model_->rageQuit();
}



