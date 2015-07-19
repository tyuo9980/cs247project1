#include <cassert>
#include <iostream>
#include "View.h"
#include "../controller/Controller.h"
#include "../model/Model.h"
#include "../model/Subject.h"
#include <gtkmm.h>

//constructor
View::View(Controller *c, Model *m) : controller_(c), model_(m){
    //sets up gui structure
    set_title("Straights!");
    set_border_width( 10 );
    
    add(vBox);
    
    vBox.add(controlFrame);
    vBox.add(tableFrame);
    vBox.add(playerFrame);
    vBox.add(handFrame);
    vBox.set_spacing(10);
    
    controlFrame.add(controlPanel);
    controlFrame.set_label("Game Controls");
    tableFrame.add(table);
    tableFrame.set_label("Table");
    playerFrame.add(players);
    playerFrame.set_label("Players");
    handFrame.add(hand);
    handFrame.set_label("Hand");
    
    //control frame
    controlPanel.add(newGame);
    controlPanel.add(seed);
    controlPanel.add(endGame);
    newGame.set_label("New Game");
    seed.set_numeric();
    seed.set_range(0, 1000000000);
    seed.set_increments(1, 1);
    endGame.set_label("End Game");
    
    //table frame
    table.add(clubs);
    table.add(diamonds);
    table.add(hearts);
    table.add(spades);
    clubs.set_spacing(10);
    clubs.set_border_width(5);
    diamonds.set_spacing(10);
    diamonds.set_border_width(5);
    hearts.set_spacing(10);
    hearts.set_border_width(5);
    spades.set_spacing(10);
    spades.set_border_width(5);
    for (int i = 0; i < 13; i++){
        clubs.add(club[i]);
        diamonds.add(diamond[i]);
        hearts.add(heart[i]);
        spades.add(spade[i]);
        
        club[i].set(gui_.null());
        diamond[i].set(gui_.null());
        heart[i].set(gui_.null());
        spade[i].set(gui_.null());
    }
    
    //player frame
    for (int i = 0; i < 4; i++){
        players.add(player[i]);
        player[i].add(name[i]);
        player[i].add(playerType[i]);
        player[i].add(rage[i]);
        player[i].add(points[i]);
        player[i].add(oldPoints[i]);
        player[i].add(total[i]);
        player[i].add(discards[i]);

        name[i].set_label("Player " + to_string(i + 1));
        playerType[i].set_label("Human?");
        playerType[i].set_active(true);
        rage[i].set_label("Rage");
        rage[i].set_sensitive(false);
        points[i].set_label("Current Points: 0");
        oldPoints[i].set_label("Previous Points: 0");
        total[i].set_label("Total Points: 0");
        discards[i].set_label("Discards: 0");
    }
    
    //current hand frame
    hand.set_spacing(10);
    for (int i = 0; i < 13; i++){
        hand.add(playerHand[i]);
        playerCards[i].set(gui_.null());
        playerHand[i].set_image(playerCards[i]);
        playerHand[i].set_sensitive(false);
    }
    
    //button click listeners
    newGame.signal_clicked().connect(sigc::mem_fun(*this, &View::newGameClicked));
    endGame.signal_clicked().connect(sigc::ptr_fun(Gtk::Main::quit));
    for (int i = 0; i < 4; i++){
        rage[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &View::rageClicked), i));
    }
    for (int i = 0; i < 13; i++){
        playerHand[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &View::cardClicked), i));
    }
    
    //displays all UI elements
    show_all();
    
    //subscribes to model
    model_->subscribe(this);
}

View::~View(){}

void View::update(){
    //update Table
    bool* h = model_->getHearts();
    bool* d = model_->getDiamonds();
    bool* s = model_->getSpades();
    bool* c = model_->getClubs();
    
    for (int i = 0; i < 13; i++){
        club[i].set(gui_.null());
        diamond[i].set(gui_.null());
        heart[i].set(gui_.null());
        spade[i].set(gui_.null());
    }
    
    for (int i = 0; i < 13; i++){
        if (h[i]){
            heart[i].set(gui_.image((Rank)i, HEART));
        }
        if (d[i]){
            diamond[i].set(gui_.image((Rank)i, DIAMOND));
        }
        if (s[i]){
            spade[i].set(gui_.image((Rank)i, SPADE));
        }
        if (c[i]){
            club[i].set(gui_.image((Rank)i, CLUB));
        }
    }
    
    //update players
    for (int i = 0; i < 4; i++){
        int oldScore = model_->getOldScore(i + 1);
        int scoreGained = model_->getScoreGained(i + 1);
        int numDiscards = model_->getPlayerDiscards(i + 1).size();
        bool human = model_->isHuman(i + 1);
        
        points[i].set_label("Current Points: " + to_string(scoreGained));
        oldPoints[i].set_label("Previous Points: " + to_string(oldScore));
        total[i].set_label("Total Points: " + to_string(scoreGained + oldScore));
        discards[i].set_label("Discards: " + to_string(numDiscards));
        
        if (human){
            rage[i].set_sensitive(true);
            playerType[i].set_active(true);
        }
        else{
            rage[i].set_sensitive(false);
            playerType[i].set_active(false);
        }
    }
        
    //update hand
    for (int i = 0; i < 13; i++){
        playerCards[i].set(gui_.null());
        playerHand[i].set_sensitive(false);
    }
    
    string status = "Discard a card";
    bool hasLegalPlay = model_->hasLegalPlays();
    vector<Card*> hand = model_->getPlayerHand();
    for (int i = 0; i < hand.size(); i++){
        Card* card = hand.at(i);
        Rank rank = card->getRank();
        Suit suit = card->getSuit();
        
        playerCards[i].set(gui_.image(rank, suit));
        if (hasLegalPlay && model_->isLegalPlay(*card)){
            playerHand[i].set_sensitive(true);
            status = "Play a card";
        }
        else if (!hasLegalPlay){
            playerHand[i].set_sensitive(true);
        }
    }
    
    int curr = model_->getPlayerID();
    handFrame.set_label("Player " + to_string(curr) + "'s hand - " + status);
    
    //output game over dialogues
    if (model_->isGameOver()){
        vector<int> winners = model_->getWinners();
        for (int i = 0 ; i < winners.size(); i++){
            Gtk::MessageDialog dialog("Game Over!", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
            dialog.set_secondary_text("Player " + to_string(winners.at(i)) + " wins!");
            dialog.set_default_response(Gtk::RESPONSE_YES);
            dialog.run();
        }
    }

    if (model_->roundReset()) {
        Gtk::MessageDialog dialog("New Round", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
        dialog.set_secondary_text("New round starts!");
        dialog.set_default_response(Gtk::RESPONSE_YES);
        dialog.run();
    }
}

//clicked on new game button
void View::newGameClicked(){
    char type[4];
    for (int i = 0; i < 4; i ++){
        if (playerType[i].get_active()){
            type[i] = 'h';
        }
        else{
            type[i] = 'c';
        }
    }
    
    controller_->newGameButtonClicked(seed.get_value_as_int(), type);
}

//clicked on rage button
void View::rageClicked(int i){
    controller_->rageButtonClicked(i);
}

//clicked on card button
void View::cardClicked(int i){
    controller_->cardButtonClicked(i);
}
