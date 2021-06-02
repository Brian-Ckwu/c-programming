#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int checkForWinner(char board[3][3], int player);
void drawBoard(char board[3][3]);
void markBoard(char board[3][3], int player);

int main()
{
    // Declare variables and create the board array
    char board[3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int currentPlayer = 1;
    int winner = 0;

    // Play the game
    while (winner == 0) {
        drawBoard(board);
        markBoard(board, currentPlayer);
        winner = checkForWinner(board, currentPlayer);
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    
    // Display the outcome
    drawBoard(board);
    if (winner == 3) {
        printf("Gamer over. There is no winner.");
    }
    else {
        printf("Player %d is the winner.", winner);
    }

    return 0;
}

void drawBoard(char board[3][3])
{
    // Clear the screen
    system("clear");

    // Draw the board
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++) {
            printf("\t%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void markBoard(char board[3][3], int player)
{
    // Declare variables
    int position = 0;
    int row, column;

    // Ask the player which position he/she wants to mark
    printf("Player %d's turn. Please choose a position: ", player);
    scanf("%d", &position);
    row = (position - 1) / 3;
    column = (position - 1) % 3;
    // Check if the position if valid
    while ((position < 1) || (position > 9) || (board[row][column] == 'O') || (board[row][column] == 'X')) {
        drawBoard(board);
        printf("Invalid position. Please choose again: ");
        scanf("%d", &position);
        row = (position - 1) / 3;
        column = (position - 1) % 3;
    }

    // Mark the board
    board[row][column] = (player == 1) ? 'O' : 'X';
}

int checkForWinner(char board[3][3], int player)
{
    // Declare variables
    char mark = (player == 1) ? 'O' : 'X';
    int rowCount[3] = {0, 0, 0};
    int colCount[3] = {0, 0, 0};
    int diagCount[2] = {0, 0};
    int totalCount = 0;
    int winner = 0;

    // Count the number of marks
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == mark) {
                rowCount[row] += 1;
                colCount[col] += 1;
                diagCount[0] += (row == col) ? 1 : 0;
                diagCount[1] += ((row + col) == 2) ? 1 : 0;
                totalCount += 1;
            }
        }
    }

    // Check for winner
    // Check row & col
    for (int i = 0; i < 3; i++) {
        if ((rowCount[i] == 3 || colCount[i] == 3))
            return player;
    }
    // Check diagonal
    if ((diagCount[0] == 3) || diagCount[1] == 3)
        return player;
    // Check if the game is over
    if (totalCount == 5)
        return 3;
    
    return winner;
}