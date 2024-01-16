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
#include <stdlib.h>

typedef struct
{
    char symbol;
    char name[50];
} Player;

Player createPlayer(char symbol, const char *name)
{
    Player newPlayer;
    newPlayer.symbol = symbol;
    strcpy(newPlayer.name, name);
    newPlayer.name[sizeof(newPlayer.name) - 1] = '\0'; // Ensure null-termination
    return newPlayer;
}

Player initializePlayer(char symbol)
{
    char playerName[50];

    printf("Please enter name for player %c:\n", symbol);
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = 0; // Remove newline character

    return createPlayer(symbol, playerName);
}

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

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


int main()
{
    // Initialize players
    Player playerOne = initializePlayer('X');
    Player playerTwo = initializePlayer('O');

    printf("Clearing the screen...\n");
    clearScreen();

    printf("Press enter when you are ready to start.\n");
    getchar(); // Wait for user to press enter
    clearScreen();

    printf("\n---------------------------\n");
    drawBoard(board);
    printf("\n---------------------------\n");

    return 0;

}