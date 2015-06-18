#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "subject.h"
#include "Deck.h"
#include "Table.h"
#include "Player.h"
class Model : public Subject {
public:
    Model();
	void newGame();
	void endGame();
	void rageQuit();

private:
	Table* table_;
    Deck* deck_;
    Player* players_[4];
};


#endif