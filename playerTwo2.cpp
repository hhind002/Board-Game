// Best comments for identical operations can be found in playerOne.cpp function

#include <iostream>
#include "playerTwo.h"
#include "board.h"
#include "referee.h"


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
void PlayerTwo::movePiece2(Board& b, Referee& r)
{
    // Declare the local variable
    bool u = 0;
    bool c = 0;
    bool a = 0;
    bool d = 1;

    // Create an output statement that prompts for user input on what piece to move and allows for input
    cout << "\nPlayer Two's turn!\nPlease select a piece to move using its coordinates. " << endl;
    cout << "X-Coordinate: " << flush;
    cin >> fromRow;
    cout << "Y-Coordinate: " << flush;
    cin >> fromCol;
    cout << endl;

    // Create a loop that allows for reselection of both the piece to move and where it is going
    while(a == 0)
    {
        // Create a placeholder variable
        d = 1;

        // Create a function call to the selecting piece function 
        selectingPiece(b, r, u, c);

        // Reset the conditional variable
        c = 0;

        // Create an output statement prompting for user input on where to move piece to
        cout << "Please select the desired location for the entered piece." << endl;
        cout << "X-Coordinate: " << flush;
        cin >> toRow;
        cout << "Y-Coordinate: " << flush;
        cin >> toCol;
        cout << endl;

        // Create a loop that allows the place to move to be reselected if needed
        while (c == 0)
        {
            // Update the value for the next loop
            u = 0;

            // Convert the entered location to grid notation
            selectingLocation(u);
       
            validate(b, c);
        }

        c = 0;
        u = 0;

       validateLocation(b, a, d, c);
    }

    b.grid[toRow0][toCol0] = b.grid[fromRow0][fromCol0];
    b.grid[fromRow0][fromCol0] = ' ';
    checkCapture(b, r, toRow0, toCol0);
    checkCaptureDuke(b, toRow0, toCol0);
    b.printBoard();

}

// Create a function for checkCapture() function
void PlayerTwo::checkCapture(Board& b, Referee& r, int toRow0, int toCol0)
{
    // Declare the local variable
    char u = 'o';

    if (b.grid[toRow0 + 2][toCol0] == 'o')
    {
        if (b.grid[toRow0 + 4][toCol0] == 'x')
            {
                b.grid[toRow0 + 2][toCol0] = ' ';
                
                r.countScore(u);
            }
    }

    else if (b.grid[toRow0 - 2][toCol0] == 'o')
    {
        if (b.grid[toRow0 - 4][toCol0] == 'x')
            {
                b.grid[toRow0 - 2][toCol0] = ' ';
                r.countScore(u);
            }
    }

    else if (b.grid[toRow0][toCol0 + 2] == 'o')
    {
        if (b.grid[toRow0][toCol0 + 4] == 'x')
            {
                b.grid[toRow0][toCol0 + 2] = ' ';
                r.countScore(u);
            }
    }

    else if (b.grid[toRow0][toCol0 - 2] == 'o')
    {
        if (b.grid[toRow0][toCol0 - 4] == 'x')
            {
                b.grid[toRow0][toCol0 - 2] = ' ';
                r.countScore(u);
            }
    }

    else
        return;
}

// Define the checkCaptureDuke() function
void PlayerTwo::checkCaptureDuke(Board& b, int toRow0, int toCol0)
{
    // Declare the local variables
    int x = 0;

    // Check if the piece moved is above the duke
    if (b.grid[toRow0 + 2][toCol0] == 'O')
    {
        if (b.grid[toRow0 + 4][toCol0] == 'x')
        {
            if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;

                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                       cout << "Duke captured. Player two wins!" << endl;
                       exit(0);
                    }
                }
                
                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0 + 4][toCol0] == 'o')
        {
            x++;
            if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }

    // Check if the piece moved is below the duke
    else if (b.grid[toRow0 - 2][toCol0] == 'O')
    {
        if (b.grid[toRow0 - 4][toCol0] == 'x')
        {
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
                
                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0 - 4][toCol0] == 'o')
        {
            x++;
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }

    // Check to see if the piece moved is to the left of the duke
    else if (b.grid[toRow0][toCol0 + 2] == 'O')
    {
        if (b.grid[toRow0][toCol0 + 4] == 'x')
        {
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
                
                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0][toCol0 - 4] == 'o')
        {
            x++;
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }

    // Check to see if the piece moved is to the right of the duke
    else if (b.grid[toRow0][toCol0 - 2] == 'O')
    {
        if (b.grid[toRow0][toCol0 - 4] == 'x')
        {
            if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
                
                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0][toCol0 - 4] == 'o')
        {
            x++;
            if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player two wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }
}

