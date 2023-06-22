#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "ticTacToeGameFunctions.c"

int main(){

    char winner = ' ';
    char userChoice;

    printf("\nTIC-TAC-TOE GAME\n\n");

    do
    {
        winner = ' ';
        userChoice = ' ';
        resetBoard();

        while(winner == ' ' && checkSpaces() != 0){

            //Prints the board
            printBoard();

            // For the player
            playerMove();
            winner = winChecker();
            if(winner != ' ' || checkSpaces() == 0){
                break;
            }

            // For the computer
            computerMove();
            winner = winChecker();
            if(winner != ' ' || checkSpaces() == 0){
                break;
            }

            printf("\n");
        }

        printBoard();
        winPrint(winner);

        // Prompts the user for replay choice
        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &userChoice);
        userChoice = toupper(userChoice);

    }while(userChoice == 'Y');

    printf("Thank you for playing!");

    return 0;
}