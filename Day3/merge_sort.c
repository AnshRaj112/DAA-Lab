#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables for counting comparisons and measuring time
long long comparisons = 0;
clock_t start_time, end_time;

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Free temporary arrays
    free(L);
    free(R);
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to read data from file
int readFromFile(const char *filename, int arr[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%d", &arr[count]) == 1 && count < 1000) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Function to write data to file
void writeToFile(const char *filename, int arr[], int n, long long comparisons) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Cannot create file %s\n", filename);
        return;
    }
    
    // Write the sorted array
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    
    // Write the number of comparisons at the end
    fprintf(file, "\nNumber of Comparisons: %lld", comparisons);
    
    fclose(file);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[1000];
    int n;
    int choice;
    
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    
    printf("Enter option: ");
    scanf("%d", &choice);
    
    char input_file[50], output_file[50];
    
    switch (choice) {
        case 1:
            strcpy(input_file, "inAsce.dat");
            strcpy(output_file, "outMergeAsce.dat");
            break;
        case 2:
            strcpy(input_file, "inDesc.dat");
            strcpy(output_file, "outMergeDesc.dat");
            break;
        case 3:
            strcpy(input_file, "inRand.dat");
            strcpy(output_file, "outMergeRand.dat");
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid option! Exiting...\n");
            return 1;
    }
    
    // Read data from input file
    n = readFromFile(input_file, arr);
    if (n == -1) {
        return 1;
    }
    
    printf("Before Sorting: ");
    printArray(arr, n);
    
    // Reset counters
    comparisons = 0;
    
    // Start timing
    start_time = clock();
    
    // Perform merge sort
    mergeSort(arr, 0, n - 1);
    
    // End timing
    end_time = clock();
    
    // Calculate execution time in nanoseconds
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    long long time_ns = (long long)(cpu_time_used * 1000000000);
    
    printf("After Sorting: ");
    printArray(arr, n);
    
    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %lld nanoseconds\n", time_ns);
    
    // Write sorted data to output file
    writeToFile(output_file, arr, n, comparisons);
    printf("Sorted data written to %s\n", output_file);
    
    return 0;
} 