#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax findMinMax(int arr[], int left, int right) {
    MinMax result;

    if (left == right) {
        result.min = arr[left];
        result.max = arr[left];
        return result;
    }

    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            result.min = arr[left];
            result.max = arr[right];
        } else {
            result.min = arr[right];
            result.max = arr[left];
        }
        return result;
    }

    int mid = left + (right - left) / 2;
    MinMax leftResult = findMinMax(arr, left, mid);
    MinMax rightResult = findMinMax(arr, mid + 1, right);

    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    MinMax result = findMinMax(arr, 0, n - 1);

    printf("Minimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);
    printf("Time Complexity: O(n)\n");

    /*
    Sample Input:
    6
    12 45 3 27 19 8

    Sample Output:
    Minimum element = 3
    Maximum element = 45
    Time Complexity: O(n)
    */

    return 0;
}