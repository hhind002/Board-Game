#include <iostream>
#include "board.h"

using namespace std;

// Define the Board constructor
Board::Board()
{
    // Initialize the grid array with empty space
    for(int i = 0; i < 18; i++)
        for(int j = 0; j < 18; j++)
            grid[i][j] = ' ';
}

// Define the makeBoard() function
void Board::makeBoard()
{
    // Output the x-axis values
    grid [0][2] = '0';
    grid [0][4] = '1';
    grid [0][6] = '2';
    grid [0][8] = '3';
    grid [0][10] = '4';
    grid [0][12] = '5';
    grid [0][14] = '6';
    grid [0][16] = '7';

    // Initialize the horizonal board
    for(int i = 1; i < 18; i++)
    {
        // Output the horizontal lines of the board
        grid[1][i] = '-';
        grid[3][i] = '-';
        grid[5][i] = '-';
        grid[7][i] = '-';
        grid[9][i] = '-';
        grid[11][i] = '-';
        grid[13][i] = '-';
        grid[15][i] = '-';
        grid[17][i] = '-';
    }

    // Output the y-axis values
    grid [2][0] = 'a';
    grid [4][0] = 'b';
    grid [6][0] = 'c';
    grid [8][0] = 'd';
    grid [10][0] = 'e';
    grid [12][0] = 'f';
    grid [14][0] = 'g';
    grid [16][0] = 'h';

    // Initialize the vertical board
    for(int i = 2; i < 17; i++)
    {
        // Output the horizontal lines of the board
        grid[i][1] = '|';
        grid[i][3] = '|';
        grid[i][5] = '|';
        grid[i][7] = '|';
        grid[i][9] = '|';
        grid[i][11] = '|';
        grid[i][13] = '|';
        grid[i][15] = '|';
        grid[i][17] = '|';
    }
}

// Define the printBoard() function
void Board::printBoard()
{
    // Clear the previous grid graphics
    system("clear");

    // Create a for loop that goes through each row of the board
    for(int i = 0; i < 18; i++)
    {
        // Create a for loop that goes through each column of the board
        for(int j = 0; j < 18; j++)
        {
            // Create an output statement that prints the posistion of the board
            cout << grid[i][j];
        }
        cout << endl;
    }
}
