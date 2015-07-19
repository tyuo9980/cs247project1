#include "Controller.h"
#include "../model/Model.h"
#include "../model/Table.h"

//constructor
Controller::Controller(Model* m) : model_(m){}

void Controller::newGameButtonClicked(int seed, char playerType[]) {
    model_->newGame(seed, playerType);
}

void Controller::rageButtonClicked(int index) {
    model_->rageQuit(index);
}

void Controller::cardButtonClicked(int index){
    model_->cardAction(index);
}
