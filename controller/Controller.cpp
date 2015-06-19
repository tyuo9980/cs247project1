#include "Controller.h"
#include "Model.h"

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

bool getPlayedClubs(){

}

bool getPlayedDiamonds(){

}

bool getPlayedHearts(){

}

bool getPlayedSpades(){

}

bool checkGameOver(){

}

std::vector<Card*> getPlayerHand(){

}

std::vector<Card*> getPlayerLegalPlays(){

}
