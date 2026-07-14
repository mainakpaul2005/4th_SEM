#include <stdio.h>

#define MAX 20
#define INF 99999

void printDistances(int dist[], int n, int source) {
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> %d : Not Reachable\n", source, i);
        else
            printf("%d -> %d : %d\n", source, i, dist[i]);
    }
}

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Dijkstra shortest paths from %d:\n", source);
    printDistances(dist, n, source);
}

int main() {
    int n, edgeCount, source;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    printf("Enter number of directed edges: ");
    scanf("%d", &edgeCount);

    printf("Enter source destination weight for each edge:\n");
    for (int i = 0; i < edgeCount; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);
    printf("Dijkstra is suitable for graphs with non-negative edge weights.\n");

    /*
    Sample Input:
    5
    7
    0 1 6
    0 3 7
    1 2 5
    1 3 8
    1 4 4
    2 1 2
    3 4 9
    0

    Sample Output:
    Dijkstra shortest paths from 0:
    0 -> 0 : 0
    ...
    Dijkstra is suitable for graphs with non-negative edge weights.
    */

    return 0;
}