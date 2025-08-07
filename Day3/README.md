# Day 3: Sorting Algorithms Implementation

## Program Description

This directory contains two menu-driven sorting programs:
1. **Merge Sort Implementation** - A traditional merge sort algorithm
2. **Quick Sort Implementation** - A quick sort algorithm with partitioning analysis

Both programs read data from different input files, sort the elements using their respective techniques, and provide detailed analysis of the sorting process.

## Quick Sort Program Features

- **Menu-driven interface** with options for different data types
- **Quick sort algorithm** implementation with partitioning analysis
- **Comparison counting** to track the number of comparisons made during sorting
- **Partitioning scenario analysis** to determine best-case vs worst-case behavior
- **File I/O operations** for reading input and writing sorted output
- **Automatic test file generation** for different data patterns (300-500 elements)

## Merge Sort Program Features

- **Menu-driven interface** with options for different data types
- **Merge sort algorithm** implementation with O(n log n) time complexity
- **Execution time measurement** in nanoseconds using high-precision timing
- **Comparison counting** to track the number of comparisons made during sorting
- **File I/O operations** for reading input and writing sorted output
- **Automatic test file generation** for different data patterns

## Features

- **Menu-driven interface** with options for different data types
- **Merge sort algorithm** implementation with O(n log n) time complexity
- **Execution time measurement** in nanoseconds using high-precision timing
- **Comparison counting** to track the number of comparisons made during sorting
- **File I/O operations** for reading input and writing sorted output
- **Automatic test file generation** for different data patterns

## Input Files

Both programs automatically generate three test files:

1. **inAsce.dat** - Contains ascending data (10, 20, 30, 40, ...)
2. **inDesc.dat** - Contains descending data (90, 80, 70, 60, ...)
3. **inRand.dat** - Contains random data

## Output Files

The sorted results are stored in separate files for each algorithm:

### Merge Sort Output Files:
1. **outMergeAsce.dat** - Sorted ascending data
2. **outMergeDesc.dat** - Sorted descending data
3. **outMergeRand.dat** - Sorted random data

### Quick Sort Output Files:
1. **outQuickAsce.dat** - Sorted ascending data
2. **outQuickDesc.dat** - Sorted descending data
3. **outQuickRand.dat** - Sorted random data

## Menu Options

Both programs use the same menu structure:

```
MAIN MENU (QUICK SORT / MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. EXIT
```

## Program Output

### Quick Sort Output:
For each option, the program displays:
- **Before Sorting**: Content of the input file (first 20 elements)
- **After Sorting**: Content of the sorted array (first 20 elements)
- **Number of Comparisons**: Actual count of comparisons made
- **Total Partitions**: Number of partitioning operations
- **Best-case Partitions**: Count of balanced partitions
- **Worst-case Partitions**: Count of unbalanced partitions
- **Scenario**: Best-case, Worst-case, or Mixed-case analysis

### Merge Sort Output:
For each option, the program displays:
- **Before Sorting**: Content of the input file
- **After Sorting**: Content of the sorted array
- **Number of Comparisons**: Actual count of comparisons made
- **Execution Time**: Time taken in nanoseconds

## Compilation and Execution

### Using Makefile
```bash
# Compile both programs
make

# Run merge sort program
make test

# Run quick sort program
make test-quick

# Clean generated files
make clean

# Show help
make help
```

### Manual Compilation
```bash
# Compile merge sort
gcc -Wall -Wextra -std=c99 merge_sort.c -o merge_sort
./merge_sort

# Compile quick sort
gcc -Wall -Wextra -std=c99 quick_sort.c -o quick_sort
./quick_sort
```

## Algorithm Details

### Quick Sort Implementation
- **Time Complexity**: O(n log n) average case, O(n²) worst case
- **Space Complexity**: O(log n) average case, O(n) worst case
- **Stable Sort**: No, may change relative order of equal elements
- **In-place**: Yes, sorts in the original array
- **Partitioning Analysis**: Tracks best-case vs worst-case scenarios

### Merge Sort Implementation
- **Time Complexity**: O(n log n) in all cases
- **Space Complexity**: O(n) for temporary arrays
- **Stable Sort**: Yes, maintains relative order of equal elements
- **In-place**: No, requires additional space

### Quick Sort Key Functions

1. **quickSort()**: Main recursive function that implements divide-and-conquer
2. **partition()**: Partitions array around pivot and analyzes partitioning scenario
3. **swap()**: Utility function to swap array elements
4. **determineScenario()**: Analyzes partitioning patterns to determine scenario
5. **readFromFile()**: Reads data from input files
6. **writeToFile()**: Writes sorted data to output files
7. **generateTestFiles()**: Creates test data files automatically

### Merge Sort Key Functions

1. **mergeSort()**: Main recursive function that divides the array
2. **merge()**: Merges two sorted subarrays into a single sorted array
3. **readFromFile()**: Reads data from input files
4. **writeToFile()**: Writes sorted data to output files
5. **generateTestFiles()**: Creates test data files automatically

## Technical Notes

### Quick Sort Program:
- Partitioning analysis tracks balanced vs unbalanced splits
- Best-case scenario: when both subproblems are ≤ n/2 size
- Worst-case scenario: when one subproblem has n-1 elements and other has 0
- Comparison count is tracked globally to avoid parameter passing complexity
- Array size is limited to 1000 elements (configurable via MAX_SIZE)
- Test files contain 300-500 entries as specified in requirements

### Merge Sort Program:
- Uses `clock_gettime(CLOCK_MONOTONIC, ...)` for high-precision timing
- Comparison count is tracked globally to avoid parameter passing complexity
- Array size is limited to 1000 elements (configurable via MAX_SIZE)
- Test files contain 300-500 entries as specified in requirements
- Program assumes single execution environment for accurate timing

## Sample Output

### Quick Sort Sample Output:
```
MAIN MENU (QUICK SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. EXIT
Enter option: 1

Before Sorting: 10 20 30 40 50 60 70 80 90 100 110 120 130 140 150 160 170 180 190 200 ... (showing first 20 elements, total: 350)
After Sorting: 10 20 30 40 50 60 70 80 90 100 110 120 130 140 150 160 170 180 190 200 ... (showing first 20 elements, total: 350)
Number of Comparisons: 6125
Total Partitions: 349
Best-case Partitions: 0
Worst-case Partitions: 349
Scenario: Worst-case
```

### Merge Sort Sample Output:
```
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. EXIT
Enter option: 1

Before Sorting: 10 20 30 40 50 60 70 80 90 100 ...
After Sorting: 10 20 30 40 50 60 70 80 90 100 ...
Number of Comparisons: 1234
Execution Time: 45678 nanoseconds
```

## Requirements Met

### Quick Sort Requirements:
✅ Menu-driven program  
✅ Quick sort implementation  
✅ Comparison counting  
✅ Partitioning analysis (best-case vs worst-case)  
✅ File I/O for different data types  
✅ 300-500 entries in input files  
✅ Proper output file naming convention  
✅ Error handling for file operations  
✅ Clean and modular code structure  

### Merge Sort Requirements:
✅ Menu-driven program  
✅ Merge sort implementation  
✅ Execution time calculation in nanoseconds  
✅ Comparison counting  
✅ File I/O for different data types  
✅ 300-500 entries in input files  
✅ Proper output file naming convention  
✅ Error handling for file operations  
✅ Clean and modular code structure
