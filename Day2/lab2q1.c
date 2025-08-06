#include <stdio.h>
#include <stdlib.h>

void getBinaryString(int decimal, char* binary) {
    for (int i = 15; i >= 0; i--) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[16] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Error: n must be a positive integer\n");
        return 1;
    }

    FILE* input = fopen(argv[2], "r");
    FILE* output = fopen(argv[3], "w");
    if (!input || !output) {
        printf("Error: Unable to open input or output file.\n");
        if (input) fclose(input);
        if (output) fclose(output);
        return 1;
    }

    int decimal, count = 0;
    char binary[17];

    while (count < n && fscanf(input, "%d", &decimal) == 1) {
        getBinaryString(decimal, binary);
        fprintf(output, "The binary equivalent of %d is %s\n", decimal, binary);
        printf("The binary equivalent of %d is %s\n", decimal, binary);
        count++;
    }

    fclose(input);
    fclose(output);
    printf("\nConversion completed! %d numbers processed.\n", count);
    return 0;
}
