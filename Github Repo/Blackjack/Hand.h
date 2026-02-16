#ifndef HAND_H
#define HAND_H
#include<vector>
#include "Card.h"
#include "Deck.h"


class Hand {

public:
    vector<Card> handVector;
    int handValue = 0;
    int handValueAceHigh = 0;
    bool hasAce = false;

    Hand() {
        
    }

    void addCard(Card dealtCard) {

        handVector.push_back(dealtCard);

        if (dealtCard.rank == ACE) {
            hasAce = true;
            handValue += 1;
            if (handValue + 10 <= 21) {
                handValueAceHigh = handValue + 10;
            }
            else {
                handValueAceHigh = handValue;
            }
        }

        else {
            handValue += dealtCard.getCardvalue();
            handValueAceHigh = handValue;
        }
    }

    void displayHand(bool ishouseHand = false) {
        for (Card card : handVector) {
            card.displayCardName();
            cout << " ";
        }
        if (!ishouseHand) {
            if (hasAce) {
                
                if (handValueAceHigh != handValue) {
                    cout << "(" << handValue << " or " << handValueAceHigh << ")";
                }
                else {
                    cout << "(" << handValue << ")";
                }
                
            }
            else {
                cout << "(" << handValue << ")";
            }
        }
    }

    void facedownHand() {
        for (Card& card : handVector) {
            if (card.faceUp == true) {
                card.faceUp = false;
            }
        }
    }

    void faceupHand() {
        for (Card& card : handVector) {
            if (card.faceUp == false) {
                card.faceUp = true;
            }
        }
    }


};





#endif