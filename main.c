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

Player playerOne;
Player playerTwo;

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

    printf("Please enter name for Player %c:\n", symbol);
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = 0; // Remove newline character

    return createPlayer(symbol, playerName);
}

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

void switchTurn(Player **turn)
{
    if ((*turn)->symbol == playerOne.symbol)
    {
        *turn = &playerTwo;
    }
    else
    {
        *turn = &playerOne;
    }
}

void drawBoard(char board[])
{
    printf("\n---------------------------\n");
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
    printf("\n---------------------------\n\n");
}

_Bool checkForWin()
{
    int winCombinations[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        if (board[winCombinations[i][0]] != ' ' &&
            board[winCombinations[i][0]] == board[winCombinations[i][1]] &&
            board[winCombinations[i][1]] == board[winCombinations[i][2]])
        {
            return 1; // A winning combination has been found
        }
    }

    return 0; // No winning combination found
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void insertMark(char board[], Player *turn)
{
    int index;
    _Bool validInput = 0;

    while (!validInput)
    {
        printf("Player turn: %s (%c)\nPlease type the number (0-8) you want to mark: ", turn->name, turn->symbol);
        scanf("%d", &index);
        getchar(); // Consume the newline character

        // Check if the index is within range and the position is not already taken
        if (index >= 0 && index < 9 && board[index] != 'X' && board[index] != 'O')
        {
            board[index] = turn->symbol;
            validInput = 1;
        }
        else
        {
            clearScreen();
            drawBoard(board);
            printf("Invalid position: already filled, or out of bounds. Please try again.\n");
        }
    }
}

int main()
{
    // Clear console on game initialise.
    clearScreen();

    // Initialize players
    playerOne = initializePlayer('X');
    playerTwo = initializePlayer('O');

    Player *turn = &playerOne;

    // Wait for players ready
    clearScreen();
    printf("Press enter when you are ready to start.\n");
    getchar(); // Wait for user to press enter
    clearScreen();

    _Bool hasWon = 0;
    while (!hasWon)
    {
        drawBoard(board);        // redraw board after each move
        insertMark(board, turn); // make move
        hasWon = checkForWin(); // check for win or draw after each move

        if (hasWon)
        {
            clearScreen();
            drawBoard(board);
            printf("%s wins!\nExiting...\n", turn->name);
            break; // Exit the loop if someone has won
        }

        // TODO: Implement and check for a draw condition

        clearScreen(); // clear screen after each move
        switchTurn(&turn); // switch turn after each move
    }

    return 0;
}