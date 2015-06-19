#include "Observer.h"
#include "View.h"
#include "../controller/Controller.h"
#include "../model/Model.h"
#include "../model/Subject.h"
#include <iostream>

View::View(Controller *c) : controller_(c) {
    newGame();
}

View::~View() {}

void View::printCards(bool cards[]){
    for (int i = 0; i < 13; i++){
        if (cards[i]){
            cout << cardName_[i] << " ";
        }
    }
}

void View::printCards(vector<Card*> cards){
    for (int i = 0; i < cards.size(); i++){
        if (cards[i]){
            cout << cardName_[i] << " ";
        }
        if ((i + 1) % 13 == 0){
            cout << endl;
        }
    }
}

void View::newGame() {
    for (int i = 1; i <= 4; i++){
        string s;
        
        std::cout << "Is player "<< i << " a human(h) or a computer(c)?" << std::endl;
        std::cout << ">";
        std::cin >> s;
        
        controller_->addPlayer(s);
    }
    
    controller_->shuffle();
    controller_->deal();
    controller_->findStarter();

    std::cout << "A new round begins. It’s player <x>’s turn to play." << std::endl;
    
    
    
    while (true){
        std::string cmd;
        
        int id = controller_->getPlayerID();
        
        if (controller_->checkGameOver()){
            break;
        }
        
        if (controller_->checkHumanPlayer()){
            std::cout << "Cards on the table:" << std::endl;
            std::cout << "Clubs: ";
            printCards(controller_->getPlayedClubs());
            std::cout << std::endl;
            
            std::cout << "Diamonds: ";
            printCards(controller_->getPlayedDiamonds());
            std::cout << std::endl;
            
            std::cout << "Hearts: ";
            printCards(controller_->getPlayedHearts());
            std::cout << std::endl;
            
            std::cout << "Spades: ";
            printCards(controller_->getPlayedSpades());
            std::cout << std::endl;
            
            std::cout << "Your hand: ";
            printCards(controller_->getPlayerHand());
            std::cout << std::endl;
            
            std::cout << "Legal plays: ";
            printCards(controller_->getPlayerLegalPlays());
            std::cout << std::endl;
            std::cout << ">";
            
            std::cin >> cmd;
            
            if (cmd == "play"){
                std::string card;
                cin >> card;
                
                if (controller_->playCard(card)){
                    std::cout << "Player " << id << " plays" << card << "." << std::endl;
                }
                else{
                    std::cout << "This is not a legal play." << std::endl;
                    std::cout << "<";
                }
            }
            else if (cmd == "discard"){
                std::string card;
                cin >> card;
                
                if (controller_->discardCard(card)){
                    std::cout << "Player " << controller_->getPlayerID() << " discards" << card << "." << std::endl;
                }
                else{
                    std::cout << "You have a legal play. You may not discard." << std::endl;
                    std::cout << ">";
                }
            }
            else if (cmd == "deck"){
                printCards(controller_->getDeck());
            }
            else if (cmd == "quit"){
                controller_->quit();
                break;
            }
            else if (cmd == "ragequit"){
                controller_->ragequit();
                cout << "Player " << id << " ragequits. A computer will now take over." << endl;
            }
        }
        else{
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
