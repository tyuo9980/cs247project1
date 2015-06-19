#ifndef CONTROLLER_H
#define CONTROLLER_H

#import <vector>
#import <string>

class Model;
class View;
class Card;

class Controller {
public:
    Controller(Model*);
    void shuffle();
    void deal();
    void addPlayer(std::string);
    void findStarter();
    bool* getPlayedClubs();
    bool* getPlayedDiamonds();
    bool* getPlayedHearts();
    bool* getPlayedSpades();
    bool checkGameOver();
    bool checkHumanPlayer();
    bool playCard(std::string);
    std::string playCard();
    bool discardCard(std::string);
    std::string discardCard();
    bool hasLegalPlay();
    int getPlayerID();
    std::vector<Card*> getDeck();
    std::vector<Card*> getPlayerHand();
    std::vector<Card*> getPlayerLegalPlays();
    void quit();
    void ragequit();
private:
    Model* model_;
    View* view_;
};


#endif