#include <stdio.h>

#define MAX 20
#define INF 99999

void floydWarshall(int dist[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    int n;
    int dist[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix using 99999 for no edge:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if (i == j)
                dist[i][j] = 0;
        }
    }

    floydWarshall(dist, n);

    printf("All-pairs shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    printf("Time Complexity: O(V^3)\n");

    /*
    Sample Input:
    4
    0 5 99999 10
    99999 0 3 99999
    99999 99999 0 1
    99999 99999 99999 0

    Sample Output:
    All-pairs shortest path matrix:
    0 5 8 9
    INF 0 3 4
    INF INF 0 1
    INF INF INF 0
    Time Complexity: O(V^3)
    */

    return 0;
}