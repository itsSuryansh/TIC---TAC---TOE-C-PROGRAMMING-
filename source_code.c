#include <stdio.h>

void initializeBoard(char board[3][3]) {
    char c = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = c++;
        }
    }
}

void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

int isValidMove(char board[3][3], int move) {
    if (move < 1 || move > 9) return 0;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return 0;

    return 1;
}

void makeMove(char board[3][3], int move, char symbol) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = symbol;
}

int checkWinner(char board[3][3]) {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    return 0; // No winner yet
}

int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

void playGame() {
    char board[3][3];
    int move, winner = 0;
    char currentPlayer = 'X';

    initializeBoard(board);

    printf("=== TIC-TAC-TOE (2 Players) ===\n");
    printf("Player 1 = X\n");
    printf("Player 2 = O\n");

    while (1) {
        displayBoard(board);

        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &move);

        if (!isValidMove(board, move)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        makeMove(board, move, currentPlayer);

        winner = checkWinner(board);
        if (winner != 0) {
            displayBoard(board);
            printf("Player %d (%c) wins!\n", winner, (winner == 1 ? 'X' : 'O'));
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    playGame();
    return 0;
}