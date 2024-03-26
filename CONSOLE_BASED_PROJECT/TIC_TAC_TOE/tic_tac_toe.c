#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Display the game board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Check if there is a win
char checkWin() {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];
    }
    // Check for draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                return '-';
            }
        }
    }
    return 'D'; // Draw
}

// Main function to play the game
int main() {
    int row, col;
    char currentPlayer = 'X';
    char winner;
    initBoard();
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");
    do {
        displayBoard();
        printf("Player %c, enter row (1-%d) and column (1-%d) separated by space: ", currentPlayer, BOARD_SIZE, BOARD_SIZE);
        scanf("%d %d", &row, &col);
        row--; // Adjusting to array index (0-based)
        col--; // Adjusting to array index (0-based)
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '-') {
            board[row][col] = currentPlayer;
            winner = checkWin();
            if (winner == '-') {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Invalid move! Try again.\n");
        }
    } while (winner == '-');
    displayBoard();
    if (winner == 'D') {
        printf("It's a draw!\n");
    } else {
        printf("Player %c wins!\n", winner);
    }
    return 0;
}
