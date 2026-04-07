#include<stdio.h>
#include<stdlib.h>

void bubbsort(int* arr, int size){
    int i = 0, j = 0, temp = 0;
    for(i = 0; i < size; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int size = 0, sum = 0;
    int minpos_index = 0, maxneg_index = 0;
    int i = 0, max_neg = 0, min_pos = 0;

    printf("Enter the no of elements: ");
    scanf("%d",&size);

    if (size <= 0){
        printf("Invalid size\n");
        return -1;
    }

    int* arr1 = (int*) malloc(size * sizeof(int));

    if (arr1 == NULL){
        printf("Memory Allocation Failed !!");
        return -1;
    }
    else{
        printf("Enter the no of elements: ");
        for(i = 0; i < size; i++){
            scanf("%d",&arr1[i]);
        }
        
        bubbsort(arr1,size);

        for(i = 0; i < size; i++){
            if (arr1[i] > 0){
                min_pos = arr1[i];
                minpos_index = i;
                break;
            }
        }

        max_neg = arr1[0];
        maxneg_index = 0;

        while(minpos_index < size && maxneg_index < size && max_neg + min_pos < 0){
            arr1[maxneg_index] = 0;
            arr1[minpos_index] = 0;
            minpos_index += 1;
            maxneg_index += 1;

            if (minpos_index >= size || maxneg_index >= size){
                break;
            }

            max_neg = arr1[maxneg_index];
            min_pos = arr1[minpos_index];
        }

        for(i = 0; i < size; i++){
            sum += arr1[i];
        }
        
        printf("MAX Sum: %d",sum);

        free(arr1);

        return 0;
    }
}