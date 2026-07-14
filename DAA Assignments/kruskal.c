#include <stdio.h>

#define MAX 20

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

int parent[MAX];

int findParent(int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent[node]);
    return parent[node];
}

void sortEdges(Edge edges[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m;
    Edge edges[MAX * MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter source destination weight for each edge:\n");
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(edges, m);

    int total = 0;
    int count = 0;

    printf("Kruskal's MST:\n");
    for (int i = 0; i < m && count < n - 1; i++) {
        int rootA = findParent(edges[i].src);
        int rootB = findParent(edges[i].dest);

        if (rootA != rootB) {
            printf("%d - %d : %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            parent[rootA] = rootB;
            total += edges[i].weight;
            count++;
        }
    }

    printf("Total cost = %d\n", total);
    printf("Kruskal generates a minimum spanning tree by selecting the lightest safe edges.\n");

    /*
    Sample Input:
    4
    5
    0 1 10
    0 2 6
    0 3 5
    1 3 15
    2 3 4

    Sample Output:
    Kruskal's MST:
    2 - 3 : 4
    0 - 3 : 5
    0 - 1 : 10
    Total cost = 19
    Kruskal generates a minimum spanning tree by selecting the lightest safe edges.
    */

    return 0;
}