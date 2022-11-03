//std
#include <iostream>
//Importing class
#include "ConsoleGame.h"
using namespace std;


int main() {
    int rows, cols, speed, max_round;
    cout << "Welcome to Game of life " << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of colums: ";
    cin >> cols;
    cout << "Speed of generation: ";
    cin >> speed;
    cout << "Number of cycles: ";
    cin >> max_round;
    ConsoleGame game(rows, cols, speed, max_round);
    game.run();
    return 0;
}
