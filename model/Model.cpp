#include "Model.h"


Model::Model() : table_(NULL), deck_(NULL), gameOver_(false) {}

void Model::newGame(int seed, bool players[]) {
	// prepare all the players
	for (int i = 0; i < NUMBER_PLAYERS; ++i) {
		if (players[i]) 
			players_.insert(pair<int, Player*>(i, new HumanPlayer()));
		else 
			players_.insert(pair<int, Player*>(i, new ComputerPlayer()));
	}
	deck_->shuffle();
    
	// distribute cards
			// first time entering the loop check for 7 of spades
	// game loop
	// big loop that loop through all the players
		// enter the game loop
	   // does not stop until gameOVer flag is set
		   // nextplayer x
			// ask for input
				// if next player can play a card (has legal play) 
					// then play the card
				// else discard a card
					// check if he has legal play in his hand
				// else if deck -> print out all the deck
				// else if quit -> quit the game immediately
				// else if rage quit
					 // replace the human with computer
	     // if (the hand for all players are null) game ends => calculating score

}

void Model::distributeCards(){
	Player* currPlayer = players_.find(;
	for (int i = 0; i < RANK_COUNT; ++i) {
	
	}
		

}