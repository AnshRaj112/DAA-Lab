# Prim's Algorithm Implementation

This directory contains implementations of Prim's algorithm to find the minimum spanning tree (MST) of an undirected weighted connected graph.

## Files

- `inUnAdjMat.dat` - Input file containing the cost adjacency matrix
- `prims_algorithm.c` - Implementation with explicit min-priority queue
- `prims_simple.c` - Simplified implementation using array-based approach
- `Makefile` - Build configuration
- `README.md` - This documentation

## Problem Statement

Given an undirected weighted connected graph G(V, E) and starting vertex 's':
1. Maintain a Min-Priority Queue 'Q' from the vertex set V
2. Apply Prim's algorithm to find the minimum spanning tree T(V, E')
3. Display the cost adjacency matrix of T
4. Display total cost of the minimum spanning tree T

## Input Format

The program reads:
1. Number of vertices (n)
2. Starting vertex (1-based indexing)
3. Adjacency matrix from `inUnAdjMat.dat` file

## Output Format

1. Cost adjacency matrix of the minimum spanning tree
2. Total weight of the spanning tree

## Compilation and Execution

### Using Makefile:
```bash
make all          # Compile both versions
make prims_simple # Compile only the simple version
make run          # Compile and run the simple version
make clean        # Remove executables
```

### Manual compilation:
```bash
gcc -Wall -Wextra -std=c99 -O2 -o prims_simple prims_simple.c
```

### Running the program:
```bash
./prims_simple
```

## Example

**Input:**
```
Enter the Number of Vertices: 9
Enter the Starting Vertex: 1
```

**Output:**
```
0 4 0 0 0 0 0 8 0
4 0 0 0 0 0 0 0 0
0 0 0 7 0 4 0 0 2
0 0 7 0 9 0 0 0 0
0 0 0 9 0 0 0 0 0
0 0 4 0 0 0 2 0 0
0 0 0 0 0 2 0 1 0
8 0 0 0 0 0 1 0 0
0 0 2 0 0 0 0 0 0
Total Weight of the Spanning Tree: 37
```

## Algorithm Complexity

- **Time Complexity:** O(V²) for the simple implementation
- **Space Complexity:** O(V²) for storing the adjacency matrix

## Notes

- The input file `inUnAdjMat.dat` contains a 9x9 adjacency matrix
- Vertices are numbered from 1 to n (converted to 0-based internally)
- Zero values in the matrix represent no edge (converted to INF internally)
- The algorithm finds the MST starting from the specified vertex
