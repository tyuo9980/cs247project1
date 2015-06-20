#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <vector>
#include "Player.h"

class HumanPlayer : public Player {
public:
	HumanPlayer();                      //constructor
	bool isHuman() const;               //check if player is human
};


#endif