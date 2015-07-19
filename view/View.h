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
    virtual void update();                                      //update gui
    
private:
    Controller* controller_;                                    //access to controller
    Model* model_;                                              //access to model
    
    Gui gui_;                                                   //deck gui
    
    Gtk::VBox vBox;                                             //main window divided into 4 components
    
    Gtk::VBox suits;
    Gtk::HBox hearts;
    Gtk::HBox spades;
    Gtk::HBox diamonds;
    Gtk::HBox clubs;
    
    Gtk::Frame controlFrame;
    Gtk::Frame tableFrame;
    Gtk::Frame playerFrame;
    Gtk::Frame handFrame;
    
    Gtk::HBox controlPanel;
    Gtk::VBox table;
    Gtk::HBox players;
    Gtk::VBox player[4];
    Gtk::HBox hand;
    
    Gtk::Button newGame;
    Gtk::SpinButton seed;
    Gtk::Button endGame;
    
    Gtk::Image heart[13];
    Gtk::Image spade[13];
    Gtk::Image diamond[13];
    Gtk::Image club[13];
    
    Gtk::CheckButton playerType[4];
    Gtk::Label name[4];
    Gtk::Button rage[4];
    Gtk::Label points[4];
    Gtk::Label oldPoints[4];
    Gtk::Label total[4];
    Gtk::Label discards[4];
    
    Gtk::Button playerHand[13];
    Gtk::Image playerCards[13];

    void newGameClicked();                                      //new game button click event
    void rageClicked(int);                                      //rage button click event
    void cardClicked(int);                                      //card button click event
};

#endif
