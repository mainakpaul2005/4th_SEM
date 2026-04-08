#include<stdio.h>
#include<stdlib.h>

int main(){
    int mat1[100][100];
    int n = 0, i = 0, j = 0;
    int top = 0, bottom = 0, left = 0, right = 0;
    int value = 1;

    printf("Enter a number(1 to 100): ");
    scanf("%d",&n);

    if(n < 1 || n > 100){
        printf("Please enter between 1 and 100!!\n");
        return 1;
    }

    top = 0;
    bottom = n - 1;
    left = 0;
    right = n - 1;

    while(top <= bottom && left <= right){
        for(j = left; j <= right; j++){
            mat1[top][j] = value++;
        }
        top++;

        for(i = top; i <= bottom; i++){
            mat1[i][right] = value++;
        }
        right--;

        if(top <= bottom){
            for(j = right; j >= left; j--){
                mat1[bottom][j] = value++;
            }
            bottom--;
        }

        if(left <= right){
            for(i = bottom; i >= top; i--){
                mat1[i][left] = value++;
            }
            left++;
        }
    }


    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%4d",mat1[i][j]);
        }
        printf("\n");
    }

    return 0;
}