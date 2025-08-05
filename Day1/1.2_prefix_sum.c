#include <stdio.h>
#include <stdlib.h>

void calculatePrefixSum(int arr[], int prefixSum[], int n) {
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
}

void printArray(int arr[], int n, char *name) {
    printf("%s: ", name);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int arr[1000]; // Assuming max size of 1000
    int prefixSum[1000];
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Calculate prefix sum
    calculatePrefixSum(arr, prefixSum, n);
    
    // Display results
    printArray(arr, n, "Input Array");
    printArray(prefixSum, n, "Output Array");
    
    return 0;
} 