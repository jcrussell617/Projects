#ifndef MINEFIELD_H
#define MINEFIELD_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Minefield {
public:
Minefield() {
    rows = 0;
    columns = 0;
}

void createGame(int userRows, int userColumns) {
    rows = userRows;
    columns = userColumns;
    mineField = vector<vector<char>>(rows, vector<char>(columns));
    cin.ignore(1000, '\n');
    for (int i=0; i < rows; i++) {
        getline(cin, userString, '\n');
        for (int x=0; x < userString.length(); x++) {
            if (userString[x] == ' ') {
                userString.erase(i,1);
            }
        }
        for (int j=0; j < columns; j++) {
            mineField[j][i] = userString[j];
        }
    }

    for (int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            if (mineField[j][i] == '.') {
                numMines = 0;
                if (j+1 < columns) {
                    if (mineField[j+1][i] == '*'){
                        numMines++;
                    }
                if (i+1 < rows && mineField[j+1][i+1] == '*') {
                    numMines++;
                }
                if (i-1 >= 0 && mineField[j+1][i-1] == '*') {
                    numMines++;
                }

                }
                if (j-1 >= 0) {
                    if (mineField[j-1][i] == '*'){
                        numMines++;
                    }
                if (i+1 < rows && mineField[j-1][i+1] == '*') {
                    numMines++;
                }
                if (i-1 >= 0 && mineField[j-1][i-1] == '*') {
                    numMines++;
                }
                }
                if (i+1 < rows) {
                    if (mineField[j][i+1] == '*') {
                        numMines++;
                    }
                }
                if (i-1 >= 0) {
                    if (mineField[j][i-1] == '*') {
                        numMines++;
                    }
                }
                charMines = static_cast<char>('0' + numMines);
                mineField[j][i] = charMines;
            }
        }
    }
    for (int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            cout << mineField[j][i] << " ";
        }
        cout << endl;
    }
}
private:
int rows;
int columns;
int numMines;
char charMines;
string userString;
vector<vector<char>> mineField;
};


#endif