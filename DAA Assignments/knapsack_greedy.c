#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int profit;
    double ratio;
    int index;
} Item;

int compareItems(const void *a, const void *b) {
    const Item *x = (const Item *)a;
    const Item *y = (const Item *)b;

    if (x->ratio < y->ratio)
        return 1;
    if (x->ratio > y->ratio)
        return -1;
    return 0;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter weight and profit for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (double)items[i].profit / items[i].weight;
        items[i].index = i + 1;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    qsort(items, n, sizeof(Item), compareItems);

    int totalWeight = 0;
    int totalProfit = 0;

    printf("Selected items using greedy ratio rule:\n");
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("Item %d -> weight=%d profit=%d ratio=%.2f\n",
                   items[i].index, items[i].weight, items[i].profit, items[i].ratio);
        }
    }

    printf("Total weight = %d\n", totalWeight);
    printf("Total profit  = %d\n", totalProfit);
    printf("Analysis: this greedy solution is not guaranteed to be optimal for 0/1 knapsack.\n");
    printf("Time Complexity: O(n log n) due to sorting\n");

    /*
    Sample Input:
    3
    10 60
    20 100
    30 120
    50

    Sample Output:
    Selected items using greedy ratio rule:
    Item 1 -> weight=10 profit=60 ratio=6.00
    Item 2 -> weight=20 profit=100 ratio=5.00
    Item 3 -> weight=30 profit=120 ratio=4.00
    Total weight = 50
    Total profit  = 280
    Analysis: this greedy solution is not guaranteed to be optimal for 0/1 knapsack.
    */

    return 0;
}