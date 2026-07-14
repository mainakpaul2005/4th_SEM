#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key);

    if (index == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", index);

    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1) for iterative binary search\n");

    /*
    Sample Input:
    5
    10 20 30 40 50
    30

    Sample Output:
    Element found at index 2.
    Time Complexity: O(log n)
    Space Complexity: O(1) for iterative binary search
    */

    return 0;
}