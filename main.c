/*
 *
 * Author: Daniel Favour Oshidero
 * Last Edited: 15/01/24
 *
 * Simulation of TicTacToe Game.
 *
 *
 */

#include <stdio.h>
#include <string.h>

char playerOne = 'X';
char playerTwo = 'O';

_Bool hasWon = 0;
char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char turn = 'X';

_Bool checkMovesLeft()
{
}

char findBoardMark()
{
}

void drawBoard(char board[])
{
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%c", board[i]);
        if (i % 3 < 2)
        {
            printf(" | "); // Print vertical separator after the first and second columns
        }
        if ((i + 1) % 3 == 0 && i < 8)
        {
            printf("\n---------\n"); // Print horizontal separator after the first and second rows
        }
    }
    printf("\n");
}

_Bool checkForWin()
{
}

void markBoard()
{
}

int main()
{
    drawBoard(board);
    return 0;
}