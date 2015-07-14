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
    
    Gtk::HBox panels;                                           // Main window divided into two horizontal panels
    Gtk::VBox butBox;                                           // Vertical boxes for stacking buttons vertically
    Gtk::Button next_button;
    Gtk::Button reset_button;
    Gtk::Image card;

    void printCards(bool[]);                                    //print cards given boolean array
    void printCards(std::vector<Card*>);                        //print cards given vector of cards
    void newGame();                                             //starts game - main loop
    
};

#endif
