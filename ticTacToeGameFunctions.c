// Functions file
#include "ticTacToeGameFunctions.h"

// Resets the board
void resetBoard(){

    // For the rows
    for(int i = 0; i < 3; i++){
        // For the columns
        for(int j = 0; j < 3; j++){
            // Sets all board spaces to an empty space
            board[i][j] = ' ';
        }
    }
}



// Prints the board
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}



// Checks the board for free spaces
int checkSpaces(){

    int freeSpaces = 9;

    // For the rows
    for(int i = 0 ; i < 3; i++){
        // For the columns
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}



// Calculates the players move
void playerMove(){

    int x = 0;
    int y = 0;

    // Continues to prompt user for a choice, if they pick an invalid spot it will prompt them again
    do{
        // Prompts user for row choice
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;

        // Prompts user for column choice
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        // Checks if user choice was valid
        if(board[x][y] != ' '){
            printf("Please choose an open spot.\n\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}



// Calculates the computer move
void computerMove(){

    // Creates a random number using srand and with time
    srand(time(0));

    int x = 0;
    int y = 0;

    // Looks for a valid space before generating choice
    if(checkSpaces() > 0){
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while(board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else{
        winPrint(' ');
    }
}



// Checks for the winner
char winChecker(){

    // Checks the rows
    for(int i = 0; i < 3; i++){
        // Compares the content of each row to see if they are all equal
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    // Checks the columns
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    // Checks the top left to bottom right diagonal
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            return board[0][0];
    }

    // Checks the top right to bottom left diagonal
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
            return board[0][2];
    }

    return ' ';
}



// Prints the wining message
void winPrint(char winner){

    if(winner == PLAYER){
        printf("Congratulations, YOU WIN");
    }
    else if(winner == COMPUTER){
        printf("Better luck next time, YOU LOSE!");
    }
    else{
        printf("It's a draw!");
    }
}