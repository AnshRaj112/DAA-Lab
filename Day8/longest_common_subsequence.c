#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the length of LCS and build the DP table
int lcsLength_1653(char *str1, char *str2, int m, int n, int **dp) {
    // Fill the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

// Function to construct the LCS string
void constructLCS_1653(char *str1, char *str2, int m, int n, int **dp, char *lcs) {
    int index = dp[m][n];
    lcs[index] = '\0'; // Set the terminating character
    
    // Start from the bottom-right corner of the DP table
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current characters match, they are part of LCS
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }
        // If not, move in the direction of larger value
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string into an array: ");
    scanf("%s", str1);
    
    printf("Enter the second string into an array: ");
    scanf("%s", str2);
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    // Allocate memory for DP table
    int **dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    
    // Find the length of LCS
    int lcs_len = lcsLength_1653(str1, str2, m, n, dp);
    
    // Allocate memory for LCS string
    char *lcs = (char*)malloc((lcs_len + 1) * sizeof(char));
    
    // Construct the LCS
    constructLCS_1653(str1, str2, m, n, dp, lcs);
    
    // Print results
    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", lcs_len);
    
    // Free allocated memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    free(lcs);
    
    return 0;
}
