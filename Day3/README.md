# Merge Sort Program

This program implements a menu-driven merge sort algorithm with execution time measurement and comparison counting.

## Features

- **Menu-driven interface** with options for different data types
- **Merge Sort implementation** with O(n log n) time complexity
- **Execution time measurement** in nanoseconds
- **Comparison counting** to track algorithm efficiency
- **File I/O** for reading input data and writing sorted results
- **Support for 300-500 elements** as required

## Input Files

The program expects the following input files:

1. **inAsce.dat** - Ascending data (10 20 30 40...)
2. **inDesc.dat** - Descending data (90 80 70 60...)
3. **inRand.dat** - Random data (55 66 33 11 44...)

## Output Files

The program generates the following output files:

1. **outMergeAsce.dat** - Sorted ascending data with comparison count
2. **outMergeDesc.dat** - Sorted descending data with comparison count
3. **outMergeRand.dat** - Sorted random data with comparison count

Each output file contains:
- The sorted array elements
- The number of comparisons made during sorting

## Compilation

```bash
make
```

Or manually:
```bash
gcc -Wall -Wextra -std=c99 -o merge_sort merge_sort.c
```

## Usage

1. Run the program:
   ```bash
   ./merge_sort
   ```

2. Choose from the menu:
   - Option 1: Sort ascending data
   - Option 2: Sort descending data
   - Option 3: Sort random data
   - Option 4: Exit

3. The program will display:
   - Before sorting: Original array content
   - After sorting: Sorted array content
   - Number of comparisons made
   - Execution time in nanoseconds
   - Confirmation of output file creation

## Sample Output

```
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. EXIT
Enter option: 1
Before Sorting: 10 20 30 40 50 ...
After Sorting: 10 20 30 40 50 ...
Number of Comparisons: 1234
Execution Time: 4567890 nanoseconds
Sorted data written to outMergeAsce.dat
```

**Output File Content (outMergeAsce.dat):**
```
10 20 30 40 50 60 70 80 90 100 ...
Number of Comparisons: 1234
```

## Algorithm Details

- **Time Complexity**: O(n log n) in all cases
- **Space Complexity**: O(n) for temporary arrays
- **Stable Sort**: Yes, maintains relative order of equal elements
- **In-place**: No, requires additional space

## Notes

- The program assumes single program execution for accurate timing
- Input files should contain 300-500 elements as specified
- All timing measurements are in nanoseconds for precision
- The comparison counter tracks all comparisons made during the merge process 