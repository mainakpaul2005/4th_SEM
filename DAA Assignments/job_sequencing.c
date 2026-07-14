#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compareJobs(const void *a, const void *b) {
    const Job *x = (const Job *)a;
    const Job *y = (const Job *)b;
    return y->profit - x->profit;
}

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];

    printf("Enter job id deadline profit for each job:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);

    qsort(jobs, n, sizeof(Job), compareJobs);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = 0;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == 0) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled jobs:\n");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != 0)
            printf("Slot %d -> Job %d\n", i, slot[i]);
    }

    printf("Maximum profit = %d\n", totalProfit);
    printf("Time Complexity: O(n log n) for sorting plus scheduling\n");

    /*
    Sample Input:
    4
    1 2 100
    2 1 19
    3 2 27
    4 1 25

    Sample Output:
    Scheduled jobs:
    Slot 1 -> Job 3
    Slot 2 -> Job 1
    Maximum profit = 127
    Time Complexity: O(n log n) for sorting plus scheduling
    */

    return 0;
}