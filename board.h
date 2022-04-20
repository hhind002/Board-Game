#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>

using namespace std;

// Define the Board class
class Board
{
    // Declare the friend classes so that the Board class can work with the private members
    friend class PlayerOne;
    friend class PlayerTwo;
    friend class Referee;

    // Declare the private members
    private:
    char grid[18][18];

    // Declare the public function members and constructor
    public:
    Board();
    void makeBoard();
    void printBoard();
};

#endif // BOARD_H