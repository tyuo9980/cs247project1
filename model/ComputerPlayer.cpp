#include "ComputerPlayer.h"
#include "HumanPlayer.h"


ComputerPlayer::ComputerPlayer() :Player(){}

ComputerPlayer::ComputerPlayer(const HumanPlayer& human):Player(human.getCurrScore(), human.getOldScore(), human.getHand(), human.getDiscard()) {}

bool ComputerPlayer::isHuman() const {
	return false;
}