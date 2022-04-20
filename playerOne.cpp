#include <iostream>
#include "playerOne.h"
#include "board.h"
#include "referee.h"

using namespace std;

// Define the placePieces1() function
void PlayerOne::placePieces1(Board& b)
{
    // Create a for loop that continues through each row
    for (int i = 2; i < 17; i++)
    {
        // Place a piece in the designated starting position
        b.grid[16][i] = 'o';

        // Add an additional amount to skip over the lines of the board
        i++;
    }

    // Place the duke piece in the designated starting position
    b.grid[14][10] = 'O';
}

// Define the movePiece1() function
void PlayerOne::movePiece1(Board& b, Referee& r)
{
    // Declare the local variable
    bool u = 0;
    bool c = 0;
    bool a = 0;
    bool d = 1;

    // Create an output statement that prompts for user input on what piece to move and allows for input
    cout << "\nPlayer One's turn!\nPlease select a piece to move using its coordinates. " << endl;
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

        // Reset the values for the next tests
        c = 0;
        u = 0;

        validateLocation(b, a, d, c);
    }

    // Update the piece to the new location
    b.grid[toRow0][toCol0] = b.grid[fromRow0][fromCol0];

    // Clear the old location of the piece
    b.grid[fromRow0][fromCol0] = ' ';

    // Create a function call to check if the piece is capturing an enemy piece
    checkCapture(b, r, toRow0, toCol0);

    // Create a function call to check if the piece is capturing a duke
    checkCaptureDuke(b, toRow0, toCol0);
    
    // Print the updated board
    b.printBoard();

}

// Define the checkCapture() function
void PlayerOne::checkCapture(Board& b, Referee& r, int toRow0, int toCol0)
{
    // Declare the local variable
    char u = 'x';

    // Check to see if there is an enemy piece below
    if (b.grid[toRow0 + 2][toCol0] == 'x')
    {
        // Check to see if there is a friendly piece below the enemy piece
        if (b.grid[toRow0 + 4][toCol0] == 'o')
            {
                // Remove the enemy from the board
                b.grid[toRow0 + 2][toCol0] = ' ';

                // Update the score
                r.countScore(u);
            }
    }

    // Check to see if there is an enemy piece above
    else if (b.grid[toRow0 - 2][toCol0] == 'x')
    {
        // Check to see if there is a friendly piece above the enemy piece
        if (b.grid[toRow0 - 4][toCol0] == 'o')
            {
                // Remove the enemy from the board
                b.grid[toRow0 - 2][toCol0] = ' ';

                // Update the score
                r.countScore(u);
            }
    }

    // Check to see if there is an enemy piece to the right
    else if (b.grid[toRow0][toCol0 + 2] == 'x')
    {
        // Check to see if there is a friendly piece to the right of the enemy
        if (b.grid[toRow0][toCol0 + 4] == 'o')
            {
                // Remove the enemy from the board
                b.grid[toRow0][toCol0 + 2] = ' ';

                // Update the score
                r.countScore(u);
            }
    }

    // Check to see if there is an enemy piece to the left
    else if (b.grid[toRow0][toCol0 - 2] == 'x')
    {
        // Check to see if there is a friendly piece to the left of the enemy
        if (b.grid[toRow0][toCol0 - 4] == 'o')
            {
                // Remove the enemy from the board
                b.grid[toRow0][toCol0 - 2] = ' ';

                // Update the score
                r.countScore(u);
            }
    }

    // Otherwise do nothing
    else
        return;
}

// Define the checkCaptureDuke() function
void PlayerOne::checkCaptureDuke(Board& b, int toRow0, int toCol0)
{
    // Declare the local variables
    int x = 0;

    // Check if the piece moved is above the duke
    if (b.grid[toRow0 + 2][toCol0] == 'X')
    {
        if (b.grid[toRow0 + 4][toCol0] == 'o')
        {
            if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;

                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                       cout << "Duke captured. Player one wins!" << endl;
                       exit(0);
                    }
                }
                
                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0 + 4][toCol0] == 'x')
        {
            x++;
            if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }

    // Check if the piece moved is below the duke
    else if (b.grid[toRow0 - 2][toCol0] == 'X')
    {
        if (b.grid[toRow0 - 4][toCol0] == 'o')
        {
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
                
                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0 - 4][toCol0] == 'x')
        {
            x++;
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }

    // Check to see if the piece moved is to the left of the duke
    else if (b.grid[toRow0][toCol0 + 2] == 'X')
    {
        if (b.grid[toRow0][toCol0 + 4] == 'o')
        {
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
                
                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0][toCol0 - 4] == 'x')
        {
            x++;
            if (b.grid[toRow0 - 2][toCol0 + 2] == 'o')
            {
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 - 2][toCol0 + 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 + 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 + 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }

    // Check to see if the piece moved is to the right of the duke
    else if (b.grid[toRow0][toCol0 - 2] == 'X')
    {
        if (b.grid[toRow0][toCol0 - 4] == 'o')
        {
            if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }

                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }

            else if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
                
                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }

        else if (b.grid[toRow0][toCol0 - 4] == 'x')
        {
            x++;
            if (b.grid[toRow0 - 2][toCol0 - 2] == 'o')
            {
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
            
            else if (b.grid[toRow0 - 2][toCol0 - 2] == 'x')
            {
                x++;
                if (b.grid[toRow0 + 2][toCol0 - 2] == 'o')
                {
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }

                else if (b.grid[toRow0 + 2][toCol0 - 2] == 'x')
                {
                    x++;
                    if (x < 2)
                    {
                        cout << "Duke captured. Player one wins!" << endl;
                        exit(0);
                    }
                }
            }
        }
    }
}

