# TicTacToe Game Simulation in C

This project is a simple console-based TicTacToe game implemented in C. It allows two players to play the classic game of TicTacToe against each other.

## Features
- **Player Name Input:** Players can enter their names at the start of the game.
- **Turn-Based Gameplay:** Players take turns to mark their symbols (X or O) on the board.
- **Win Detection:** The game detects and announces the winner.
- **Valid Input Checking:** Ensures players do not overwrite each other's moves and that the chosen position is within the game board's bounds.
- **Console-Based Interface:** Game board and instructions are displayed in the console.

## How to Play
1. Run the program.
2. Each player is prompted to enter their name.
3. Player One will use 'X', and Player Two will use 'O'.
4. Players take turns to choose a position on the board (0 to 8) to place their mark.
5. The first player to align three of their marks (horizontally, vertically, or diagonally) wins.
6. The game ends when a player wins.

## Compilation
Compile the program with a C compiler, e.g., `gcc`:

## Future Enhancements
- Implementing a draw condition when the board is full and there's no winner.
- Enhancing user interface for a better gaming experience.
- Adding AI for a single-player mode.
