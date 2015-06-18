#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <vector>
#include "Player.h"
class HumanPlayer : public Player {
public:
	HumanPlayer();
	bool isHuman() const;
};


#endif