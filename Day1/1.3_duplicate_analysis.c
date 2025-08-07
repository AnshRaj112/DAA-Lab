#include <stdio.h>
#include <stdlib.h>

void analyzeDuplicates(int arr[], int n) {
    int count[1000] = {0}; // Assuming elements are < 1000
    int totalDuplicates = 0;
    int mostRepeating = arr[0];
    int maxCount = 1;
    
    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Find total duplicates and most repeating element
    for (int i = 0; i < 1000; i++) {
        if (count[i] > 1) {
            totalDuplicates++;
        }
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostRepeating = i;
        }
    }
    
    printf("Total number of duplicate values = %d\n", totalDuplicates);
    printf("The most repeating element in the array = %d\n", mostRepeating);
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
    
    // Read size of array from first line
    fscanf(file, "%d", &n);
    
    // Read array elements
    printf("Reading %d elements from file:\n", n);
    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    fclose(file);
    
    // Analyze duplicates
    analyzeDuplicates(arr, n);
    
    return 0;
} 