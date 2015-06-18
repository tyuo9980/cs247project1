#ifndef MODEL_H
#define MODEL_H

#include "subject.h"
#include <vector>

class Model : public Subject {
public:
    Model();
    
private:
    Deck* deck_;
    Table* table_;
    Player*[] players_;
};


#endif