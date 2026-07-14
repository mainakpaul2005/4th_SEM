#include <stdio.h>

int isSafe(int board[8], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
            return 0;
    }
    return 1;
}

int solve(int board[8], int row) {
    if (row == 8)
        return 1;

    for (int col = 0; col < 8; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if (solve(board, row + 1))
                return 1;
        }
    }
    return 0;
}

void printBoard(int board[8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    int board[8] = {0};

    if (solve(board, 0)) {
        printf("8-Queen solution:\n");
        printBoard(board);
    } else {
        printf("No solution found.\n");
    }

    printf("Backtracking explores solutions and prunes invalid states early.\n");

    /*
    Sample Output:
    8-Queen solution:
    Q . . . . . . .
    ...
    Backtracking explores solutions and prunes invalid states early.
    */

    return 0;
}