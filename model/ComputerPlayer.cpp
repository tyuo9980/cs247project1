#include "ComputerPlayer.h"
#include "HumanPlayer.h"

//constructor
ComputerPlayer::ComputerPlayer() :Player(){}

//copy constructor
ComputerPlayer::ComputerPlayer(const HumanPlayer& human):Player(human.getCurrScore(), human.getOldScore(), human.getHand(), human.getDiscard()) {}

//checks if computer player is computer
bool ComputerPlayer::isHuman() const {
	return false;
}