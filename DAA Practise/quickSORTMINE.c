#include<stdio.h>
#include<stdlib.h>

void quickSORT(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void swap(int* a, int* b);


int main(){
    int n = 0, i = 0;

    printf("Enter the no of elements: ");
    scanf("%d",&n);

    int* arr1 = (int*) malloc(n * sizeof(int));

    printf("Enter the elements: \n");
    for(i = 0; i < n; i++){
        scanf("%d",&arr1[i]);
    }

    quickSORT(arr1, 0, n - 1);

    printf("Sorted Array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");

    free(arr1);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSORT(int* arr, int low, int high){
    int pi = 0;
    if(low < high){
        pi = partition(arr, low, high);
        quickSORT(arr, low, pi - 1);
        quickSORT(arr, pi + 1, high);
    }
}
