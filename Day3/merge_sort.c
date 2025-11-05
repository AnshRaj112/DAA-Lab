#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

long long comparison_count = 0;

void merge_1653(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    i = 0; j = 0; k = left;
    
    while (i < n1 && j < n2) {
        comparison_count++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort_1653(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort_1653(arr, left, mid);
        mergeSort_1653(arr, mid + 1, right);
        merge_1653(arr, left, mid, right);
    }
}

int readFromFile_1653(const char* filename, int arr[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%d", &arr[count]) == 1 && count < MAX_SIZE) count++;
    fclose(file);
    return count;
}

void writeToFile_1653(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Cannot create file %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) fprintf(file, "%d ", arr[i]);
    fclose(file);
}

void printArray_1653(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void generateTestFiles_1653() {
    FILE* asce = fopen("inAsce.dat", "w");
    for (int i = 1; i <= 400; i++) fprintf(asce, "%d ", i * 10);
    fclose(asce);

    FILE* desc = fopen("inDesc.dat", "w");
    for (int i = 400; i >= 1; i--) fprintf(desc, "%d ", i * 10);
    fclose(desc);

    FILE* randf = fopen("inRand.dat", "w");
    srand(time(NULL));
    for (int i = 0; i < 350; i++) fprintf(randf, "%d ", rand() % 1000 + 1);
    fclose(randf);
}

int main() {
    int arr[MAX_SIZE], size;

    generateTestFiles_1653();

    while (1) {
        printf("\nMAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }

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
            default:
                printf("Invalid option! Please try again.\n");
                continue;
        }

        size = readFromFile_1653(input_file, arr);
        if (size == -1) continue;

        printf("\nBefore Sorting:\n");
        printArray_1653(arr, size);

        comparison_count = 0;

        mergeSort_1653(arr, 0, size - 1);

        printf("After Sorting:\n");
        printArray_1653(arr, size);

        writeToFile_1653(output_file, arr, size);

        printf("Number of Comparisons: %lld\n", comparison_count);
    }

    return 0;
}
