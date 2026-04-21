#include<stdio.h>
#include<stdlib.h>

void mergeSORT(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

int main(){
    int n = 0, i = 0;

    int right = 0, mid = 0, left = 0;

    printf("Enter the no of elements: ");
    scanf("%d",&n);

    int* arr1 = (int*) malloc(n * sizeof(int));

    if(arr1 == NULL){
        printf("Memory Allocation Failed !!");
        return -1;
    }
    else{

        printf("Enter the elements: \n");
        for(i = 0; i < n; i++){
            scanf("%d",&arr1[i]);
        }

        left = 0;
        right = n - 1;
        mid = (left + right)/2;

        mergeSORT(arr1, left, right);

        printf("Sorted Array: \n");
        for(i = 0; i < n; i++){
            printf("%d ",arr1[i]);
        }
        free(arr1);
        return 0;
    }
}

void merge(int* arr, int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++){
        L[i] = arr[i + left];
    }
    for(j = 0; j < n2; j++){
        R[j] = arr[mid + j + 1];
    }

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSORT(int* arr, int left, int right){
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSORT(arr, left, mid);
        mergeSORT(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
