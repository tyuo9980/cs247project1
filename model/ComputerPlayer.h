#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <vector>
#include "Player.h"
#include "HumanPlayer.h"

class ComputerPlayer : public Player {
public:
	ComputerPlayer();                       //constructor
	ComputerPlayer(const HumanPlayer&);     //copy constructor
	bool isHuman() const;                   //checks if player is a computer
};


#endif