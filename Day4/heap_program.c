#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PERSONS 1000

// Person structure as specified
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Global variables
struct person *persons = NULL;
int heap_size = 0;
int total_persons = 0;
int is_min_heap = 0; // 0 for max-heap, 1 for min-heap

// Function prototypes
void readData_1653();
void createMinHeap_1653();
void createMaxHeap_1653();
void displayYoungestWeight_1653();
void insertPerson_1653();
void deleteOldest_1653();
void heapify_1653(int index);
void swapPersons_1653(int i, int j);
void displayHeap_1653();
void freeMemory_1653();
void saveCurrentData_1653();

// Swap two persons in the array
void swapPersons_1653(int i, int j) {
    struct person temp = persons[i];
    persons[i] = persons[j];
    persons[j] = temp;
}

// Heapify function to maintain heap property
void heapify_1653(int index) {
    int target = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (is_min_heap) {
        // Min-heap based on age - find smallest
        if (left < heap_size && persons[left].age < persons[target].age)
            target = left;
        if (right < heap_size && persons[right].age < persons[target].age)
            target = right;
    } else {
        // Max-heap based on weight - find largest
        if (left < heap_size && persons[left].weight > persons[target].weight)
            target = left;
        if (right < heap_size && persons[right].weight > persons[target].weight)
            target = right;
    }
    
    if (target != index) {
        swapPersons_1653(index, target);
        heapify_1653(target);
    }
}

// Build heap from array
void buildHeap_1653() {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        heapify_1653(i);
    }
}

// Read data from CSV file
void readData_1653() {
    // If we already have data (including inserted persons), just display it
    if (persons != NULL && total_persons > 0) {
        printf("Current data (including newly inserted persons):\n");
        printf("Total persons: %d\n", total_persons);
        printf("Id\tName\t\t\tAge\tHeight\tWeight(pound)\n");
        for (int i = 0; i < total_persons; i++) {
            printf("%d\t%s\t\t%d\t%d\t%d\n", 
                   persons[i].id, persons[i].name, persons[i].age, 
                   persons[i].height, persons[i].weight);
        }
        
        // Create output CSV for current data
        FILE *csv_out = fopen("01_original_data_output.csv", "w");
        if (csv_out != NULL) {
            fprintf(csv_out, "ID,Name,Age,Height,Weight_Pounds\n");
            for (int i = 0; i < total_persons; i++) {
                fprintf(csv_out, "%d,%s,%d,%d,%d\n", 
                       persons[i].id, persons[i].name, persons[i].age, 
                       persons[i].height, persons[i].weight);
            }
            fclose(csv_out);
            printf("Output CSV created: 01_original_data_output.csv\n");
        }
        return;
    }
    
    // First time reading - load from CSV file
    FILE *file = fopen("input_data.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open input_data.csv\n");
        return;
    }
    
    // Allocate memory for persons
    persons = (struct person *)malloc(MAX_PERSONS * sizeof(struct person));
    if (persons == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return;
    }
    
    total_persons = 0;
    char line[256];
    
    // Skip header line
    fgets(line, sizeof(line), file);
    
    while (fgets(line, sizeof(line), file) && total_persons < MAX_PERSONS) {
        char *token = strtok(line, ",\n");
        if (token == NULL) continue;
        
        persons[total_persons].id = atoi(token);
        
        token = strtok(NULL, ",\n");
        if (token == NULL) continue;
        
        persons[total_persons].name = (char *)malloc(MAX_NAME_LENGTH);
        strcpy(persons[total_persons].name, token);
        
        token = strtok(NULL, ",\n");
        if (token == NULL) continue;
        persons[total_persons].age = atoi(token);
        
        token = strtok(NULL, ",\n");
        if (token == NULL) continue;
        persons[total_persons].height = atoi(token);
        
        token = strtok(NULL, ",\n");
        if (token == NULL) continue;
        persons[total_persons].weight = atoi(token);
        
        total_persons++;
    }
    
    fclose(file);
    heap_size = total_persons;
    
    // Create output CSV for original data
    FILE *csv_out = fopen("01_original_data_output.csv", "w");
    if (csv_out != NULL) {
        fprintf(csv_out, "ID,Name,Age,Height,Weight_Pounds\n");
        for (int i = 0; i < total_persons; i++) {
            fprintf(csv_out, "%d,%s,%d,%d,%d\n", 
                   persons[i].id, persons[i].name, persons[i].age, 
                   persons[i].height, persons[i].weight);
        }
        fclose(csv_out);
        printf("Output CSV created: 01_original_data_output.csv\n");
    }
    
    printf("Data read successfully. Total persons: %d\n", total_persons);
    printf("Id\tName\t\t\tAge\tHeight\tWeight(pound)\n");
    for (int i = 0; i < total_persons; i++) {
        printf("%d\t%s\t\t%d\t%d\t%d\n", 
               persons[i].id, persons[i].name, persons[i].age, 
               persons[i].height, persons[i].weight);
    }
}

