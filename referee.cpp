#include <iostream>
#include "board.h"
#include "referee.h"
#include <stdlib.h>

using namespace std;

// Define the Referee constructor
Referee::Referee()
{
    score1 = 8;
    score2 = 8;
}

void Referee::countScore(char u)
{
    if(u == 'x')
    {
        score2--;

        if (score2 == 0)
        {
            cout << "Player one WINS! Congratulations!" << endl;
            exit(0);
        }
    }

    else
        {
            score1--;

            if (score1 == 0)
            {
                cout << "Player two WINS! Congratulations!" << endl;
                exit(0);
            }
        }
}

// Define the outputScore() function
void Referee::outputScore()
{
    cout << "Player one's score: " << score1 << endl
         << "Player two's score: " << score2 << endl;
}