#include <iostream>
#include <vector>
using namespace std;
#include "Minefield.h"



int main() {
    int userRows;
    int userColumns;
    Minefield game1;
    cout << "Enter the number of rows and a space, followed by the number of columns." << endl;
    cin >> userRows;
    cin >> userColumns;
    if (userRows < 3 || userRows > 10) {
        cout << "Bad value";
        return 0;
    }
    if (userColumns < 3 || userRows > 8) {
        cout << "Bad value";
        return 0;
    }
    game1.createGame(userRows, userColumns);
    return 0;
}