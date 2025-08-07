# Day 2 - Recursion and Iteration Programs

This directory contains two C programs that demonstrate the use of recursion and iteration for solving algorithmic problems.

## Programs

### 1. lab2q1.c - Decimal to Binary Converter

**Aim**: Convert the first 'n' decimal numbers from a file to binary using iteration and store the results in a separate file.

**Features**:
- Uses iterative function to convert decimal to binary
- Reads command line arguments for n, input file, and output file
- Displays results both on terminal and saves to output file
- Formats binary numbers as 16-bit strings with leading zeros

**Usage**:
```bash
gcc lab2q1.c -o lab2q1
./lab2q1 <n> <input_file> <output_file>
```

**Example**:
```bash
./lab2q1 150 inDec.dat outBin.dat
```

**Input File Format** (inDec.dat):
```
30 75 2564 100 255 1024 ...
```

**Output File Format** (outBin.dat):
```
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
...
```

### 2. lab2q2.c - GCD Calculator

**Aim**: Find the Greatest Common Divisor (GCD) of pairs of numbers using recursion.

**Features**:
- Uses recursive Euclidean algorithm to find GCD
- Reads pairs of numbers from input file
- Stores results in output file
- Displays results on terminal
- Recommends at least 20 pairs in input file

**Usage**:
```bash
gcc lab2q2.c -o lab2q2
./lab2q2 <input_file> <output_file>
```

**Example**:
```bash
./lab2q2 inGcd.dat outGcd.dat
```

**Input File Format** (inGcd.dat):
```
8 12
20 45
30 80
...
```

**Output File Format** (outGcd.dat):
```
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
...
```

## Compilation and Testing

### Using Makefile
```bash
# Compile both programs
make all

# Compile individual programs
make lab2q1
make lab2q2

# Test programs with sample data
make test1
make test2

# Clean compiled files
make clean

# Show help
make help
```

### Manual Compilation
```bash
# Compile lab2q1
gcc lab2q1.c -o lab2q1

# Compile lab2q2
gcc lab2q2.c -o lab2q2
```

## Algorithm Details

### Decimal to Binary Conversion (Iterative)
The iterative algorithm works as follows:
1. Initialize a 16-bit binary string with zeros
2. For each bit position from right to left (15 to 0):
   - Set the current bit to (decimal % 2)
   - Divide decimal by 2
3. The result is a 16-bit binary representation with leading zeros

### GCD Calculation (Euclidean Algorithm - Recursive)
The recursive Euclidean algorithm:
1. If b is 0, return a (base case)
2. Otherwise, return gcd(b, a % b)

## Files in this Directory

- `lab2q1.c` - Decimal to binary converter program (iterative)
- `lab2q2.c` - GCD calculator program (recursive)
- `inDec.dat` - Sample input file for decimal numbers
- `inGcd.dat` - Sample input file for number pairs
- `outBin.dat` - Output file for binary conversions
- `outGcd.dat` - Output file for GCD calculations
- `Makefile` - Build configuration
- `README.md` - This documentation file

## Sample Output

### lab2q1 Output
```
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
...

Conversion completed! 10 numbers processed.
```

### lab2q2 Output
```
Done. 40 pairs processed.
```

## Error Handling

Both programs include comprehensive error handling:
- Command line argument validation
- File opening error checking
- Input format validation
- Proper file closure on errors

## Requirements

- GCC compiler
- C99 standard compliance
- POSIX-compliant system for file operations 