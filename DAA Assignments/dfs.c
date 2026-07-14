#include <stdio.h>

#define MAX 100

void dfsUtil(int graph[MAX][MAX], int n, int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i])
            dfsUtil(graph, n, i, visited);
    }
}

void dfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfsUtil(graph, n, start, visited);
    printf("\n");
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dfs(graph, n, start);
    printf("Time Complexity: O(V + E)\n");

    /*
    Sample Input:
    4
    0 1 1 0
    1 0 0 1
    1 0 0 1
    0 1 1 0
    0

    Sample Output:
    DFS Traversal: 0 1 3 2
    Time Complexity: O(V + E)
    */

    return 0;
}