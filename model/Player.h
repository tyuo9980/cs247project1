#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player {
public:
    Player();
    Player(Player&);
    ~Player();
    
protected:
    void playCard(Card*);
    void discardCard(Card*);
    
private:
    int score_;
    std::vector<Card*> hand_;
    std::vector<Card*> discard_;
};


#endif