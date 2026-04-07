#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int* inserttionSORT(int* arr,int n);

int main(){
    int n = 0, i = 0;
    printf("Enter the no of elements: ");
    if (scanf("%d",&n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid input for number of elements.\n");
        return 1;
    }

    int* arr1 = malloc(sizeof(int) * n);
    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    printf("Enter the elements: ");
    for(i = 0; i < n; i++){
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Invalid element input.\n");
            free(arr1);
            return 1;
        }
    }

    int* arr2 = inserttionSORT(arr1,n);

    printf("The Sorted elements are: ");
    for(i = 0; i < n; i++){
        printf(" %d ",arr2[i]);
    }

    free(arr1);

    return 0;
}


int* inserttionSORT(int* arr,int n){
    int i = 0, j = 0, key = 0;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key)){
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }

    return arr;
}