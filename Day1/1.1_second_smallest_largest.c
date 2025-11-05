#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void findSecondMinMax_1653(int arr[], int n, int *secondMin, int *secondMax) {
    if (n < 2) {
        printf("Array must have at least 2 elements\n");
        return;
    }
    
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        // Find second minimum
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
        
        // Find second maximum
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    
    *secondMin = min2;
    *secondMax = max2;
}

int main() {
    FILE *file;
    int n;
    int arr[1000]; // Assuming max size of 1000
    
    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Read size of array
    fscanf(file, "%d", &n);
    
    // Read array elements
    printf("Reading %d elements from file:\n", n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    fclose(file);
    
    int secondMin, secondMax;
    findSecondMinMax_1653(arr, n, &secondMin, &secondMax);
    
    printf("Second smallest element: %d\n", secondMin);
    printf("Second largest element: %d\n", secondMax);
    
    return 0;
} 