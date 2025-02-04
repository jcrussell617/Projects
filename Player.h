#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

class Player {

public:
    
    string playerName;
    Hand playerHand;
    bool isBust = false;

    Player(string playerName) {
        this->playerName = playerName;
    }


};








#endif