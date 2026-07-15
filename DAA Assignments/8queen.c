#include <stdio.h>

int isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            board[i] - i == col - row ||
            board[i] + i == col + row)
            return 0;
    }
    return 1;
}

int solve(int board[], int row, int n) {
    if (row == n)
        return 1;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            if (solve(board, row + 1, n))
                return 1;
        }
    }
    return 0;
}

void printBoard(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    int board[n];

    if (solve(board, 0, n)) {
        printf("%d-Queen solution:\n", n);
        printBoard(board, n);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}