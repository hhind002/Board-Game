#ifndef REFEREE_H
#define REFEREE_H

#include <iostream>
#include "board.h"


using namespace std;

// Define the Board class
class Referee
{
    // Declare the friend class so that the Board class can work with the private members
    friend class Board;

    // Declare the private members
    int score1;
    int score2;
   
    // Declare the public function members and constructor
    public:
    Referee();
    void countScore(char u);
    void outputScore();
};

#endif // REFEREE_H