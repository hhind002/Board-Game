// Written by: Hunter Hindmarsh

#include <iostream>
#include "board.h"
#include "playerOne.h"
#include "playerTwo.h"
#include "referee.h"

using namespace std;

int main()
{
    // Declare the local variables
    Board b;
    PlayerOne o;
    PlayerTwo x;
    Referee r;

    // Create function call to the initializing functions
    b.makeBoard();
    o.placePieces1(b);
    x.placePieces2(b);
    b.printBoard();

    // Create a controller for the loop
    int y = 0;

    // Create a loop to loop the turns of the game
    while (y == 0)
    {
        o.movePiece1(b, r);
        x.movePiece2(b, r);
        r.outputScore();
    }

    return 0;
}