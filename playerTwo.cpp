#include <iostream>
#include "playerTwo.h"
#include "board.h"

using namespace std;

// Define the placePieces2() function
void PlayerTwo::placePieces2(Board& b)
{
    // Create a for loop that continues through every other row
    for (int i = 2; i < 17; i++)
    {
        // Place a piece in the designated starting position
        b.grid[2][i] = 'x';

        // Add an additional amount to skip over the lines of the board
        i++;
    }

    // Place the duke piece in the designated starting position
    b.grid[4][8] = 'X';
}

// Define the movePiece1() function
void PlayerTwo::movePiece2(Board& b)
{
    // Declare the local variable
    bool u = 0;
    bool c = 0;
    bool a = 0;

    // Create an output statement that prompts for user input on what piece to move and allows for input
    cout << "\nPlayer Two's turn!\nPlease select a piece to move using its coordinates. " << endl;
    cout << "X-Coordinate: " << flush;
    cin >> fromRow;
    cout << "Y-Coordinate: " << flush;
    cin >> fromCol;
    cout << endl;


    while(c == 0)
    {
        // Create a while loop to check if the entered value is viable for row and update the entered position with the corresponding grid value
        while(u == 0)
        {
            // Check the entered value and assign the corresponding grid position
            switch(fromRow)
            {
                case 'a':
                    fromRow0 = 2;
                    u = 1;
                    break;
        
                case 'b':
                    fromRow0 = 4;
                    u = 1;
                    break;

                case 'c':
                    fromRow0 = 6;
                    u = 1;
                    break;
        
                case 'd':
                    fromRow0 = 8;
                    u = 1;
                    break;

                case 'e':
                    fromRow0 = 10;
                    u = 1;
                    break;
        
                case 'f':
                    fromRow0 = 12;
                    u = 1;
                    break;
        
                case 'g':
                    fromRow0 = 14;
                    u = 1;
                    break;
        
                case 'h':
                    fromRow0 = 16;
                    u = 1;
                    break;
        
                default:
                    cout << "The entered position is invalid.\nPlease re-enter a position for the piece you would like to move." << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> fromRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> fromCol;
                    cout << endl;
                    u = 0;
            }
        }

        // Update the value for the next loop
        u = 0;

        // Create a while loop to check if the entered value is viable for column and update the entered position with the coresponding grid value
        while(u == 0)
        {
            // Check the entered value and assign the corresponding grid position
            switch(fromCol)
            {
                case '0':
                    fromCol0 = 2;
                    u = 1;
                    break;
        
                case '1':
                    fromCol0 = 4;
                    u = 1;
                    break;

                case '2':
                    fromCol0 = 6;
                    u = 1;
                    break;
        
                case '3':
                    fromCol0 = 8;
                    u = 1;
                    break;

                case '4':
                    fromCol0 = 10;
                    u = 1;
                    break;
        
                case '5':
                    fromCol0 = 12;
                    u = 1;
                    break;
        
                case '6':
                    fromCol0= 14;
                    u = 1;
                    break;
        
                case '7':
                    fromCol0 = 16;
                    u = 1;
                    break;
        
                default:
                    cout << "This is not a possible position.\nPlease re-enter a position for the location you would like to move" << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> fromRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> fromCol;
                    cout << endl;
                    u = 0;
            }
        }

        if((b.grid[fromRow0][fromCol0] == 'o') || (b.grid[fromRow0][fromCol0] == 'O'))
            {
                cout << "You selected player two's piece.\nPlease re-enter a position for the location you would like to move with your own piece." << endl;
                cout << "X-Coordinate: " << flush;
                cin >> fromRow;
                cout << "Y-Coordinate: " << flush;
                cin >> fromCol;
                cout << endl;
                c = 0;
                u = 0;
            }

            else if (b.grid[fromRow0][fromCol0] == ' ')
            {
                cout << "You selected an empty space.\nPlease re-enter a position for the location you would like to move with your own piece." << endl;
                cout << "X-Coordinate: " << flush;
                cin >> fromRow;
                cout << "Y-Coordinate: " << flush;
                cin >> fromCol;
                cout << endl;
                c = 0;
                u = 0;
            }

            else
                c = 1;
    
    }

    c = 0;

    // Create an output statement prompting for user input on where to move piece to
    cout << "Please select the desired location for the entered piece." << endl;
    cout << "X-Coordinate: " << flush;
    cin >> toRow;
    cout << "Y-Coordinate: " << flush;
    cin >> toCol;
    cout << endl;


while (c == 0)
{
    // Update the value for the next loop
    u = 0;
    
    // Create a while loop to check if the entered value is viable and update the entered position with the coresponding grid value
    while(u == 0)
    {
        switch(toRow)
        {
            case 'a':
                toRow0 = 2;
                u = 1;
                break;
        
            case 'b':
                toRow0 = 4;
                u = 1;
                break;

            case 'c':
                toRow0 = 6;
                u = 1;
                break;
        
            case 'd':
                toRow0 = 8;
                u = 1;
                break;

            case 'e':
                toRow0 = 10;
                u = 1;
                break;
        
            case 'f':
                toRow0 = 12;
                u = 1;
                break;
        
            case 'g':
                toRow0 = 14;
                u = 1;
                break;
        
            case 'h':
                toRow0 = 16;
                u = 1;
                break;
        
            default:
                cout << "The entered posision is invalid.\nPlease re-enter a position for the desired location for the entered piece." << endl;
                cout << "X-Coordinate: " << flush;
                cin >> toRow;
                cout << "Y-Coordinate: " << flush;
                cin >> toCol;
                cout << endl;
                u = 0;
        }

        switch(toCol)
        {
            case '0':
                toCol0 = 2;
                u = 1;
                break;
        
            case '1':
                toCol0 = 4;
                u = 1;
                break;

            case '2':
                toCol0 = 6;
                u = 1;
                break;
        
            case '3':
                toCol0 = 8;
                u = 1;
                break;

            case '4':
                toCol0 = 10;
                u = 1;
                break;
        
            case '5':
                toCol0 = 12;
                u = 1;
                break;
        
            case '6':
                toCol0 = 14;
                u = 1;
                break;
        
            case '7':
                toCol0 = 16;
                u = 1;
                break;
        
            default:
                cout << "The entered posision is invalid.\nPlease re-enter a position for the desired location for the entered piece." << endl;
                cout << "X-Coordinate: " << flush;
                cin >> toRow;
                cout << "Y-Coordinate: " << flush;
                cin >> toCol;
                cout << endl;
                u = 0;
        }
    }

    if ((b.grid[toRow0][toCol0] == 'x') || (b.grid[toRow0][toCol0] == 'X') || (b.grid[toRow0][toCol0] == 'o') || (b.grid[toRow0][toCol0] == 'O'))
    {
        cout << "There is already a piece occupying that location. Please re-enter a desired location for the entered piece." << endl;
        cout << "X-Coordinate: " << flush;
        cin >> toRow;
        cout << "Y-Coordinate: " << flush;
        cin >> toCol;
        cout << endl;
        c = 0;
    }

    else if  ((toCol0 != fromCol0) && (toRow0 != fromRow0))
    {
        cout << "A piece can only move horizontally or vertically. Please re-enter a desired location for the entered piece." << endl;
        cout << "X-Coordinate: " << flush;
        cin >> toRow;
        cout << "Y-Coordinate: " << flush;
        cin >> toCol;
        cout << endl;
        c = 0;
    }
    
    else
        c = 1;
}

    b.grid[toRow0][toCol0] = b.grid[fromRow0][fromCol0];
    b.grid[fromRow0][fromCol0] = ' ';
    checkCapture(b, toRow0, toCol0);
    b.printBoard();

}

// Create a function for checkCapture() function
void PlayerTwo::checkCapture(Board& b, int toRow0, int toCol0)
{
    if (b.grid[toRow0 + 2][toCol0] == 'o')
    {
        if (b.grid[toRow0 + 4][toCol0] == 'x')
            {
                b.grid[toRow0 + 2][toCol0] = ' ';
                // Subtract from score
            }
    }

    else if (b.grid[toRow0 - 2][toCol0] == 'o')
    {
        if (b.grid[toRow0 - 4][toCol0] == 'x')
            {
                b.grid[toRow0 - 2][toCol0] = ' ';
                // Subtract from score
            }
    }

    else if (b.grid[toRow0][toCol0 + 2] == 'o')
    {
        if (b.grid[toRow0][toCol0 + 4] == 'x')
            {
                b.grid[toRow0][toCol0 + 2] = ' ';
                // Subtract from score
            }
    }

    else if (b.grid[toRow0][toCol0 - 2] == 'o')
    {
        if (b.grid[toRow0][toCol0 - 4] == 'x')
            {
                b.grid[toRow0][toCol0 - 2] = ' ';
                // Subtract from score
            }
    }

    else
        return;
}