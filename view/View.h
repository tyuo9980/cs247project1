#ifndef VIEW_H
#define VIEW_H

#include "Observer.h"
#include <string>

class Controller;
class Model;

class View {
public:
    View( Controller*, Model* );
    virtual ~View();
    virtual void update();	// Observer Pattern: concrete update() method
    
private:
    // Observer Pattern: to access Model accessors without having to downcast subject
    Model* model_;
    
    // Strategy Pattern member (plus signal handlers)
    Controller* controller_;
    
    const std::string cardName_[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    void printCards(bool[]);
    void newGame();
    
}; // View

#endif
