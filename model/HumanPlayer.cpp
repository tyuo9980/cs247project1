#include "HumanPlayer.h"

//constructor
HumanPlayer::HumanPlayer() :Player(){}

//checks if player is human
bool HumanPlayer::isHuman() const {
	return true;
}