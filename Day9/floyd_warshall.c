#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF 99999

// Function to print the shortest path between two vertices
void printPath_1653(int next[][MAX_VERTICES], int u, int v) {
    if (next[u][v] == -1) {
        printf("%d", u + 1); // Convert to 1-based indexing
        return;
    }
    
    printf("%d-->", u + 1); // Convert to 1-based indexing
    printPath_1653(next, next[u][v], v);
}

// Function to print the shortest path with proper formatting
void printShortestPath_1653(int next[][MAX_VERTICES], int u, int v) {
    printf("Shortest Path from vertex %d to vertex %d: ", u + 1, v + 1);
    printPath_1653(next, u, v);
    printf("\n");
}

// Floyd-Warshall algorithm implementation
void floydWarshall_1653(int graph[][MAX_VERTICES], int n, int source, int destination) {
    int dist[MAX_VERTICES][MAX_VERTICES];
    int next[MAX_VERTICES][MAX_VERTICES];
    
    // Initialize distance matrix and next matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            } else {
                dist[i][j] = INF;
            }
            
            if (graph[i][j] != 0) {
                next[i][j] = j;
            } else {
                next[i][j] = -1;
            }
        }
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    
    // Print the shortest path weight matrix
    printf("Shortest Path Weight Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    
    // Print the shortest path between source and destination
    if (dist[source][destination] != INF) {
        printShortestPath_1653(next, source, destination);
        printf("Path weight: %d\n", dist[source][destination]);
    } else {
        printf("No path exists from vertex %d to vertex %d\n", source + 1, destination + 1);
    }
}

int main() {
    int n;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int source, destination;
    
    // Read input file
    FILE *file = fopen("inDiAdjMat2.dat", "r");
    if (file == NULL) {
        printf("Error: Could not open input file 'inDiAdjMat2.dat'\n");
        return 1;
    }
    
    // Read number of vertices
    printf("Number of Vertices: ");
    scanf("%d", &n);
    
    // Read adjacency matrix from file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);
    
    // Get source and destination vertices
    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &source, &destination);
    
    // Convert to 0-based indexing
    source--;
    destination--;
    
    // Apply Floyd-Warshall algorithm
    floydWarshall_1653(graph, n, source, destination);
    
    return 0;
}
