#include<stdio.h>
#include<stdlib.h>

int main(){
    int size = 0;
    int i = 0;

    printf("Enter the no of elements: ");
    scanf("%d",&size);

    int* arr1 = (int*) malloc(size * sizeof(int)); //Integer ARRAY, use double/float in place of int for other types

    if (arr1 == NULL){
        printf("Memory Allocation Failed !!");
        return -1;
    }
    else{
        printf("Enter the elements:\n");
        for(i = 0; i < size; i++){
            scanf("%d",&arr1[i]);
        }

        printf("The Array received is: [");
        for(i = 0; i < size; i++){
            printf(" %d ",arr1[i]);
        }
        printf("]");
        return 0;
    }
}