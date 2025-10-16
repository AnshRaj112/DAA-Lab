# Day 8 - Dynamic Programming Problems

This directory contains two dynamic programming implementations:

## 8.1 Matrix Chain Multiplication

**File:** `matrix_chain_multiplication.c`

**Aim:** Implement the matrix chain multiplication problem using M-table & S-table to find optimal parenthesization of a matrix-chain product.

**Features:**
- Dynamic programming solution with O(n³) time complexity
- M-table for storing minimum scalar multiplications
- S-table for storing optimal split points
- Dimension compatibility validation
- Optimal parenthesization output

**Sample Input:**
```
Enter number of matrices: 4
Enter row and col size of A1: 30 35
Enter row and col size of A2: 35 15
Enter row and col size of A3: 15 5
Enter row and col size of A4: 5 10
```

**Sample Output:**
```
M Table:
0 15750 7875 9375
0 0 2625 4375
0 0 0 750
0 0 0 0

S Table:
0 1 1 3
0 0 2 3
0 0 0 3
0 0 0 0

Optimal parenthesization: ((A1(A2A3))A4)
The optimal ordering of the given matrices requires 9375 scalar multiplications.
```

## 8.2 Longest Common Subsequence (LCS)

**File:** `longest_common_subsequence.c`

**Aim:** Find the Longest Common Subsequence of two given strings and calculate its length.

**Features:**
- Dynamic programming solution with O(m×n) time complexity
- LCS construction and length calculation
- Memory efficient implementation

**Sample Input:**
```
Enter the first string into an array: 10010101
Enter the second string into an array: 010110110
```

**Sample Output:**
```
LCS: 100110
LCS Length: 6
```

## Compilation and Execution

### Using Makefile:
```bash
# Build both programs
make all

# Build individual programs
make matrix_chain_multiplication
make longest_common_subsequence

# Run tests with sample inputs
make test

# Clean generated files
make clean
```

### Manual compilation:
```bash
# Matrix Chain Multiplication
gcc -Wall -Wextra -std=c99 -O2 -o matrix_chain_multiplication matrix_chain_multiplication.c

# Longest Common Subsequence
gcc -Wall -Wextra -std=c99 -O2 -o longest_common_subsequence longest_common_subsequence.c
```

## Algorithm Details

### Matrix Chain Multiplication
- **Time Complexity:** O(n³)
- **Space Complexity:** O(n²)
- Uses dynamic programming to find optimal parenthesization
- Validates matrix dimension compatibility
- Constructs optimal parenthesization from S-table

### Longest Common Subsequence
- **Time Complexity:** O(m×n)
- **Space Complexity:** O(m×n)
- Uses dynamic programming to find LCS length
- Backtracks through DP table to construct actual LCS
- Handles strings of arbitrary length (up to 99 characters)

## Input Validation

### Matrix Chain Multiplication:
- Validates that number of matrices is positive
- Ensures dimension compatibility between consecutive matrices
- Provides clear error messages for invalid inputs

### Longest Common Subsequence:
- Accepts any string input (up to 99 characters)
- Handles empty strings gracefully
- No special validation required for string inputs
