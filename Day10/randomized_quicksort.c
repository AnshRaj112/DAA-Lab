#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Randomized Quicksort

  Input format:
    n               (number of elements)
    a1 a2 ... an    (space-separated integers)

  Output:
    Sorted array in non-decreasing order.

  Expected time complexity:
    - The pivot is chosen uniformly at random, so the expected running time over
      all inputs is O(n log n). The expectation is taken over the algorithm's
      internal randomness and follows from linearity of expectation applied to
      the number of comparisons (or recursion balance).
    - Worst case remains O(n^2), but occurs with exponentially small probability
      for truly random pivots.
*/

static void swap_int_1653(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

static int partition_random_1653(int *arr, int low, int high) {
	int pivot_index = low + rand() % (high - low + 1);
	swap_int_1653(&arr[pivot_index], &arr[high]);
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j) {
		if (arr[j] <= pivot) {
			++i;
			swap_int_1653(&arr[i], &arr[j]);
		}
	}
	swap_int_1653(&arr[i + 1], &arr[high]);
	return i + 1;
}

static void randomized_quicksort_1653(int *arr, int low, int high) {
	while (low < high) {
		int p = partition_random_1653(arr, low, high);
		/* Tail recursion elimination: recurse on smaller side first */
		if (p - 1 - low < high - (p + 1)) {
			randomized_quicksort_1653(arr, low, p - 1);
			low = p + 1;
		} else {
			randomized_quicksort_1653(arr, p + 1, high);
			high = p - 1;
		}
	}
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1 || n < 0) {
		fprintf(stderr, "Invalid n\n");
		return 1;
	}
	int *arr = (int *)malloc((size_t)n * sizeof(int));
	if (!arr) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &arr[i]) != 1) {
			fprintf(stderr, "Invalid input at index %d\n", i);
			free(arr);
			return 1;
		}
	}

	srand((unsigned)time(NULL));
	randomized_quicksort_1653(arr, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");

	free(arr);
	return 0;
}


