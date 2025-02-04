#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"
#include "House.h"
#include<iostream>
#include<random>
#include<time.h>
using namespace std;

int main() {
    Deck deck1;
    Game game1;
    bool quit = false;
    char userInput;
    int numPlayers = 0;
    cout << "Welcome to Blackjack!" << endl << "Enter number of players (1-7)" << endl;
    cin >> numPlayers;
    House house1;
    for (int i=1; i<=numPlayers; i++) {
        string playerName;
        cout << "Enter name for player " << i << ": " << endl;
        cin >> playerName;
        game1.players.push_back(Player(playerName));
    }

    
        for (int i=0; i < 2; i++) {
            deck1.DealCard(house1.houseHand);
            for (Player& Player : game1.players) {
                deck1.DealCard(Player.playerHand);  
            }
        }
        house1.houseHand.facedownHand();

        for (Player& Player : game1.players) {
            if (Player.isBust == false) {
                cout << Player.playerName << " ";
                Player.playerHand.displayHand();
                cout << endl;
            }
            else {
                cout << Player.playerName << " ";
                Player.playerHand.displayHand();
                cout << endl;
                cout << Player.playerName << " busts!" << endl;
            }
        }
        
    while(quit == false) {

        cout << "House ";
        house1.houseHand.displayHand(true);
        cout << '\n';

        for (Player& Player : game1.players) {
            bool isHit = true;
            if (!Player.isBust) {
                cout << Player.playerName << ", do you want to hit (Y or N)?" << endl;
                cin >> userInput;
                if (userInput == 'Y') {
                    isHit = true;
                    while (isHit == true) {
                        deck1.DealCard(Player.playerHand);
                        game1.checkBust(Player);
                            if (Player.isBust == false) {
                                cout << Player.playerName << " ";
                                Player.playerHand.displayHand();
                                cout << endl;
                                cout << Player.playerName << ", do you want to hit (Y or N)?" << endl;
                                cin >> userInput;
                                if (userInput == 'Y') {
                                    continue;
                                }
                                else {
                                    isHit = false;
                                    break;
                                }
                            }
                        else {
                            cout << Player.playerName << " ";
                            Player.playerHand.displayHand();
                            cout << endl;
                            cout << Player.playerName << " busts!" << endl;
                            isHit = false;
                            break;
                        }
                    }
                }
                else {
                    continue;
                }
            }
            if (Player.isBust) {
                continue;
            }
        } 
        quit = true; 
    }

    game1.getResults(house1);
    
    
}