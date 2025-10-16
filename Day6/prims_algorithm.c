#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Structure for priority queue node
typedef struct {
    int vertex;
    int key;
} PQNode;

// Structure for priority queue
typedef struct {
    PQNode* heap;
    int size;
    int capacity;
} PriorityQueue;

// Function to create a new priority queue
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (PQNode*)malloc(capacity * sizeof(PQNode));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

// Function to swap two nodes in the heap
void swap(PQNode* a, PQNode* b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the priority queue (min-heap)
void heapify(PriorityQueue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heap[left].key < pq->heap[smallest].key)
        smallest = left;

    if (right < pq->size && pq->heap[right].key < pq->heap[smallest].key)
        smallest = right;

    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

// Function to extract minimum from priority queue
PQNode extractMin(PriorityQueue* pq) {
    if (pq->size == 0) {
        PQNode empty = {-1, -1};
        return empty;
    }

    PQNode min = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return min;
}

// Function to decrease key of a vertex in priority queue
void decreaseKey(PriorityQueue* pq, int vertex, int newKey) {
    int i;
    for (i = 0; i < pq->size; i++) {
        if (pq->heap[i].vertex == vertex) {
            if (newKey < pq->heap[i].key) {
                pq->heap[i].key = newKey;
                // Heapify up
                while (i > 0 && pq->heap[(i - 1) / 2].key > pq->heap[i].key) {
                    swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
                    i = (i - 1) / 2;
                }
            }
            break;
        }
    }
}

// Function to check if vertex is in priority queue
bool isInQueue(PriorityQueue* pq, int vertex) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->heap[i].vertex == vertex)
            return true;
    }
    return false;
}

// Function to get key value of a vertex in priority queue
int getKey(PriorityQueue* pq, int vertex) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->heap[i].vertex == vertex)
            return pq->heap[i].key;
    }
    return INF;
}

// Function to add a node to priority queue
void enqueue(PriorityQueue* pq, int vertex, int key) {
    if (pq->size >= pq->capacity) return;
    
    pq->heap[pq->size].vertex = vertex;
    pq->heap[pq->size].key = key;
    pq->size++;
    
    // Heapify up
    int i = pq->size - 1;
    while (i > 0 && pq->heap[(i - 1) / 2].key > pq->heap[i].key) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

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

// Prim's algorithm implementation
void primMST(int n, int adj[MAX_VERTICES][MAX_VERTICES], int start, int mst[MAX_VERTICES][MAX_VERTICES]) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool inMST[MAX_VERTICES];
    
    // Initialize arrays
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
        for (int j = 0; j < n; j++) {
            mst[i][j] = 0;
        }
    }
    
    // Create priority queue
    PriorityQueue* pq = createPriorityQueue(n);
    
    // Initialize starting vertex
    key[start] = 0;
    enqueue(pq, start, 0);
    
    // Add all other vertices to priority queue
    for (int i = 0; i < n; i++) {
        if (i != start) {
            enqueue(pq, i, INF);
        }
    }
    
    // Prim's algorithm
    while (pq->size > 0) {
        PQNode minNode = extractMin(pq);
        int u = minNode.vertex;
        
        inMST[u] = true;
        
        // Update key values and parent indices of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != INF && !inMST[v] && adj[u][v] < getKey(pq, v)) {
                parent[v] = u;
                key[v] = adj[u][v];
                decreaseKey(pq, v, adj[u][v]);
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
    
    free(pq->heap);
    free(pq);
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
