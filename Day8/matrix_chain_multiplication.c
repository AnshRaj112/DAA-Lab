#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to print the M-table
void printMTable_1653(int **m, int n) {
    printf("M Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Function to print the S-table
void printSTable_1653(int **s, int n) {
    printf("S Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

// Function to print optimal parenthesization
void printOptimalParenthesization_1653(int **s, int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        printOptimalParenthesization_1653(s, i, s[i][j]);
        printOptimalParenthesization_1653(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Matrix Chain Multiplication using Dynamic Programming
int matrixChainOrder_1653(int dimensions[], int n, int **m, int **s) {
    // Initialize diagonal elements to 0
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }
    
    // Fill the table for different chain lengths
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    return m[0][n - 1];
}

// Function to validate matrix dimensions
int validateDimensions_1653(int dimensions[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (dimensions[i] != dimensions[i + 1]) {
            return 0; // Invalid dimensions
        }
    }
    return 1; // Valid dimensions
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Error: Number of matrices must be positive.\n");
        return 1;
    }
    
    // Allocate memory for dimensions array
    int *dimensions = (int*)malloc((n + 1) * sizeof(int));
    
    // Input matrix dimensions
    printf("Enter row and col size of A1: ");
    scanf("%d %d", &dimensions[0], &dimensions[1]);
    
    for (int i = 1; i < n; i++) {
        int row, col;
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &row, &col);
        
        // Validate dimension compatibility
        if (dimensions[i] != row) {
            printf("Error: Dimension mismatch! Column size of A%d (%d) must equal row size of A%d (%d).\n", 
                   i, dimensions[i], i + 1, row);
            free(dimensions);
            return 1;
        }
        dimensions[i + 1] = col;
    }
    
    // Allocate memory for M-table and S-table
    int **m = (int**)malloc(n * sizeof(int*));
    int **s = (int**)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        m[i] = (int*)calloc(n, sizeof(int));
        s[i] = (int*)calloc(n, sizeof(int));
    }
    
    // Calculate optimal parenthesization
    int minMultiplications = matrixChainOrder_1653(dimensions, n, m, s);
    
    // Print results
    printMTable_1653(m, n);
    printf("\n");
    printSTable_1653(s, n);
    printf("\n");
    
    printf("Optimal parenthesization: ");
    printOptimalParenthesization_1653(s, 0, n - 1);
    printf("\n");
    
    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", 
           minMultiplications);
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(m[i]);
        free(s[i]);
    }
    free(m);
    free(s);
    free(dimensions);
    
    return 0;
}
