#include <stdio.h>
#include <limits.h>

#define MAX 12
#define INF 99999

int n;
int cost[MAX][MAX];

int firstMin(int i) {
    int min = INF;
    for (int k = 0; k < n; k++)
        if (i != k && cost[i][k] < min)
            min = cost[i][k];
    return min;
}

int secondMin(int i) {
    int first = INF, second = INF;
    for (int j = 0; j < n; j++) {
        if (i == j)
            continue;
        if (cost[i][j] <= first) {
            second = first;
            first = cost[i][j];
        } else if (cost[i][j] < second) {
            second = cost[i][j];
        }
    }
    return second;
}

void tspBranchAndBound(int currBound, int currWeight, int level, int currPath[], int visited[], int *bestCost, int bestPath[]) {
    if (level == n) {
        if (cost[currPath[level - 1]][currPath[0]] != INF) {
            int currRes = currWeight + cost[currPath[level - 1]][currPath[0]];
            if (currRes < *bestCost) {
                *bestCost = currRes;
                for (int i = 0; i < n; i++)
                    bestPath[i] = currPath[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (cost[currPath[level - 1]][i] != INF && !visited[i]) {
            int tempBound = currBound;
            int tempWeight = currWeight + cost[currPath[level - 1]][i];

            if (level == 1)
                tempBound -= (firstMin(currPath[level - 1]) + firstMin(i)) / 2;
            else
                tempBound -= (secondMin(currPath[level - 1]) + firstMin(i)) / 2;

            if (tempWeight + tempBound < *bestCost) {
                currPath[level] = i;
                visited[i] = 1;
                tspBranchAndBound(tempBound, tempWeight, level + 1, currPath, visited, bestCost, bestPath);
            }

            visited[i] = 0;
        }
    }
}

void tspDP() {
    int dp[1 << MAX][MAX];

    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = INF;

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)))
                continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v))
                    continue;
                if (cost[u][v] != INF) {
                    int nextMask = mask | (1 << v);
                    if (dp[mask][u] + cost[u][v] < dp[nextMask][v])
                        dp[nextMask][v] = dp[mask][u] + cost[u][v];
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        if (cost[i][0] != INF && dp[(1 << n) - 1][i] != INF) {
            int value = dp[(1 << n) - 1][i] + cost[i][0];
            if (value < ans)
                ans = value;
        }
    }

    printf("\nTSP using Dynamic Programming\n");
    if (ans == INF)
        printf("No Hamiltonian tour found.\n");
    else
        printf("Minimum tour cost = %d\n", ans);
}

void tspBB() {
    int visited[MAX] = {0};
    int currPath[MAX], bestPath[MAX];
    int bestCost = INF;
    int currBound = 0;

    for (int i = 0; i < n; i++)
        currBound += firstMin(i) + secondMin(i);
    currBound = (currBound % 2 == 0) ? currBound / 2 : currBound / 2 + 1;

    visited[0] = 1;
    currPath[0] = 0;

    tspBranchAndBound(currBound, 0, 1, currPath, visited, &bestCost, bestPath);

    printf("\nTSP using Branch and Bound\n");
    if (bestCost == INF)
        printf("No Hamiltonian tour found.\n");
    else {
        printf("Minimum tour cost = %d\n", bestCost);
        printf("Tour: ");
        for (int i = 0; i < n; i++)
            printf("%d -> ", bestPath[i]);
        printf("0\n");
    }
}

int main() {
    int choice;

    printf("Enter number of cities (max 12): ");
    scanf("%d", &n);

    printf("Enter cost matrix using 99999 for no edge:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j)
                cost[i][j] = INF;
        }
    }

    printf("1. Dynamic Programming\n");
    printf("2. Branch and Bound\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        tspDP();
    else if (choice == 2)
        tspBB();
    else
        printf("Invalid choice.\n");

    printf("TSP is exponential in general, so exact methods are practical only for small n.\n");

    /*
    Sample Input:
    4
    99999 10 15 20
    10 99999 35 25
    15 35 99999 30
    20 25 30 99999
    1

    Sample Output:
    TSP using Dynamic Programming
    Minimum tour cost = 80
    TSP is exponential in general, so exact methods are practical only for small n.

    Sample Input:
    4
    99999 10 15 20
    10 99999 35 25
    15 35 99999 30
    20 25 30 99999
    2

    Sample Output:
    TSP using Branch and Bound
    Minimum tour cost = 80
    Tour: 0 -> ... -> 0
    TSP is exponential in general, so exact methods are practical only for small n.
    */

    return 0;
}