#ifndef VIEW_H
#define VIEW_H

#include <gtkmm.h>
#include "Gui.h"
#include "Observer.h"
#include <string>
#include <vector>

class Controller;
class Model;
class Card;

const std::string cardName_[13] = {"A", "2", "3",
                                   "4", "5", "6",
                                   "7", "8", "9",
                                   "10", "J", "Q", "K"};        //mapping of card number to name

class View : public Gtk::Window, public Observer{
public:
    View(Controller*, Model*);                                  //contructor
    virtual ~View();                                            //destructor
    virtual void update();
    
private:
    Controller* controller_;                                    //access to controller
    Model* model_;                                              //access to model
    
    Gui gui_;
    
    Gtk::VBox vBox;                                             // Main window divided into 4 components
    
    Gtk::VBox suits;
    Gtk::HBox hearts;
    Gtk::HBox spades;
    Gtk::HBox diamonds;
    Gtk::HBox clubs;
    
    Gtk::HBox controlPanel;
    Gtk::VBox table;
    Gtk::HBox players;
    Gtk::VBox player[4];
    Gtk::HBox hand;
    
    Gtk::Button newGame;
    Gtk::Entry seed;
    Gtk::Button endGame;
    
    Gtk::Image heart[13];
    Gtk::Image spade[13];
    Gtk::Image diamond[13];
    Gtk::Image club[13];
    
    Gtk::Label name[4];
    Gtk::Button rage[4];
    Gtk::Label points[4];
    Gtk::Label discards[4];
    
    Gtk::Image playerCards[13];

    void printCards(bool[]);                                    //print cards given boolean array
    void printCards(std::vector<Card*>);                        //print cards given vector of cards
    void startGame();                                             //starts game - main loop
    
};

#endif
