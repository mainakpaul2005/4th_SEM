#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
	int n = 0, max_neg = 0, min_pos = 0;
	int i = 0, max_n_i = 0, min_p_i = 0;
	int j = 0, sum = 0;

	printf("Enter the no of elements: ");
	scanf("%d",&n);
	
	int* arr1 = (int*) malloc(n * sizeof(int));
	
	if(arr1 == NULL){
		printf("Memory Allocation Failed !!");
		return -1;
	}
	else{
		printf("Enter the elements: ");
		for(i = 0; i < n ; i++){
			scanf("%d",&arr1[i]);
		}

		qsort(arr1, n, sizeof(int), compare);

		for(i = 0; i < n; i++){
			if(arr1[i] >= 0){
				min_pos = arr1[i];
				min_p_i = i;
				break;
			}
		}

		while((arr1[j] + arr1[min_p_i]) < 0 ){
			arr1[j] = 0;
			arr1[min_p_i] = 0;
			j += 1;
			min_p_i += 1;

		}
		
		for(i = 0; i < n; i++){
			sum += arr1[i];
		}
		printf("MAX Sum: %d",sum);
		return 0;
	}
}
