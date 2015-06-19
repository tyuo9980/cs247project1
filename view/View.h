#ifndef VIEW_H
#define VIEW_H


#include <string>
#include <vector>

class Controller;
class Model;
class Card;

const std::string cardName_[13] = {"A", "2", "3",
                                        "4", "5", "6",
                                        "7", "8", "9",
                                        "10", "J", "Q", "K"};   //mapping of card number to name
class View {
public:
    View(Controller*);                                          //contructor
    ~View();                                                    //destructor
    
private:
    Controller* controller_;                                    //access to controller

    void printCards(bool[]);                                    //print cards given boolean array
    void printCards(std::vector<Card*>);                        //print cards given vector of cards
    void newGame();                                             //starts game - main loop
    
};

#endif
