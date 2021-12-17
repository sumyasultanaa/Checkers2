# Checkers2
by Sumya Sultana and Rachel Kong for CS 102 Section C Fall 2021
# Introduction

Checkers is played by two people who oppose each other across a board of 64 light and dark squares, the same as a chessboard. The 24 playing pieces are disk-shaped and of contrasting colors. At the start of the game, each contestant has 12 pieces arranged on the board. The notation used in describing the game is based on numbering the squares on the board. The black pieces always occupy squares 1 to 12, and the white pieces invariably rest on squares 21 to 32. The pieces can only move forward diagonally.

To account for the limited graphics in C, we used different symbols to denote our black and red pieces. (The red pieces are denoted by $. The black pieces are denoted by @).

E denotes empty spots as where these are the open spaces where each player can move to.
Only diagonal moves are allowed by jumping over opponent pieces to capture pieces. One player has the dark pieces; the other has the light pieces. Players alternate turns, and a player may not move an opponent's piece. A move consists of moving a piece diagonally to an adjacent unoccupied square that is denoted by E. 

We created a 2 player game in which each user inputs a starting point to indicate which piece they want to move. Our program then asks for an entry of where the player wants to move their piece. If the player attempts to make an "illegal" move, the game will inform the user that the move was illegal and will be requested to try again. 

If the adjacent square contains an opponent's piece, and the square immediately beyond it is empty or unoccupied, the piece may be captured by jumping over it. These rules are accounted for in our code. 

Basic Rules
-Always move diaganolly forward towards opponent's side of gameboard
-Move your checker piece on space diagonally to an open adjacent square or jump one or more checkers diagonally to an adjacent square of the checker piece jumped over. When you jump over the opponent's piece, you capture it
-If all the adjacent to your checker are occupied, your check is blocked and can't move
-When your checker reaches the first row on your opponent's side of board

# Technical Description
void printDisplayFancy - Function is used to display the board. Due to it only displaying the checkerboard, the void makes it so that the function does not return a specific value but still displays it
void swapIJKL - The swap function is used to switch the characters in the board without the function needing to return a specific value. This is also used for the movement of the @ (black pieces), $ (red pieces), and E (empty squares). 
char value2symbol - The char function holds a single symbol which can also be an upper or lower case letter. In our code, we used the ASCII table to determine which characters alligned with the user's string input of the row number followed by the column letter.
int Playersturn - int data type for user input of column followed by either the i, j, k, or l interval. In the game, this defines the data type. Since the string that determines the location of each square is a ROW, COLUMN string, the integer function tells the compiler or user that the values of r and c are specifically integer values. 

Bugs:
-Taking multiple pieces in one single move is not implemented
-Code will not allow capital letters to substitute lowercase ones, so if the player wanst to moove from 3d to 5f but insetad types 5F, the game will call this move illegal even though its technically the same.
-User must enter string input as the row followed by the column (r,c) and cannot enter it (c,r) or else the output is a repeating loop of "Red's turn: to: RED move from -1,-97 to -1,-97 move your own piece! Illegal move, try again"
-Game does not indicate when there is a winner. Even if the red piece captures all the black pieces, there will be no indication of a win rather than that all the black pieces are gone from the board. 

Sample Game: 
1. 3b - 4c (RED)
2. 6c - 5d (BLACK)
3. 2a - 3b (RED
4. 5d - 4e (BLACK)
5. 3d - 5f (RED) *1 black captured*
6. 6g - 4e (BLACK) *1 red captured*
7. 3f - 4g (RED)
8. 6e - 5d (BLACK)
9. 4g - 5f (RED)
10. 4e - 3f (BLACK)
11. 4c - 6e (RED) *1 black captured*
12. 7f - 5d (BLACK) *1 red captured*
13. 5f - 6g (RED) 
14. 7h - 5f (BLACK) *1 red captured*
15. 2e - 4g (RED) *1 black captured*
16. 5d - 4c (BLACK) 
17. 3b - 5d (RED) *1 black captured*
18. 7b - 6c (BLACK) *1 red captured*
19. 5d - 7b (RED) *1 black captured*
20. 6a - 5b (BLACK)
21. 4g - 6e (RED) *1 black captured*
22. 5b - 4a (BLACK) 
23. 3h - 4g (RED) 
24. 8c - 6a (BLACK) *1 red captured*
25. 6e - 8c (RED) *1 black captured*
26. 4a - 3b (BLACK) 
27.  2c - 4a (RED) *1 black captured*
28. 8g - 7f (BLACK)
29. 4g - 5f (RED) 
30. 7f - 6e (BLACK)
31. 5f - 7d (RED) *1 black captured*
32. 6a - 5b (BLACK)
33. 4a - 6c (RED) *1 black captured*
34. 8a - 7b (BLACK)
35. 6c - 8a (RED) *1 black captured*
36. 8e - 7f (BLACK)
37. 1b - 2c (RED)
38. 7f - 6e (BLACK)
39. 2c - 3d (RED)
40. 6e - 5d (BLACK)
41. 3d - 4e (RED)
42. 5d - 4c (BLACK)
43. 1d - 2c (RED)
44. 4c - 3b (BLACK)
45. 2c - 4a (RED) *last black captured*

Result: All blacks are captured, but game does not technically end. Code is "continuous"

Possible Scenarios

Illegal Input #1: 6a, 6b 
Output: Move your own piece! 
Illegal move, try again!
Explanation: Red ($) goes first; player can only move $ pieces

Illegal Input #2: 2a, 2b
Output: You must move to empty location. Illegal move, try again!
Explanation: Player attempts to move to a square that is not empty; empty squares are denoted by "E"

Illegal Input #3: 2a, 4a
Output: You can only move diagonally. Illegal move, try again!
Explanation: Player attempted to move in a straight line; pieces can only move diagonally forward

Successful Input: 3b, 4c
Output: RED move from 2,1 to 3,2
SWAP: 2,1 to 3,2 
Explanation: This is a correct move as the player moves diagonally forward to an empty square; swap function switches the new position of the $ piece with "E" 



# Screenshots of Working Program
[![Screen-Shot-2021-12-14-at-1-56-08-PM.png](https://i.postimg.cc/gjfyf4kN/Screen-Shot-2021-12-14-at-1-56-08-PM.png)](https://postimg.cc/vxt6nrnV)

# Link to YouTube video recording of presentation and code walk through
https://www.youtube.com/watch?v=THVTntUk3Tc
