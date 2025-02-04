#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Hand.h"
#include "House.h"

class Game {

public:
    vector<Player> players;
    bool allPlayersBust = true;
    vector<Player> winners;
    int winningValue = -1;
    

    void checkBust(Player& player) {
        if (player.playerHand.handValue > 21) {
            player.isBust = true;
        }
    }

    void getResults(House& house) {

        cout << "House ";
        house.houseHand.faceupHand();
        house.houseHand.displayHand();
        cout << endl;
        
        for (Player& player : players) {
            if (!player.isBust) {
                allPlayersBust = false;
                if (player.playerHand.handValueAceHigh > winningValue) {
                    winners.clear();
                    winners.push_back(player);
                    winningValue = player.playerHand.handValueAceHigh;
                }
                else if (player.playerHand.handValueAceHigh == winningValue) {
                    winners.push_back(player);
                }
            }
        }

        if (allPlayersBust) {
            cout << "House wins!" << endl;
        }

        else if (winningValue > house.houseHand.handValueAceHigh) {
            for (Player winner : winners) {
                cout << winner.playerName << " wins!" << endl;
            }
        }

        else if (winningValue < house.houseHand.handValueAceHigh) {
                cout << "House wins!" << endl;
            }

        else if (winningValue == house.houseHand.handValueAceHigh) {
            cout << "Tie!" << endl;
        }
    }






};










#endif