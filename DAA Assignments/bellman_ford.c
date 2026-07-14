#include <stdio.h>

#define MAX 20
#define INF 99999

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void printDistances(int dist[], int n, int source) {
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> %d : Not Reachable\n", source, i);
        else
            printf("%d -> %d : %d\n", source, i, dist[i]);
    }
}

void bellmanFord(Edge edges[], int edgeCount, int n, int source) {
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected.\n");
            return;
        }
    }

    printf("Bellman-Ford shortest paths from %d:\n", source);
    printDistances(dist, n, source);
}

int main() {
    int n, edgeCount, source;
    Edge edges[MAX * MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of directed edges: ");
    scanf("%d", &edgeCount);

    printf("Enter source destination weight for each edge:\n");
    for (int i = 0; i < edgeCount; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(edges, edgeCount, n, source);
    printf("Bellman-Ford works with negative weights and can detect negative cycles.\n");

    /*
    Sample Input:
    5
    7
    0 1 6
    0 3 7
    1 2 5
    1 3 8
    1 4 -4
    2 1 -2
    3 4 9
    0

    Sample Output:
    Bellman-Ford shortest paths from 0:
    ...
    Bellman-Ford works with negative weights and can detect negative cycles.
    */

    return 0;
}