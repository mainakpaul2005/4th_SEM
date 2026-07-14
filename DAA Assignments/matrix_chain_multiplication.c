#include <stdio.h>
#include <limits.h>

#define MAX 20

void printOptimalParens(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }

    printf("(");
    printOptimalParens(s, i, s[i][j]);
    printOptimalParens(s, s[i][j] + 1, j);
    printf(")");
}

int main() {
    int n;
    int p[MAX];
    int m[MAX][MAX], s[MAX][MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array of size %d: \n", n + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d\n", m[1][n]);
    printf("Optimal parenthesization = ");
    printOptimalParens(s, 1, n);
    printf("\n");
    printf("Time Complexity: O(n^3)\n");

    /*
    Sample Input:
    3
    10 20 30 40

    Sample Output:
    Minimum number of scalar multiplications = 18000
    Optimal parenthesization = ((A1A2)A3)
    Time Complexity: O(n^3)
    */

    return 0;
}