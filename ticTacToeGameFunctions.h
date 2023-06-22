// Function header file

// Constants and global variables
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

// Resets the board
void resetBoard();

// Prints the board
void printBoard();

// Checks the board for free spaces
int checkSpaces();

// Calculates the players move
void playerMove();

// Calculates the computer move
void computerMove();

// Checks for the winner
char winChecker();

// Prints the wining message
void winPrint(char);