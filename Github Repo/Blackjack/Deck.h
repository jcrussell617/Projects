#ifndef DECK_H
#define DECK_H
#include<vector>
#include<string>
#include<random>
#include<algorithm>
#include<time.h>
using namespace std;
enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
#include "Card.h"
#include "Hand.h"

class Deck {

public:

    vector<Card> cardDeck;

    Deck() {

        for (int suit=HEARTS; suit<=SPADES; suit++) {
            for (int rank=ACE; rank<=KING; rank++) {
                cardDeck.push_back(Card{static_cast<Suit>(suit), static_cast<Rank>(rank)});
            }
        }

        srand(time(0));
        random_device rd;
        mt19937 g(rd());
        shuffle(cardDeck.begin(), cardDeck.end(), g);


    }

    void DealCard(Hand& playerHand) {
        if (!cardDeck.empty()) {
            Card dealtCard = cardDeck.back();

                cardDeck.pop_back();
                dealtCard.inPlay = true;
                playerHand.addCard(dealtCard); 
        }
    }






};





#endif