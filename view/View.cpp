#include "Observer.h"
#include "View.h"
#include "../controller/Controller.h"
#include "../model/Model.h"
#include "../model/Subject.h"
#include <iostream>

View::View(Controller *c, Model *m) : model_(m), controller_(c) {
    
}

View::~View() {}


void View::update() {

    
}

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
    for (int i = 0; i < 4; i++){
        string s;
        
        std::cout << "Is player <x> a human(h) or a computer(c)?" << std::endl << ">";
        std::cin >> s;
        
        controller_->addPlayer(s);
    }
    
    controller_->shuffle();
    controller_->deal();
    controller_->findStarter();

    std::cout << "A new round begins. It’s player <x>’s turn to play." << std::endl;
    
    
    
    while (true){
        std::string cmd;
        Player player = controller_->currentPlayer();
        
        if (controller_->checkGameOver()){
            
            
            break;
        }
        
        if (player.isHuman()){
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
            printCards(player.hand());
            std::cout << std::endl;
            
            std::cout << "Legal plays: "
            printCards(player.legalPlays());
            std::cout << std::endl;
            std::cout << ">";
            
            std::cin >> cmd;
            
            if (cmd == "play"){
                std::string card;
                if (player.islegalPlay(card)){
                    player.play(card);
                    std::cout << "Player " << player.id << " plays" << card << "." << std::endl;
                }
                else{
                    std::cout << "This is not a legal play." << std::endl;
                    std::cout << "<";
                }
            }
            else if (cmd == "discard"){
                if (player.hasLegalPlays()){
                    player.discard(card);
                    std::cout << "Player " << player.id << " discards" << card << "." << std::endl;
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
                break;
            }
            else if (cmd == "ragequit"){
                cout << "Player " << player.id << " ragequits. A computer will now take over." << endl;
                player = new ComputerPlayer(player);
            }
        }
        else{
            if (player.hasLegalPlays()){
                string card = player.play();
                cout << "Player " << player.id << " plays " << card << "." << endl;
            }
            else{
                string card = player.discard();
                cout << "Player " << player.id << " discards " << card << "." << endl;
            }
        }
    }
}
