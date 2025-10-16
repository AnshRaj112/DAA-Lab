#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function to read adjacency matrix from file
void readAdjacencyMatrix(int n, int adj[MAX_VERTICES][MAX_VERTICES], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &adj[i][j]);
            if (adj[i][j] == 0 && i != j) {
                adj[i][j] = INF;
            }
        }
    }
    fclose(file);
}

// Function to find minimum key vertex not in MST
int minKey(int n, int key[], bool mstSet[]) {
    int min = INF, min_index;
    
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Prim's algorithm implementation
void primMST(int n, int adj[MAX_VERTICES][MAX_VERTICES], int start, int mst[MAX_VERTICES][MAX_VERTICES]) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    
    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
        for (int j = 0; j < n; j++) {
            mst[i][j] = 0;
        }
    }
    
    // Always include first vertex in MST
    key[start] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[start] = -1; // First node is always root of MST
    
    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(n, key, mstSet);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        
        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            // adj[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if adj[u][v] is smaller than key[v]
            if (adj[u][v] != INF && mstSet[v] == false && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }
    
    // Build MST adjacency matrix
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            int u = parent[i];
            int v = i;
            int weight = adj[u][v];
            mst[u][v] = weight;
            mst[v][u] = weight; // Undirected graph
        }
    }
}

// Function to calculate total weight of MST
int calculateTotalWeight(int n, int mst[MAX_VERTICES][MAX_VERTICES]) {
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mst[i][j] > 0) {
                totalWeight += mst[i][j];
            }
        }
    }
    return totalWeight;
}

// Function to display adjacency matrix
void displayMatrix(int n, int matrix[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, start;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int mst[MAX_VERTICES][MAX_VERTICES];
    
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    
    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);
    start--; // Convert to 0-based indexing
    
    // Read adjacency matrix from file
    readAdjacencyMatrix(n, adj, "inUnAdjMat.dat");
    
    // Apply Prim's algorithm
    primMST(n, adj, start, mst);
    
    // Display MST adjacency matrix
    displayMatrix(n, mst);
    
    // Calculate and display total weight
    int totalWeight_1653 = calculateTotalWeight(n, mst);
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight_1653);
    
    return 0;
}