void PlayerOne::selectingPiece(Board& b, Referee& r, bool& u, bool& c)
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

             if((b.grid[fromRow0][fromCol0] == 'x') || (b.grid[fromRow0][fromCol0] == 'X'))
                {
                    cout << "You selected player two's piece.\nPlease re-enter the coordinates for your own piece ('o' / 'O')." << endl;
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
void PlayerOne::selectingLocation(bool& u)
{
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

// Define the validateLocation() function
void PlayerOne::validateLocation(Board& b, bool& a, bool& d, bool& c)
{
          // Check to see if there is an obstacle on the path you want when moving up the board
        if (toRow0 > fromRow0)
        {
            // Create a loop to iterate through each spot between where you are going and where you came from
            for (int i = toRow0; i > fromRow0; i--)
            {
                // Check to see if there is a piece in the way
                if ((b.grid[i][toCol0] == 'o') || (b.grid[i][toCol0] == 'O') || (b.grid[i][toCol0] == 'x') || (b.grid[i][toCol0] == 'X'))
                {
                    // Explain the error to the user and allow for new input
                    cout << "A piece is in the way of your path.\nPlease re-select a piece to move using its coordinates." << endl;
                    cout << "X-Coordinate: " << flush;
                    cin >> fromRow;
                    cout << "Y-Coordinate: " << flush;
                    cin >> fromCol;
                    cout << endl;
                    d = 0;
                    c = 0;
                    break;
                }

                // Update the loop to the next spot
                i--; 
            }

            // Check the results and if it passed validate the coordinates
            if (d == 1)
                a = 1;
            
            // Otherwise, loop the program to re-enter the piece you want to move
            else 
                a = 0;
        }

        // Check to see if there is an obstacle on the path you want when moving backwards
        else if (fromRow0 > toRow0)
        {
            // Create a loop to iterate through each spot between where you are going and where you came from
            for (int i = toRow0; i < fromRow0; i++)
            {
                // Check to see if there is a piece in the way
                if ((b.grid[i][toCol0] == 'o') || (b.grid[i][toCol0] == 'O') || (b.grid[i][toCol0] == 'x') || (b.grid[i][toCol0] == 'X'))
                {
                    // Explain the error to the user and allow for new input
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

                // Update the loop to the next spot
                i++;
            }

            // Check the results and if it passed validate the coordinates
            if (d == 1)
                a = 1; 
            
            // Otherwise, loop the program to re-enter the piece you want to move
            else 
                a = 0;
        }

        // Check to see if there is an obstacle on the path you want when moving left
        else if (fromCol0 > toCol0)
        {
            // Create a loop to iterate through each spot between where you are going and where you came from
            for (int i = fromCol0 - 2; i > toCol0; i--)
            {
                // Check to see if there is a piece in the way
                if ((b.grid[toRow0][i] == 'o') || (b.grid[toRow0][i] == 'O') || (b.grid[toRow0][i] == 'x') || (b.grid[toRow0][i] == 'X'))
                {
                    // Explain the error to the user and allow for new input
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

                // Update the loop to the next spot
                i--;
            }

            // Check the results and if it passed validate the coordinates
            if (d == 1)
                a = 1;
            
            // Otherwise, loop the program to re-enter the piece you want to move
            else 
                a = 0;
        }

        // Check to see if there is an obstacle on the path you want when moving right
        else if (toCol0 > fromCol0)
        {
            // Create a loop to iterate through each spot between where you are going and where you came from
            for (int i = toCol0 - 2; i > fromCol0; i--)
            {
                // Check to see if there is a piece in the way
                if ((b.grid[toRow0][i] == 'o') || (b.grid[toRow0][i] == 'O') || (b.grid[toRow0][i] == 'x') || (b.grid[toRow0][i] == 'X'))
                {
                    // Explain the error to the user and allow for new input
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

                // Update the loop to the next spot
                i--;
            }

            // Check the results and if it passed validate the coordinates
            if (d == 1)
                a = 1; 

            // Otherwise, loop the program to re-enter the piece you want to move
            else 
                a = 0;
        }

        // Validate the path is free
        else
            a = 1;
}

// Define the validateLocation1() function
void PlayerOne::validate(Board& b, bool& c)
{
    // Check if there is a piece in the location you are trying to move to
    if ((b.grid[toRow0][toCol0] == 'x') || (b.grid[toRow0][toCol0] == 'X') || (b.grid[toRow0][toCol0] == 'o') || (b.grid[toRow0][toCol0] == 'O'))
    {
        // Explain the error to the user and allow for new input
        cout << "There is already a piece occupying this spot. Please re-enter a desired location." << endl;
        cout << "X-Coordinate: " << flush;
        cin >> toRow;
        cout << "Y-Coordinate: " << flush;
        cin >> toCol;
        cout << endl;
        c = 0;
    }

    // Check if the piece is being moved horizontally or vertically
    else if  ((toCol0 != fromCol0) && (toRow0 != fromRow0))
    {
        // Explain the error to the user and allow for new input
        cout << "A piece can only move horizontally or vertically. Please re-enter a desired location." << endl;
        cout << "X-Coordinate: " << flush;
        cin >> toRow;
        cout << "Y-Coordinate: " << flush;
        cin >> toCol;
        cout << endl;
        c = 0;
    }

    // Otherwise allow the values to become valid
    else
        c = 1;
}