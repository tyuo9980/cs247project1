#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <vector>
#include "Player.h"
#include "HumanPlayer.h"

class ComputerPlayer : public Player {
public:
	ComputerPlayer();
	ComputerPlayer(const HumanPlayer&);
	bool isHuman() const;
};


#endif