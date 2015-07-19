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
    void newGameButtonClicked(int, char[]);
    void rageButtonClicked(int);
    void cardButtonClicked(int);
    
private:
    Model* model_;                              //access to model
};

#endif

