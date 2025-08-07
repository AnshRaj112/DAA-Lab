#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

long long comparison_count = 0;
int partition_count = 0;
int best_case_partitions = 0;
int worst_case_partitions = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparison_count++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    int left = i + 1 - low;
    int right = high - (i + 1);
    int total = high - low + 1;
    partition_count++;

    if (left <= total / 2 && right <= total / 2)
        best_case_partitions++;
    else
        worst_case_partitions++;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int readFromFile(const char* filename, int arr[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening %s\n", filename);
        return -1;
    }
    int count = 0;
    while (fscanf(file, "%d", &arr[count]) == 1 && count < MAX_SIZE)
        count++;
    fclose(file);
    return count;
}

void writeToFile(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    for (int i = 0; i < size; i++)
        fprintf(file, "%d ", arr[i]);
    fclose(file);
}

void printArray(int arr[], int size) {
    int display = (size > 20) ? 20 : size;
    for (int i = 0; i < display; i++)
        printf("%d ", arr[i]);
    if (size > 20)
        printf("... (showing first 20 elements, total: %d)", size);
    printf("\n");
}

void generateTestFiles() {
    FILE* f;
    int count;

    f = fopen("inQuickAsce.dat", "w");
    for (int i = 1; i <= 400; i++) fprintf(asce, "%d ", i * 10);
    fclose(f);

    f = fopen("inQuickDesc.dat", "w");
    for (int i = 400; i >= 1; i--) fprintf(desc, "%d ", i * 10);
    fclose(f);

    f = fopen("inQuickRand.dat", "w");
    count = 300 + rand() % 201;
    for (int i = 0; i < count; i++) fprintf(f, "%d ", rand() % 1000 + 1);
    fclose(f);
}

const char* determineScenario() {
    if (partition_count == 0) return "N/A";
    float best = (float)best_case_partitions / partition_count;
    float worst = (float)worst_case_partitions / partition_count;
    if (best > 0.7) return "Best-case";
    else if (worst > 0.7) return "Worst-case";
    else return "Mixed-case";
}

int main() {
    int arr[MAX_SIZE], size;
    srand(time(NULL));
    generateTestFiles();

    while (1) {
        printf("\nMAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n2. Descending Data\n3. Random Data\n4. EXIT\n");
        printf("Enter option: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 4) break;

        char in_file[50], out_file[50];
        if (choice == 1) {
            strcpy(in_file, "inAsce.dat");
            strcpy(out_file, "outQuickAsce.dat");
        } else if (choice == 2) {
            strcpy(in_file, "inDesc.dat");
            strcpy(out_file, "outQuickDesc.dat");
        } else if (choice == 3) {
            strcpy(in_file, "inRand.dat");
            strcpy(out_file, "outQuickRand.dat");
        } else {
            printf("Invalid choice!\n");
            continue;
        }

        size = readFromFile(in_file, arr);
        if (size == -1) continue;

        printf("\nBefore Sorting:\n");
        printArray(arr, size);

        comparison_count = 0;
        partition_count = 0;
        best_case_partitions = 0;
        worst_case_partitions = 0;

        quickSort(arr, 0, size - 1);

        printf("After Sorting:\n");
        printArray(arr, size);

        writeToFile(out_file, arr, size);

        printf("Comparisons: %lld\n", comparison_count);
        printf("Partitions: %d\n", partition_count);
        printf("Best-case Partitions: %d\n", best_case_partitions);
        printf("Worst-case Partitions: %d\n", worst_case_partitions);
        printf("Scenario: %s\n", determineScenario());
    }

    return 0;
}
