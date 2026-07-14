#include <stdio.h>

#define MAX 20

int isSafeColor(int graph[MAX][MAX], int colors[MAX], int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c)
            return 0;
    }
    return 1;
}

int colorGraph(int graph[MAX][MAX], int m, int colors[MAX], int v, int n) {
    if (v == n)
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafeColor(graph, colors, v, c, n)) {
            colors[v] = c;
            if (colorGraph(graph, m, colors, v + 1, n))
                return 1;
            colors[v] = 0;
        }
    }
    return 0;
}

int main() {
    int n, m;
    int graph[MAX][MAX];
    int colors[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if (colorGraph(graph, m, colors, 0, n)) {
        printf("Color assignment:\n");
        for (int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n", i, colors[i]);
    } else {
        printf("No valid coloring possible with %d colors.\n", m);
    }

    printf("Backtracking explores solutions and prunes invalid states early.\n");

    /*
    Sample Input:
    4
    0 1 1 1
    1 0 1 0
    1 1 0 1
    1 0 1 0
    3

    Sample Output:
    Color assignment:
    Vertex 0 -> Color 1
    ...
    Backtracking explores solutions and prunes invalid states early.
    */

    return 0;
}