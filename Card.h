#ifndef CARD_H
#define CARD_H
#include<iostream>
#include "Deck.h"
using namespace std;

class Hand;

class Card {

public:
    bool faceUp = true;
    bool inPlay = false;
    Suit suit;
    Rank rank;

    Card(Suit s, Rank r) {
        suit = s;
        rank = r;
    }

    void flipCard() {
        if (faceUp == false) {
            faceUp = true;
        }
    }

    int getCardvalue() {
        switch (rank) {
            case ACE:
                return 1;
                break;
            case TWO:
                return 2;
                break;
            case THREE:
                return 3;
                break;
            case FOUR:
                return 4;
                break;
            case FIVE:
                return 5;
                break;
            case SIX:
                return 6;
                break;
            case SEVEN:
                return 7;
                break;
            case EIGHT:
                return 8;
                break;
            case NINE:
                return 9;
                break;
            case TEN:
                return 10;
                break;
            case JACK:
                return 10;
                break;
            case QUEEN:
                return 10;
                break;
            case KING:
                return 10;   
                break;   
            default:
                return 0;  
                break;    
        }
    }

    void displayCardName() {
            
        if (faceUp == false) {
            cout << "XX";
            return;
        }

        switch (rank) {
        case ACE:
            cout << 'A';
            break;
        case TWO:
            cout << '2';
            break;
        case THREE:
            cout << '3';
            break;
        case FOUR:
            cout << '4';
            break;
        case FIVE:
            cout << '5';
            break;
        case SIX:
            cout << '6';
            break;
        case SEVEN:
            cout << '7';
            break;
        case EIGHT:
            cout << '8';
            break;
        case NINE:
            cout << '9';
            break;
        case TEN:
            cout << "10";
            break;
        case JACK:
            cout << 'J';
            break;
        case QUEEN:
            cout << 'Q';
            break;
        case KING:
            cout << 'K';
            break;
        }

        switch (suit) {
            case HEARTS:
                cout << 'H';
                break;
            case DIAMONDS:
                cout << 'D';
                break;
            case CLUBS:
                cout << 'C';
                break;
            case SPADES:
                cout << 'S';
                break;
        }

        
    }

};






#endif