// Create min-heap based on age
void createMinHeap_1653() {
    if (persons == NULL) {
        printf("Error: No data loaded. Please read data first.\n");
        return;
    }
    
    is_min_heap = 1;
    heap_size = total_persons;
    buildHeap_1653();
    
    // Create output CSV for min-heap
    FILE *csv_out = fopen("02_min_heap_age_output.csv", "w");
    if (csv_out != NULL) {
        fprintf(csv_out, "Heap_Index,ID,Name,Age,Height,Weight_Pounds,Heap_Level\n");
        for (int i = 0; i < heap_size; i++) {
            char *level;
            if (i == 0) level = "Root";
            else if (i < 3) level = "Level_1";
            else level = "Level_2";
            
            fprintf(csv_out, "%d,%d,%s,%d,%d,%d,%s\n", 
                   i, persons[i].id, persons[i].name, persons[i].age, 
                   persons[i].height, persons[i].weight, level);
        }
        fclose(csv_out);
        printf("Output CSV created: 02_min_heap_age_output.csv\n");
    }
    
    printf("Min-heap created successfully based on age.\n");
    displayHeap_1653();
}

// Create max-heap based on weight
void createMaxHeap_1653() {
    if (persons == NULL) {
        printf("Error: No data loaded. Please read data first.\n");
        return;
    }
    
    is_min_heap = 0;
    heap_size = total_persons;
    buildHeap_1653();
    
    // Create output CSV for max-heap
    FILE *csv_out = fopen("03_max_heap_weight_output.csv", "w");
    if (csv_out != NULL) {
        fprintf(csv_out, "Heap_Index,ID,Name,Age,Height,Weight_Pounds,Heap_Level\n");
        for (int i = 0; i < heap_size; i++) {
            char *level;
            if (i == 0) level = "Root";
            else if (i < 3) level = "Level_1";
            else level = "Level_2";
            
            fprintf(csv_out, "%d,%d,%s,%d,%d,%d,%s\n", 
                   i, persons[i].id, persons[i].name, persons[i].age, 
                   persons[i].height, persons[i].weight, level);
        }
        fclose(csv_out);
        printf("Output CSV created: 03_max_heap_weight_output.csv\n");
    }
    
    printf("Max-heap created successfully based on weight.\n");
    displayHeap_1653();
}

