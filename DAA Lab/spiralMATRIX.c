#include <stdio.h>

int main() {
    int matrix[100][100];
    int n, i, j;

    printf("Enter a number: ");
    scanf("%d", &n);

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {

        for (j = left; j <= right; j++) {
            matrix[top][j] = num++;
        }
        top++;

        for (i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        if (top <= bottom) {
            for (j = right; j >= left; j--) {
                matrix[bottom][j] = num++;
            }
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    printf("\n Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
