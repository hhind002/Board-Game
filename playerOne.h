#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <iostream>
#include "board.h"
#include "referee.h"

using namespace std;

// Define the Board class
class PlayerOne
{
    // Declare the friend class so that the Board class can work with the private members
    friend class Board;
    friend class Referee;

    // Declate the private members
    private:
    char fromRow;
    char fromCol;
    int fromRow0;
    int fromCol0;
    char toRow;
    char toCol;
    int toRow0;
    int toCol0;

    // Declare the public function members 
    public:
    void placePieces1(Board& b);
    void movePiece1(Board& b, Referee& r);
    void checkCapture(Board& b, Referee& r, int toRow0, int toCol0);
    void selectingPiece(Board& b, Referee& r, bool& u, bool& c);
    void selectingLocation(bool& u);
    void checkCaptureDuke(Board& b, int toRow0, int toCol0);
    void checkCornerCapture(Board& b, Referee& r, int toRow0, int toCol0);
    void validateLocation(Board&b, bool& a, bool& d, bool& c);
    void validate(Board& b, bool& c);
};

#endif // PLAYERONE_H