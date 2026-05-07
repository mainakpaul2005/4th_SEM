#include<stdio.h>
#include<stdlib.h>

typedef struct Item {
    int value, weight;
}item;

int compare(const void *a, const void *b) {
    const item *i1 = (const item *)a;
    const item *i2 = (const item *)b;
    float r1 = (float)i1->value / i1->weight;
    float r2 = (float)i2->value / i2->weight;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    return 0;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1) return 0;

    item *items = (item *) malloc(n * sizeof(item));
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i+1);
        if (scanf("%d %d", &items[i].value, &items[i].weight) != 2) {
            free(items);
            return 0;
        }
    }

    printf("Enter knapsack capacity: ");
    if (scanf("%d", &W) != 1) {
        free(items);
        return 0;
    }

    qsort(items, n, sizeof(item), compare);

    int total = 0, curW = 0;
    for (int i = 0; i < n; i++) {
        if (curW + items[i].weight <= W) {
            curW += items[i].weight;
            total += items[i].value;
        }
    }

    printf("Maximum Profit Value = %d", total);
    free(items);
    return 0;
}
