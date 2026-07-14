/*
Sample Input:
5 6
0 1 10
0 2 5
1 2 2
1 3 1
2 3 9
3 4 4

Sample Output:
CAMPUS NETWORK DESIGN OPTIMIZER
1. Display Network
2. BFS
3. Kruskal Optimization
...
*/

#include <stdio.h>

#define MAX 20
#define INF 99999

typedef struct {
    int src, dest, weight;
} Edge;

int graph[MAX][MAX], n, edgeCount, parent[MAX];
Edge edges[MAX * MAX];

void displayNetwork() {
    /* Show the graph as an adjacency matrix. */
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d ", graph[i][j]);
        printf("\n");
    }
}

int originalCost() {
    /* Add all input edge weights. */
    int cost = 0;
    for (int i = 0; i < edgeCount; i++)
        cost += edges[i].weight;
    return cost;
}

void bfs(int start) {
    /* Visit nodes level by level. */
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int next = 0; next < n; next++) {
            if (graph[current][next] && !visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
            }
        }
    }
    printf("\n");
}

int findParent(int node) {
    /* Find the root parent with path compression. */
    if (parent[node] != node)
        parent[node] = findParent(parent[node]);

    return parent[node];
}

void sortEdges() {
    /* Sort edges by weight for Kruskal's algorithm. */
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int kruskal() {
    /* Build the minimum cost network. */
    int totalCost = 0, selectedEdges = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges();

    printf("\nOptimized Network using Kruskal:\n");

    for (int i = 0; i < edgeCount && selectedEdges < n - 1; i++) {
        int rootA = findParent(edges[i].src);
        int rootB = findParent(edges[i].dest);

        if (rootA != rootB) {
            printf("%d <--> %d  Cost: %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            parent[rootA] = rootB;
            totalCost += edges[i].weight;
            selectedEdges++;
        }
    }

    if (selectedEdges != n - 1) {
        printf("Network is disconnected.\n");
        return -1;
    }

    printf("Minimum Cost = %d\n", totalCost);
    return totalCost;
}

void dijkstra(int source) {
    /* Find shortest paths from one source. */
    int distance[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        distance[i] = INF;

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDistance = INF;
        int current = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                current = i;
            }
        }

        if (current == -1)
            break;

        visited[current] = 1;

        for (int next = 0; next < n; next++) {
            if (!visited[next] &&
                graph[current][next] &&
                distance[current] + graph[current][next] < distance[next]) {

                distance[next] =
                    distance[current] + graph[current][next];
            }
        }
    }

    printf("\nShortest Paths from %d:\n", source);

    for (int i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("%d -> %d : Not Reachable\n", source, i);
        else
            printf("%d -> %d : %d\n", source, i, distance[i]);
    }
}

void floydWarshall() {
    /* Compute shortest paths between every pair of nodes. */
    int distance[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                distance[i][j] = 0;
            else if (graph[i][j])
                distance[i][j] = graph[i][j];
            else
                distance[i][j] = INF;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] + distance[k][j]
                    < distance[i][j]) {

                    distance[i][j] =
                        distance[i][k] + distance[k][j];
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Paths:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i][j] == INF)
                printf(" INF ");
            else
                printf("%4d ", distance[i][j]);
        }
        printf("\n");
    }
}

void compareNetwork() {
    /* Compare the original network with the optimized one. */
    int oldCost = originalCost();
    int newCost = kruskal();

    if (newCost == -1)
        return;

    int savings = oldCost - newCost;

    float reduction = oldCost ?
        (100.0 * savings / oldCost) : 0;

    printf("\n--- Network Comparison ---\n");
    printf("Original Connections : %d\n", edgeCount);
    printf("Optimized Connections: %d\n", n - 1);
    printf("Original Cost        : %d\n", oldCost);
    printf("Optimized Cost       : %d\n", newCost);
    printf("Cost Saved           : %d\n", savings);
    printf("Cost Reduction       : %.2f%%\n", reduction);
}

int main() {
    int choice, start;

    printf("CAMPUS NETWORK DESIGN OPTIMIZER\n");

    printf("Enter number of buildings and connections: ");
    scanf("%d %d", &n, &edgeCount);

    printf("Enter Source Destination Cost:\n");

    for (int i = 0; i < edgeCount; i++) {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);

        graph[edges[i].src][edges[i].dest] =
            edges[i].weight;

        graph[edges[i].dest][edges[i].src] =
            edges[i].weight;
    }

    do {
        /* Menu for graph operations. */
        printf("\n1. Display Network\n");
        printf("2. BFS\n");
        printf("3. Kruskal Optimization\n");
        printf("4. Dijkstra Shortest Path\n");
        printf("5. Floyd-Warshall\n");
        printf("6. Compare Network\n");
        printf("7. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayNetwork();
                break;

            case 2:
                printf("Start building: ");
                scanf("%d", &start);
                bfs(start);
                break;

            case 3:
                kruskal();
                break;

            case 4:
                printf("Source building: ");
                scanf("%d", &start);
                dijkstra(start);
                break;

            case 5:
                floydWarshall();
                break;

            case 6:
                compareNetwork();
                break;

            case 7:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}