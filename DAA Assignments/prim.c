#include <stdio.h>

#define MAX 20
#define INF 99999

void prim(int graph[MAX][MAX], int n) {
    int selected[MAX] = {0};
    int key[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;

        for (int v = 0; v < n; v++) {
            if (!selected[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1)
            break;

        selected[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !selected[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    printf("Prim's MST:\n");
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
            total += graph[i][parent[i]];
        }
    }
    printf("Total cost = %d\n", total);
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix using 99999 for no edge:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j)
                graph[i][j] = 0;
        }
    }

    prim(graph, n);
    printf("Prim generates a minimum spanning tree by expanding the current tree.\n");

    /*
    Sample Input:
    4
    0 10 6 5
    10 0 99999 15
    6 99999 0 4
    5 15 4 0

    Sample Output:
    Prim's MST:
    0 - 3 : 5
    3 - 2 : 4
    0 - 1 : 10
    Total cost = 19
    Prim generates a minimum spanning tree by expanding the current tree.
    */

    return 0;
}