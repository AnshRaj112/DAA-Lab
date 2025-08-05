# Day 2 - Recursion Programs

This directory contains two C programs that demonstrate the use of recursion for solving algorithmic problems.

## Programs

### 1. lab2q1.c - Decimal to Binary Converter

**Aim**: Convert the first 'n' decimal numbers from a file to binary using recursion and store the results in a separate file.

**Features**:
- Uses recursive function to convert decimal to binary
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

### Decimal to Binary Conversion (Recursive)
The recursive algorithm works as follows:
1. If the number is 0, return (base case)
2. Recursively convert n/2 to binary
3. Append n%2 to the result

### GCD Calculation (Euclidean Algorithm)
The recursive Euclidean algorithm:
1. If b is 0, return a (base case)
2. Otherwise, return gcd(b, a % b)

## Files in this Directory

- `lab2q1.c` - Decimal to binary converter program
- `lab2q2.c` - GCD calculator program
- `inDec.dat` - Sample input file for decimal numbers
- `inGcd.dat` - Sample input file for number pairs
- `Makefile` - Build configuration
- `README.md` - This documentation file

## Sample Output

### lab2q1 Output
```
Converting first 10 decimal numbers to binary...
Reading from: inDec.dat
Writing to: outBin.dat

The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
...

Conversion completed! 10 numbers processed.
Results saved to: outBin.dat
```

### lab2q2 Output
```
Finding GCD of number pairs...
Reading from: inGcd.dat
Writing to: outGcd.dat

The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
...

GCD calculation completed! 40 pairs processed.
Results saved to: outGcd.dat
```

## Error Handling

Both programs include comprehensive error handling:
- Command line argument validation
- File opening error checking
- Input format validation
- Memory allocation safety

## Requirements

- GCC compiler
- C99 standard compliance
- POSIX-compliant system for file operations 