// Display weight of youngest person
void displayYoungestWeight_1653() {
    if (persons == NULL || heap_size == 0) {
        printf("Error: No data available.\n");
        return;
    }
    
    int youngest_index = 0;
    int youngest_age = persons[0].age;
    
    for (int i = 1; i < heap_size; i++) {
        if (persons[i].age < youngest_age) {
            youngest_age = persons[i].age;
            youngest_index = i;
        }
    }
    
    // Convert pounds to kg (1 pound = 0.453592 kg)
    double weight_kg = persons[youngest_index].weight * 0.453592;
    
    // Create output CSV for youngest person analysis
    FILE *csv_out = fopen("04_youngest_person_output.csv", "w");
    if (csv_out != NULL) {
        fprintf(csv_out, "Analysis_Type,Value,Unit,Details\n");
        fprintf(csv_out, "Youngest_Person_ID,%d,ID,Person with minimum age\n", persons[youngest_index].id);
        fprintf(csv_out, "Youngest_Person_Name,%s,Name,Full name of youngest person\n", persons[youngest_index].name);
        fprintf(csv_out, "Youngest_Person_Age,%d,Years,Minimum age in the dataset\n", persons[youngest_index].age);
        fprintf(csv_out, "Youngest_Person_Height,%d,Inches,Height of youngest person\n", persons[youngest_index].height);
        fprintf(csv_out, "Youngest_Person_Weight_Pounds,%d,Pounds,Weight in pounds\n", persons[youngest_index].weight);
        fprintf(csv_out, "Youngest_Person_Weight_KG,%.2f,Kilograms,Converted weight\n", weight_kg);
        fprintf(csv_out, "Weight_Conversion_Factor,0.453592,KG/Pound,Standard conversion factor\n");
        fclose(csv_out);
        printf("Output CSV created: 04_youngest_person_output.csv\n");
    }
    
    printf("Weight of youngest student: %.2f kg\n", weight_kg);
    printf("Youngest person: %s (Age: %d, Weight: %d pounds)\n", 
           persons[youngest_index].name, persons[youngest_index].age, 
           persons[youngest_index].weight);
}

// Insert a new person into the min-heap
void insertPerson_1653() {
    if (persons == NULL) {
        printf("Error: No data loaded. Please read data first.\n");
        return;
    }
    
    if (heap_size >= MAX_PERSONS) {
        printf("Error: Heap is full.\n");
        return;
    }
    
    struct person new_person;
    
    printf("Enter person details:\n");
    printf("ID: ");
    scanf("%d", &new_person.id);
    
    new_person.name = (char *)malloc(MAX_NAME_LENGTH);
    printf("Name: ");
    scanf(" %[^\n]s", new_person.name);
    
    printf("Age: ");
    scanf("%d", &new_person.age);
    
    printf("Height: ");
    scanf("%d", &new_person.height);
    
    printf("Weight: ");
    scanf("%d", &new_person.weight);
    
    // Add to heap
    persons[heap_size] = new_person;
    heap_size++;
    total_persons++; // Update total_persons to include new person
    
    // Rebuild heap
    if (is_min_heap) {
        buildHeap_1653();
        printf("Person inserted into min-heap successfully.\n");
    } else {
        buildHeap_1653();
        printf("Person inserted into max-heap successfully.\n");
    }
    
    // Create output CSV for insert operation
    FILE *csv_out = fopen("05_insert_person_output.csv", "w");
    if (csv_out != NULL) {
        fprintf(csv_out, "Operation,ID,Name,Age,Height,Weight_Pounds,Heap_Type,Heap_Size\n");
        fprintf(csv_out, "New_Person,%d,%s,%d,%d,%d,%s,%d\n", 
               new_person.id, new_person.name, new_person.age, 
               new_person.height, new_person.weight, 
               is_min_heap ? "Min_Heap_Age" : "Max_Heap_Weight", heap_size);
        
        for (int i = 0; i < heap_size; i++) {
            fprintf(csv_out, "Heap_Element,%d,%s,%d,%d,%d,%s,%d\n", 
                   persons[i].id, persons[i].name, persons[i].age, 
                   persons[i].height, persons[i].weight, 
                   is_min_heap ? "Min_Heap_Age" : "Max_Heap_Weight", heap_size);
        }
        fclose(csv_out);
        printf("Output CSV created: 05_insert_person_output.csv\n");
    }
    
    displayHeap_1653();
}

