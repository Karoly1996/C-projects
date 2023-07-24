#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);



int main () 
{
    char winner = ' ';
    char response;

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

    while (winner == ' ' && checkFreeSpaces() != 0) 
    {
        printBoard();
        
        //check if player won
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
        
        //check if computer won
        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
    }

    printBoard();
    printWinner(winner);
    
    printf("\nWould you like to play again? (Y/N): ");
    scanf(" %c", &response);
    response = toupper(response);
    } while (response == 'Y');
    


    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf("   %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\nR ---|---|---\n");
    printf("O  %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\nW ---|---|---\n");
    printf("   %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n    Column");
    printf("\n");
}
int checkFreeSpaces()
{
    int freeSpaces = 9;
    
    for (int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces; 
}
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter a row #(1-3)");
        scanf("%d", &x);
        x--;
    
        printf("Enter a column #(1-3)");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ') {
        printf("Invalid Move, TRY AGAIN!\n");
    } else {
        board[x][y] = PLAYER;
        break;
    }
    } while (board[x][y] != ' ');
    
}
void computerMove()
{
    //create a seed based on current time (random num gen)
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0) {
        do
        {
            x = rand() %3;
            y = rand() %3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER; 
    } else {
        printWinner(' ');
    }
}
char checkWinner()
{   
    //start loop for checking board
    for(int i = 0; i < 3; i++) {
        //check if rows are aligned for winner
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    //checking column for winner
    for(int i = 0; i < 3; i++) {
        //check if rows are aligned for winner
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }

    //check diagonals left to right
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
    }

    //check diagonals right to left
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return board[0][2];
    }

    //no winner
    return ' ';
    


}
void printWinner(char winner)
{
    if (winner == PLAYER) {
        printf("YOU WIN!");
    } else if (winner == COMPUTER) {
        printf("YOU LOST!");
    } else {
        printf("TIE GAME!");
    }
}