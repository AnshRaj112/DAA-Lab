# Day 1 - Array Operations in C

This directory contains four C programs implementing various array operations as part of the DAA Lab.

## Programs

### 1.1 Second Smallest and Second Largest Elements
**File:** `1.1_second_smallest_largest.c`
- **Aim:** Find the second smallest and second largest elements in an array
- **Input:** Reads array size and elements from `input.txt`
- **Output:** Second smallest and second largest elements

### 1.2 Prefix Sum Array
**File:** `1.2_prefix_sum.c`
- **Aim:** Calculate prefix sum of an array
- **Input:** Array size and elements from user
- **Output:** Prefix sum array

### 1.3 Duplicate Elements Analysis
**File:** `1.3_duplicate_analysis.c`
- **Aim:** Find total duplicate elements and most repeating element
- **Input:** Reads array from `input.txt`
- **Output:** Count of duplicates and most frequent element

### 1.4 Array Rotation
**File:** `1.4_array_rotation.c`
- **Aim:** Rotate first p2 elements of array right by 1 position
- **Input:** Reads array size and elements from `rotation_input.txt`
- **Output:** Array before and after rotation

## Compilation

### Using Makefile (Recommended)
```bash
make all
```

### Manual Compilation
```bash
gcc -Wall -Wextra -std=c99 -o 1.1_second_smallest_largest 1.1_second_smallest_largest.c
gcc -Wall -Wextra -std=c99 -o 1.2_prefix_sum 1.2_prefix_sum.c
gcc -Wall -Wextra -std=c99 -o 1.3_duplicate_analysis 1.3_duplicate_analysis.c
gcc -Wall -Wextra -std=c99 -o 1.4_array_rotation 1.4_array_rotation.c
```

## Running the Programs

### 1.1 Second Smallest and Largest
```bash
./1.1_second_smallest_largest
```
*Note: Requires `input.txt` file with array size and elements*

### 1.2 Prefix Sum
```bash
./1.2_prefix_sum
```
*Example input:*
- Size: 5
- Elements: 3 4 5 1 2
*Expected output:* 3 7 12 13 15

### 1.3 Duplicate Analysis
```bash
./1.3_duplicate_analysis
```
*Note: Requires `input.txt` file with array elements*

### 1.4 Array Rotation
```bash
./1.4_array_rotation
```
*Note: Requires `rotation_input.txt` file with array size and elements*
*Example input:*
- Size: 9
- Elements: 11 22 33 44 55 66 77 88 99
*Expected output:* 55 11 22 33 44 66 77 88 99

## Input File Format

For programs that read from `input.txt`:
```
15
10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
```
First line: Array size
Second line: Array elements separated by spaces

For program 1.4 that reads from `rotation_input.txt`:
```
9
11 22 33 44 55 66 77 88 99
```
First line: Array size
Second line: Array elements separated by spaces

## Cleaning
```bash
make clean
```

## Features
- Static array allocation
- Error handling for file operations
- Efficient algorithms for each operation
- Clear output formatting
- Modular code structure with separate functions 