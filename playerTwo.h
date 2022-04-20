#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include <iostream>
#include "referee.h"
#include "board.h"

using namespace std;

// Define the Board class
class PlayerTwo
{
    // Declare the friend class so that the Board class can work with the private members
    friend class Board;

    // Declare the private members
    char fromRow;
    char fromCol;
    char toRow;
    char toCol;
    int toRow0;
    int toCol0;
    int fromRow0;
    int fromCol0;

    // Declare the public function members and constructor
    public:
    void placePieces2(Board& b);
    void movePiece2(Board& b, Referee& r);
    void selectingPiece(Board& b, Referee& r, bool& u, bool& c);
    void selectingLocation(bool& u);
    void validate(Board& b, bool& c);
    void checkCornerCapture(Board& b, Referee& r, int toRow0, int toCol0);
    void validateLocation(Board&b, bool& a, bool& d, bool& c);
    void checkCaptureDuke(Board& b, int toRow0, int toCol0);
    void checkCapture(Board& b, Referee& r, int toRow0, int toCol0);
};

#endif // PLAYERTWO_H