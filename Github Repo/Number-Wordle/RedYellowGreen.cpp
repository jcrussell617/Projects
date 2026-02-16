#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std;

class RedYellowGreen {
    private:
        int number;
        string key;
        int correctSpot;
        int correctNumber;
        int wrongNumber;
        string temp;
    
    public:
        void startGame();
        void guess();
        string getKey();
        




};

void RedYellowGreen :: startGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    number = rand() % 899 + 100;
    key = std::to_string(number); 
    correctSpot = 0;
    correctNumber = 0;
    wrongNumber = 0;
    temp = key;
}

string RedYellowGreen::getKey(){
    return key;
}

void RedYellowGreen ::guess() {
    correctSpot = 0;
    correctNumber = 0;
    wrongNumber = 0;
    string guess;
    cout << "Enter a guess?" << endl;
    cin >> guess;

    for (int k = 0; k < guess.size(); k++) {
        if (key.find(guess[k]) != string::npos) {
        }
        else {
            wrongNumber++;
        }
    }

    if (guess == key) {
        cout << "CONGRATULATIONS! YOU ARE CORRECT!" << endl;
        exit(1);
    }
 
    else {
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == temp[i]){
                temp.replace(i, 1, "*");
                guess.replace(i, 1, "#");
                correctSpot++;
            }
        }

        for (int i = 0; i < guess.size(); i++) {
            for (int j=0; j < guess.size(); j++){
                if (guess[j] == temp[i]){
                    temp.replace(i,1,"*");
                    guess.replace(j, 1, "#");
                    correctNumber++;
                }
            }
        }

        temp = key;     
                
    }   
    cout << "You have " << correctSpot << " green, " << correctNumber << " yellow, " << wrongNumber << " red." << endl;
}


int main() {
    RedYellowGreen game1;
    game1.startGame();
    game1.guess();
    cout << "You have 4 guesses remaining." << endl;
    game1.guess();
    cout << "You have 3 guesses remaining." << endl;
    game1.guess();
    cout << "You have 2 guesses remaining." << endl;
    game1.guess();
    cout << "You have 1 guesses remaining." << endl;
    game1.guess();
    cout << "Out of guesses! The number is: " << game1.getKey() << endl;
    return 0;
}