#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
public:
    Player();
	Player(int, std::vector<Card*>, std::vector<Card*>);
	//Player(const Player&);
    ~Player();
	int getScore() const;
	void dealtCard(std::vector<Card*>);
	const std::vector<Card*>& getHand() const;
	const std::vector<Card*>& getDiscard() const;
	virtual bool isHuman() const = 0;

protected:
    void playCard(Card);
    void discardCard(Card);

	//void setHand(std::vector<Card*>&);
	//void setDiscard(std::vector<Card*>&);
	//void setScore(int);

private:
    int score_;
	std::vector<Card*>::const_iterator findCard(Card);
    std::vector<Card*> hand_;
    std::vector<Card*> discard_;
};


#endif