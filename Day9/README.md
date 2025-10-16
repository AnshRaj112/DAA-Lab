# Floyd-Warshall Algorithm Implementation

## Overview
This program implements Floyd-Warshall's algorithm to find the shortest path between every pair of vertices in a directed weighted graph.

## Features
- Reads adjacency matrix from input file `inDiAdjMat2.dat`
- Computes shortest path weights between all pairs of vertices
- Displays intermediate vertices on the shortest path between given source and destination
- Handles negative edge weights and detects negative cycles

## Files
- `floyd_warshall.c` - Main program implementation
- `inDiAdjMat2.dat` - Input file containing the adjacency matrix
- `Makefile` - Compilation instructions
- `README.md` - This documentation

## Input Format
The input file `inDiAdjMat2.dat` contains a cost adjacency matrix where:
- `0` represents no direct edge between vertices
- Positive/negative numbers represent edge weights
- The matrix is n×n for n vertices

## Usage
1. Compile the program:
   ```bash
   make
   ```

2. Run the program:
   ```bash
   make run
   ```

3. Enter the number of vertices and source/destination pair when prompted

## Example
For the given input matrix:
```
0 3 8 0 -4
0 0 0 1 7
0 4 0 0 0
2 0 -5 0 0
0 0 0 6 0
```

With source=2, destination=5, the output will be:
```
Shortest Path Weight Matrix:
0 1 -3 2 -4
3 0 -4 1 -1
7 4 0 5 3
2 -1 -5 0 -2
8 5 1 6 0
Shortest Path from vertex 2 to vertex 5: 2-->4-->1-->5
Path weight: -1
```

## Algorithm Complexity
- Time Complexity: O(V³) where V is the number of vertices
- Space Complexity: O(V²) for storing the distance and next matrices

## Notes
- The program uses 1-based indexing for vertex numbers in output
- INF represents infinity (no path exists)
- The algorithm handles negative edge weights but not negative cycles
