#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	int weight;
}node;

int compare(const void *a, const void *b) {
    const node *i1 = (const node *)a;
    const node *i2 = (const node *)b;

    float r1 = (float)i1->value / i1->weight;
    float r2 = (float)i2->value / i2->weight;

    return (r2 > r1) - (r2 < r1);
}

int main(){
	int n = 0, i = 0;
	int curW = 0;
	int cap = 0, remain = 0;
	float max = 0;

	printf("Enter the no of items: ");
	scanf("%d",&n);

	node* items = (node*) malloc(n * sizeof(node));

	for(i = 0; i < n; i++){
		printf("Enter the value and weight of item %d:",i);
		scanf("%d %d",&items[i].value,&items[i].weight);
	}

	printf("Enter the MAX capacity: ");
	scanf("%d",&cap);

	qsort(items, n, sizeof(node), compare);

	for(i = 0; i < n; i++){
		if( curW + items[i].weight <= cap){
			max = max + items[i].value;
			curW = curW + items[i].weight;
		}
		else{
			remain = cap - curW;
			max = max + ((float)items[i].value / items[i].weight) * remain;
		}
	}
	
	printf("Maximum Profit Value: %f",max);
	free(items);
	return 0;
}
