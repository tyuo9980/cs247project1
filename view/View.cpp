#include "Observer.h"
#include "View.h"
#include "../controller/Controller.h"
#include "../model/Model.h"
#include <iostream>

//constructor
View::View(Controller *c) : controller_(c) {
    newGame();
}

//print cards given boolean array
void View::printCards(bool cards[]){
    for (int i = 0; i < 13; i++){
        if (cards[i]){
            cout << " " << cardName_[i] ;
        }
    }
}

//print cards given vector of cards
void View::printCards(vector<Card*> cards){
	if (cards.size() == 0) return;
    for (int i = 0; i < cards.size(); i++){
        cout << *cards.at(i);
        
        if (i < cards.size() - 1){
            cout << " ";
        }
        
        if ((i + 1) % 13 == 0 && i != cards.size() - 1){
            cout << endl;
        }
    }
}

//starts game - main loop
void View::newGame() {
    
    // adds players to game
    for (int i = 1; i <= 4; i++){
        string type;
        
        std::cout << "Is player "<< i << " a human(h) or a computer(c)?" << std::endl;
        std::cout << ">";
        std::cin >> type;
        
        controller_->addPlayer(i, type);
    }
    
    //init methods - shuffle, deal, and find starting player
    controller_->shuffle();
    controller_->deal();
    controller_->findStarter();

	std::cout << "A new round begins. It's player " << controller_->getPlayerID() << "'s turn to play." << std::endl;
    
    //main game loop
    while (true){
        std::string cmd;

        //checks for game status - game is over or new round
        if (controller_->checkGameOver()){
            for (int i = 1; i <= 4; i++){
                int oldScore = controller_->getOldScore(i);
                int scoreGained = controller_->getScoreGained(i);
                
				std::cout << "Player " << i << "'s discards: ";
                printCards(controller_->getPlayerDiscards(i));
                std::cout << endl;
				std::cout << "Player " << i << "'s score: ";
                std::cout << oldScore << " + " << scoreGained << " = " << oldScore + scoreGained << std::endl;
            }
            
            vector<int> winners = controller_->getWinners();
            for (int i = 0 ; i < winners.size(); i++){
                std::cout << "Player " << winners.at(i) << " wins!" << endl;
            }
            
            if (winners.size() > 0){
                return;
            }
            
            controller_->resetRound();
            
            std::cout << "A new round begins. It's player " << controller_->getPlayerID() << "'s turn to play." << std::endl;
        }
        
        int id = controller_->getPlayerID();
        bool human = controller_->checkHumanPlayer();
        
        if (human){
            //prints stats for human player
            std::cout << "Cards on the table:" << std::endl;
            std::cout << "Clubs:";
            printCards(controller_->getPlayedClubs());
            std::cout << std::endl;
            
            std::cout << "Diamonds:";
            printCards(controller_->getPlayedDiamonds());
            std::cout << std::endl;
            
            std::cout << "Hearts:";
            printCards(controller_->getPlayedHearts());
            std::cout << std::endl;
            
            std::cout << "Spades:";
            printCards(controller_->getPlayedSpades());
            std::cout << std::endl;
            
            std::cout << "Your hand: ";
            printCards(controller_->getPlayerHand());
            std::cout << std::endl;
            
            std::cout << "Legal plays: ";
            printCards(controller_->getPlayerLegalPlays());
            
            while (true){
                std::cout << std::endl;
                std::cout << ">";
                
                std::cin >> cmd;
                
                //handles commands
                if (cmd == "play"){
                    std::string card;
                    cin >> card;
                    
                    if (controller_->playCard(card)){
                        std::cout << "Player " << id << " plays " << card << "." << endl;
                        break;
                    }
                    else{
                        std::cout << "This is not a legal play.";
                    }
                }
                else if (cmd == "discard"){
                    std::string card;
                    cin >> card;
                    
                    if (controller_->discardCard(card)){
                        std::cout << "Player " << id << " discards " << card << "." << endl;
                        break;
                    }
                    else{
                        std::cout << "You have a legal play. You may not discard.";
                    }
                }
                else if (cmd == "deck"){
                    printCards(controller_->getDeck());
                }
                else if (cmd == "quit"){
                    return;
                }
                else if (cmd == "ragequit"){
                    controller_->ragequit();
                    cout << "Player " << id << " ragequits. A computer will now take over." << endl;
                    break;
                }
            }
        }
        
        //computer player
        if (!human){
            if (controller_->hasLegalPlay()){
                std::string card = controller_->playCard();
                cout << "Player " << id << " plays " << card << "." << endl;
            }
            else{
                std::string card = controller_->discardCard();
                cout << "Player " << id << " discards " << card << "." << endl;
            }
        }
    }
}
