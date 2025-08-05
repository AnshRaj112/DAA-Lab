#include <stdio.h>
#include <stdlib.h>

// Function to find GCD using recursion (Euclidean algorithm)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        printf("Example: %s inGcd.dat outGcd.dat\n", argv[0]);
        return 1;
    }
    
    char* input_file = argv[1];
    char* output_file = argv[2];
    
    // Open input file
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Cannot open input file %s\n", input_file);
        return 1;
    }
    
    // Open output file
    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Cannot create output file %s\n", output_file);
        fclose(input);
        return 1;
    }
    
    int num1, num2;
    int pair_count = 0;
    
    printf("Finding GCD of number pairs...\n");
    printf("Reading from: %s\n", input_file);
    printf("Writing to: %s\n\n", output_file);
    
    // Read pairs of numbers and find their GCD
    while (fscanf(input, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        
        // Write to output file
        fprintf(output, "The GCD of %d and %d is %d\n", num1, num2, result);
        
        // Display on terminal
        printf("The GCD of %d and %d is %d\n", num1, num2, result);
        
        pair_count++;
    }
    
    fclose(input);
    fclose(output);
    
    printf("\nGCD calculation completed! %d pairs processed.\n", pair_count);
    printf("Results saved to: %s\n", output_file);
    
    if (pair_count < 20) {
        printf("Warning: Input file contains only %d pairs, but at least 20 pairs are recommended.\n", pair_count);
    }
    
    return 0;
} 