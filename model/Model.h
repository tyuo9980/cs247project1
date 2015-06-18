#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <map>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "subject.h"
#include "Deck.h"
#include "Table.h"
#include "Player.h"

using namespace std;

const int NUMBER_PLAYERS = 4;

class Model : public Subject {
public:
    Model();
	void newGame(int, bool[]);
	void distributeCards();
	void gameLoop();
	void endGame();
	void rageQuit();

private:	
	bool gameOver_;
	Table* table_;
    Deck* deck_;
	map<int, Player*> players_;
};


#endif