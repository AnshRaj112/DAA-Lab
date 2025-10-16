# Day 4 - Heap Data Structure Program

## Overview
This program implements a menu-driven heap data structure for managing person records. It supports both min-heap (based on age) and max-heap (based on weight) operations.

## Person Structure
```c
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
```

## Features

### 1. Read Data
- Reads person data from `persons_data.txt` file
- If file doesn't exist, creates a sample data file with 7 persons
- Automatically allocates memory for dynamic array

### 2. Create Min-heap (Age-based)
- Builds a min-heap where the youngest person is at the root
- Uses heapify algorithm to maintain heap property
- Displays the resulting heap structure

### 3. Create Max-heap (Weight-based)
- Builds a max-heap where the heaviest person is at the root
- Uses heapify algorithm to maintain heap property
- Displays the resulting heap structure

### 4. Display Youngest Person's Weight
- Finds the person with minimum age
- Converts weight from pounds to kilograms
- Shows detailed information about the youngest person

### 5. Insert New Person
- Adds a new person to the current heap
- Automatically rebuilds heap to maintain property
- Supports both min-heap and max-heap modes

### 6. Delete Oldest Person
- Removes the person with maximum age
- Rebuilds heap after deletion
- Frees allocated memory properly

## Menu Options
```
MAIN MENU (HEAP)
1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit
```

## Sample Data
The program creates a sample data file with the following persons:
- Adarsh Hota (ID: 0, Age: 39, Height: 77, Weight: 231)
- Levi Maier (ID: 1, Age: 56, Height: 77, Weight: 129)
- Priya Kumari (ID: 2, Age: 63, Height: 78, Weight: 240)
- Dorothy Helton (ID: 3, Age: 47, Height: 72, Weight: 229)
- Florence Smith (ID: 4, Age: 24, Height: 75, Weight: 171)
- Erica Anyan (ID: 5, Age: 38, Height: 73, Weight: 102)
- Norma Webster (ID: 6, Age: 23, Height: 75, Weight: 145)

## Compilation and Usage

### Compile
```bash
make
# or
make heap_program
```

### Run
```bash
make test
# or
./heap_program
```

### Clean
```bash
make clean
```

### Help
```bash
make help
```

## Implementation Details

### Heap Operations
- **Heapify**: Maintains heap property by recursively swapping elements
- **Build Heap**: Converts array to heap by calling heapify on non-leaf nodes
- **Insert**: Adds element and rebuilds heap
- **Delete**: Removes element and rebuilds heap

### Memory Management
- Dynamic allocation for person array
- Proper memory cleanup on exit
- String memory management for names

### File I/O
- Automatic file creation if not exists
- Error handling for file operations
- Structured data parsing

## Notes
- All function names include `_1653` suffix as required
- Weight conversion: 1 pound = 0.453592 kg
- Heap size is limited to 1000 persons
- Names are limited to 100 characters
- The program handles both min-heap and max-heap modes dynamically