// Define the selectingPiece() function
void PlayerTwo::selectingPiece(Board& b, Referee& r, bool& u, bool& c)
{
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
                        cout << "The entered coordinates are invalid.\nPlease re-enter the coordinates for the piece you would like to move." << endl;
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
                        cout << "The entered coordinates are invalid.\nPlease re-enter the coordinates for the piece you would like to move." << endl;
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
                    cout << "You selected player one's piece.\nPlease re-enter the coordinates for your own piece ('x' / 'X')." << endl;
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
                    cout << "You selected an empty space.\nPlease re-enter the coordinates for a piece you want to move." << endl;
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
}

// Define the selectingLocation() function
void PlayerTwo::selectingLocation(bool& u)
{
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
                    cout << "The entered posision is invalid.\nPlease re-enter where you would like to move your piece." << endl;
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
                    cout << "The entered posision is invalid.\nPlease re-enter where you would like to move your piece." << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> toRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> toCol;
                    cout << endl;
                    u = 0;
            }
        }
}

// Define the validate() function
void PlayerTwo::validate(Board& b, bool& c)
{
    if ((b.grid[toRow0][toCol0] == 'x') || (b.grid[toRow0][toCol0] == 'X') || (b.grid[toRow0][toCol0] == 'o') || (b.grid[toRow0][toCol0] == 'O'))
            {
                cout << "There is already a piece occupying this spot. Please re-enter a desired location." << endl;
                cout << "X-Coordinate: " << flush;
                cin >> toRow;
                cout << "Y-Coordinate: " << flush;
                cin >> toCol;
                cout << endl;
                c = 0;
            }

            else if  ((toCol0 != fromCol0) && (toRow0 != fromRow0))
            {
                cerr << toCol0 << " " << fromCol0 << endl;
                cout << "A piece can only move horizontally or vertically. Please re-enter a desired location." << endl;
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

// Define the validateLocation() function
void PlayerTwo::validateLocation(Board&b, bool& a, bool& d, bool& c)
{
     if (toRow0 > fromRow0)
        {
            for (int i = toRow0; i > fromRow0; i--)
            {
                if ((b.grid[i][toCol0] == 'o') || (b.grid[i][toCol0] == 'O') || (b.grid[i][toCol0] == 'x') || (b.grid[i][toCol0] == 'X'))
                {
                    cout << "A piece is in the way of your path.\nPlease select a piece to move using its coordinates." << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> fromRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> fromCol;
                    cout << endl;
                    d = 0;
                    c = 0;
                    break;
                }

                else 
                    i--; 
            }

            if (d == 1)
                a = 1;
            
            else 
                a = 0;
        }

        else if (fromRow0 > toRow0)
        {
            for (int i = toRow0; i < fromRow0; i++)
            {
                if ((b.grid[i][toCol0] == 'o') || (b.grid[i][toCol0] == 'O') || (b.grid[i][toCol0] == 'x') || (b.grid[i][toCol0] == 'X'))
                {
                    cout << "A piece is in the way of your path.\nPlease select a piece to move using its coordinates. " << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> fromRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> fromCol;
                    cout << endl;
                    a = 0;
                    d = 0;
                    break;
                }

                i++;
            }

            if (d == 1)
                a = 1;
            
            else 
                a = 0;
        }

        else if (fromCol0 > toCol0)
        {
            for (int i = fromCol0 - 2; i > toCol0; i++)
            {
                if ((b.grid[toRow0][i] == 'o') || (b.grid[toRow0][i] == 'O') || (b.grid[toRow0][i] == 'x') || (b.grid[toRow0][i] == 'X'))
                {
                    cout << "A piece is in the way of your path.\nPlease select a piece to move using its coordinates. " << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> fromRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> fromCol;
                    cout << endl;
                    a = 0;
                    d = 0;
                    break;
                }

                i--;
            }

            if (d == 1)
                a = 1;
            
            else 
                a = 0;
        }

        else if (toCol0 > fromCol0)
        {
            for (int i = toCol0 - 2; i > fromCol0; i--)
            {
                if ((b.grid[toRow0][i] == 'o') || (b.grid[toRow0][i] == 'O') || (b.grid[toRow0][i] == 'x') || (b.grid[toRow0][i] == 'X'))
                {
                    cout << "A piece is in the way of your path.\nPlease select a piece to move using its coordinates. " << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> fromRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> fromCol;
                    cout << endl;
                    a = 0;
                    d = 0;
                    break;
                }

                i--;
            }

            if (d == 1)
                a = 1;
            
            else 
                a = 0;
        }

        else
            a = 1;
}