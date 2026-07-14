#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int weight;
} node;

int knapSack(node* arr, int n, int cap);

int main() {
    int n, cap;
    int max;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter capacity: ");
    scanf("%d", &cap);

    node* items = (node*) malloc(n * sizeof(node));

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    max = knapSack(items, n, cap);

    printf("Maximum Profit Value: %d\n", max);

    free(items);
    return 0;
}

int knapSack(node* arr, int n, int cap) {
    int maxProfit = 0;

    int totalCombo = 1;
    for (int i = 0; i < n; i++) {
        totalCombo *= 2;
    }

    int* pow2 = (int*)malloc(n * sizeof(int));
    pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    for (int i = 0; i < totalCombo; i++) {
        int totalWeight = 0;
        int totalValue = 0;

        for (int j = 0; j < n; j++) {
            if ((i / pow2[j]) % 2 == 1) {
                totalWeight += arr[j].weight;
                totalValue += arr[j].value;
            }
        }

        if (totalWeight <= cap && totalValue > maxProfit) {
            maxProfit = totalValue;
        }
    }

    free(pow2);
    return maxProfit;
}