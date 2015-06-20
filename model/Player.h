#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
public:
    Player();                                                   //constructor
	Player(int,int, std::vector<Card*>, std::vector<Card*>);    //constructor - copies cards and scores
    ~Player();                                                  //destructor
	int getCurrScore() const;                                   //current score accessor
	int getOldScore() const;                                    //old score accessor
	const std::vector<Card*>& getHand() const;                  //returns list of cards in hand
	const std::vector<Card*>& getDiscard() const;               //returns list of discarded cards
	virtual bool isHuman() const = 0;                           //checks if player is human
	void addCards(Card*);                                       //add cards to hand
    void playCard(Card);                                        //plays a card
    void discardCard(Card);                                     //discard a card
	void resetPlayer();                                         //resets player hand, discard, and scores
	//void setHand(std::vector<Card*>&);
	//void setDiscard(std::vector<Card*>&);
	//void setScore(int);

private:
    int currScore_;                                             //current score data memeber
	int oldScore_;                                              //old score data member
	std::vector<Card*>::const_iterator findCard(Card);          //find card iterator
    std::vector<Card*> hand_;                                   //list of cards in hand data member
    std::vector<Card*> discard_;                                //list of discarded cards data member
};


#endif