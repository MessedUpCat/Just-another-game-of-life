#include <windows.h>
#include <cstdlib>
#include <string>
#include "GameEngine.h"
using namespace std;

class ConsoleGame: public Game {
private:
    int speed=0;
    int max_round=200;
public:
    //required to run the constructor of class 'game'
    //ConsoleGame(int rows, int cols) : Game(rows, cols) {}
    ConsoleGame(int, int, int, int);
    //Limit the speed of the game between 0 and 100s
    void setSpeed(int);
    //Runs the game
    void run(void);
    //Prints matrix
    void printMatrix(void);
};

ConsoleGame::ConsoleGame(int rows, int cols, int speed_, int max_round_) : Game(rows, cols) {
    speed = speed_;
    max_round = max_round_;
}

void ConsoleGame::setSpeed(int speed_) {
    if (speed_ < 0 || speed_ >= 100) {
        //if the speed is to fast or too slow, stop programm and print this message
        throw std::invalid_argument("The provided speed is out out of the range: 0-100");
    }
    speed = speed_;
}

void ConsoleGame::run(void) {
    for(int i=0; i < max_round; i++) {
        //starts the game
        makeStep();
        //prints the matrix
        printMatrix();
        //waits before next iteration
        Sleep(speed*100);
    }
    //once max amount of rounds is reached prints this message:
    cout << "Max round reached - the end!" << endl;
};

void ConsoleGame::printMatrix(void) {
    system("cls");
    //Information above the matrix
    cout << "Matrix: " << rows << "x" << cols << " Round:" << round << " Living cells: " << n_living_cells << " speed (ms): " << speed << endl;
    for (int r=0; r < rows; r++) {
        for (int c=0; c < cols; c++) {
            //prints the values in the matrix
            cout << *(matrix_to_display + r * cols + c);
        }
        //ends the line after the row is max
        cout << endl;
    }
};
