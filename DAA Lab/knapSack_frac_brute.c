
#include <stdio.h>
#include <stdlib.h>

double fractionalKnapsackBruteForce(int n, double weights[], double values[], double capacity) {
	double totalValue = 0.0;
	int *used = (int *)calloc((size_t)n, sizeof(int));

	while (capacity > 0) {
		int bestIdx = -1;
		double maxRatio = -1.0;

		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				double ratio = values[i] / weights[i];
				if (ratio > maxRatio) {
					maxRatio = ratio;
					bestIdx = i;
				}
			}
		}

		if (bestIdx == -1) break;

		used[bestIdx] = 1;
		if (weights[bestIdx] <= capacity) {
			capacity -= weights[bestIdx];
			totalValue += values[bestIdx];
		} else {
			totalValue += values[bestIdx] * (capacity / weights[bestIdx]);
			capacity = 0;
		}
	}

	free(used);
	return totalValue;
}

int main() {
	int n;
	printf("Enter number of items: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	double *weights = (double *)malloc((size_t)n * sizeof(double));
	double *values = (double *)malloc((size_t)n * sizeof(double));

	if (weights == NULL || values == NULL) {
		free(weights);
		free(values);
		return 0;
	}

	printf("Enter weights of items: ");
	for (int i = 0; i < n; i++) {
		if (scanf("%lf", &weights[i]) != 1) {
			free(weights);
			free(values);
			return 0;
		}
	}

	printf("Enter values of items: ");
	for (int i = 0; i < n; i++) {
		if (scanf("%lf", &values[i]) != 1) {
			free(weights);
			free(values);
			return 0;
		}
	}

	double capacity;
	printf("Enter knapsack capacity: ");
	if (scanf("%lf", &capacity) != 1) {
		free(weights);
		free(values);
		return 0;
	}

	double maxValue = fractionalKnapsackBruteForce(n, weights, values, capacity);
	printf("Maximum value = %.2f\n", maxValue);

	free(weights);
	free(values);
	return 0;
}
