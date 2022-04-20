# Board-Game
This is my assignment final for CS 250 - Problem Solving and Programming II

Latrunculi, or Ludus Latrunculorum, is a two-player strategy board game that dates back to the Roman Empire and is believed to be a variant of Pessoi, an ancient Greek game. 
No historical evidence regarding its rules has ever been found and thus there is no definitive version. 
There are many variants based on various reconstructions by historians who have analyzed ancient texts and iconographies. 
The variations have different mechanics regarding board setup, capturing rules, etc., but they all share the same structure. 
Each player’s pieces are placed on the far sides of the board, in a manner very similar to chess, and play in turns with the goal of capturing the opponent’s pieces. 

The goal is to either capture all the opponent’s pieces or to completely immobilize the Duke. 

All pieces (including the Duke) have the same movement capabilities, move either horizontally or vertically for any number of squares as long as no other piece (friendly or not) is blocking the way.
The movement is identical to that of the rook in chess. 

In order to capture a piece, it must be flanked vertically or horizontally. 
A special case is when a piece is placed in a corner, and it must be flanked in the only two viable directions. 

The flanking must have been completed by the piece that just moved, for the capture to take place. 
This means that suicide is not possible. 


A piece is immobilized if it has nowhere to move.
In order to immobilize the Duke, it must be flanked from all four directions (or all viable directions). 
If it is placed in a corner, the capturing mechanics are identical for both duke and piece. 
The Duke’s flanking doesn’t have to be based on the opponent’s pieces entirely, since a Duke’s movement can be blocked by its own pieces as well.
But as long as one enemy piece is involved in the Duke’s encirclement then the Duke is immobilized, and the game is lost. 
Therefore, Duke suicide is possible. 
If A duke is surrounded by his own pieces, he is not immobilized and thus the game is not lost.

The program implements Latrunculi for two human players. 
The game does not permit illegal moves. At each turn, the program prompts the appropriate player to select a piece and a destination.
If an incorrect move is inputted, the program will recognize the error and continue to request correct input until the user provides it.
When a player wins, the game stops, and a message indicating which player is victorious is displayed to the screen. 