// Delete the oldest person
void deleteOldest_1653() {
    if (persons == NULL || heap_size == 0) {
        printf("Error: No data available.\n");
        return;
    }
    
    int oldest_index = 0;
    int oldest_age = persons[0].age;
    
    for (int i = 1; i < heap_size; i++) {
        if (persons[i].age > oldest_age) {
            oldest_age = persons[i].age;
            oldest_index = i;
        }
    }
    
    printf("Deleting oldest person: %s (Age: %d)\n", 
           persons[oldest_index].name, persons[oldest_index].age);
    
    // Free the name memory
    free(persons[oldest_index].name);
    
    // Move last element to the deleted position
    persons[oldest_index] = persons[heap_size - 1];
    heap_size--;
    
    // Rebuild heap
    if (is_min_heap) {
        buildHeap_1653();
        printf("Oldest person deleted from min-heap successfully.\n");
    } else {
        buildHeap_1653();
        printf("Oldest person deleted from max-heap successfully.\n");
    }
    
    // Create output CSV for delete operation
    FILE *csv_out = fopen("06_delete_oldest_output.csv", "w");
    if (csv_out != NULL) {
        fprintf(csv_out, "Operation,ID,Name,Age,Height,Weight_Pounds,Heap_Type,Heap_Size,Action\n");
        fprintf(csv_out, "Deleted_Person,%d,%s,%d,%d,%d,%s,%d,DELETED\n", 
               persons[oldest_index].id, persons[oldest_index].name, persons[oldest_index].age, 
               persons[oldest_index].height, persons[oldest_index].weight, 
               is_min_heap ? "Min_Heap_Age" : "Max_Heap_Weight", heap_size);
        
        for (int i = 0; i < heap_size; i++) {
            fprintf(csv_out, "Remaining_Element,%d,%s,%d,%d,%d,%s,%d,Keep\n", 
                   persons[i].id, persons[i].name, persons[i].age, 
                   persons[i].height, persons[i].weight, 
                   is_min_heap ? "Min_Heap_Age" : "Max_Heap_Weight", heap_size);
        }
        fclose(csv_out);
        printf("Output CSV created: 06_delete_oldest_output.csv\n");
    }
    
    displayHeap_1653();
}

// Display the current heap
void displayHeap_1653() {
    if (persons == NULL || heap_size == 0) {
        printf("No data to display.\n");
        return;
    }
    
    printf("\nCurrent Heap (%s):\n", is_min_heap ? "Min-heap by Age" : "Max-heap by Weight");
    printf("Id\tName\t\t\tAge\tHeight\tWeight(pound)\n");
    
    for (int i = 0; i < heap_size; i++) {
        printf("%d\t%s\t\t%d\t%d\t%d\n", 
               persons[i].id, persons[i].name, persons[i].age, 
               persons[i].height, persons[i].weight);
    }
    printf("Heap size: %d\n", heap_size);
}

// Free allocated memory
void freeMemory_1653() {
    if (persons != NULL) {
        for (int i = 0; i < total_persons; i++) {
            if (persons[i].name != NULL) {
                free(persons[i].name);
            }
        }
        free(persons);
        persons = NULL;
    }
    total_persons = 0;
    heap_size = 0;
}

// Save current data (including inserted persons) to CSV
void saveCurrentData_1653() {
    if (persons == NULL || total_persons == 0) {
        printf("Error: No data available to save.\n");
        return;
    }
    
    FILE *csv_out = fopen("07_current_data_with_insertions.csv", "w");
    if (csv_out != NULL) {
        fprintf(csv_out, "ID,Name,Age,Height,Weight_Pounds,Status\n");
        for (int i = 0; i < total_persons; i++) {
            char *status = (i < 7) ? "Original" : "Inserted";
            fprintf(csv_out, "%d,%s,%d,%d,%d,%s\n", 
                   persons[i].id, persons[i].name, persons[i].age, 
                   persons[i].height, persons[i].weight, status);
        }
        fclose(csv_out);
        printf("Current data saved to: 07_current_data_with_insertions.csv\n");
        printf("Total persons: %d (Original: 7, Inserted: %d)\n", 
               total_persons, total_persons - 7);
    }
}

int main() {
    int choice;
    
    printf("=== HEAP DATA STRUCTURE PROGRAM ===\n");
    
    while (1) {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Save current data to CSV\n");
        printf("8. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readData_1653();
                break;
            case 2:
                createMinHeap_1653();
                break;
            case 3:
                createMaxHeap_1653();
                break;
            case 4:
                displayYoungestWeight_1653();
                break;
            case 5:
                insertPerson_1653();
                break;
            case 6:
                deleteOldest_1653();
                break;
            case 7:
                saveCurrentData_1653();
                break;
            case 8:
                printf("Exiting program...\n");
                freeMemory_1653();
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}
