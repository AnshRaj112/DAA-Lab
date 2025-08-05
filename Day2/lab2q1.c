#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary using recursion
void decimalToBinary(int decimal, char* binary, int* index) {
    if (decimal == 0) {
        return;
    }
    
    decimalToBinary(decimal / 2, binary, index);
    binary[*index] = (decimal % 2) + '0';
    (*index)++;
}

// Function to convert decimal to 16-bit binary string
void getBinaryString(int decimal, char* binary) {
    int index = 0;
    decimalToBinary(decimal, binary, &index);
    
    // Pad with leading zeros to make it 16 bits
    int len = strlen(binary);
    if (len < 16) {
        memmove(binary + (16 - len), binary, len + 1);
        for (int i = 0; i < 16 - len; i++) {
            binary[i] = '0';
        }
    }
    binary[16] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        printf("Example: %s 150 inDec.dat outBin.dat\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    char* input_file = argv[2];
    char* output_file = argv[3];
    
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
    
    int decimal;
    int count = 0;
    char binary[17]; // 16 bits + null terminator
    
    printf("Converting first %d decimal numbers to binary...\n", n);
    printf("Reading from: %s\n", input_file);
    printf("Writing to: %s\n\n", output_file);
    
    // Read decimal numbers and convert to binary
    while (count < n && fscanf(input, "%d", &decimal) == 1) {
        getBinaryString(decimal, binary);
        
        // Write to output file
        fprintf(output, "The binary equivalent of %d is %s\n", decimal, binary);
        
        // Display on terminal
        printf("The binary equivalent of %d is %s\n", decimal, binary);
        
        count++;
    }
    
    fclose(input);
    fclose(output);
    
    printf("\nConversion completed! %d numbers processed.\n", count);
    printf("Results saved to: %s\n", output_file);
    
    return 0;
} 