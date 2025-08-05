#include <stdio.h>
#include <stdlib.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    if (p2 <= 1) return;
    
    // Store the last element
    int last = p1[p2 - 1];
    
    // Shift elements to the right
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i-1]);
    }
    
    // Put the last element at the beginning
    p1[0] = last;
}

void printArray(int arr[], int n, char *name) {
    printf("%s: ", name);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *file;
    int n;
    int arr[100]; // Assuming max size of 100
    
    // Open file for reading
    file = fopen("rotation_input.txt", "r");
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
    
    // Display array before rotation
    printArray(arr, n, "Before ROTATE");
    
    // Perform rotation
    ROTATE_RIGHT(arr, 5);
    
    // Display array after rotation
    printArray(arr, n, "After ROTATE");
    
    return 0;
} 