#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
public:
    Player();
	Player(int,int, std::vector<Card*>, std::vector<Card*>);
	//Player(const Player&);
	int getCurrScore() const;
	int getOldScore() const;
	const std::vector<Card*>& getHand() const;
	const std::vector<Card*>& getDiscard() const;
	virtual bool isHuman() const = 0;
	void addCards(Card*);
    void playCard(Card);
    void discardCard(Card);
	void resetPlayer();
	//void setHand(std::vector<Card*>&);
	//void setDiscard(std::vector<Card*>&);
	//void setScore(int);

private:
    int currScore_;
	int oldScore_;
	std::vector<Card*>::const_iterator findCard(Card);
    std::vector<Card*> hand_;
    std::vector<Card*> discard_;
};


#endif