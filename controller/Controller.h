#ifndef CONTROLLER_H
#define CONTROLLER_H

class Model;

class Controller {
public:
    Controller( Model* );
    void shuffle();
    void deal();
    void addPlayer(std::string);
    void findStarter();
private:
    Model *model_;
};


#endif