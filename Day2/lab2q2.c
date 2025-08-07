#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate GCD
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE* output = fopen(argv[2], "w");
    if (!output) {
        perror("Error creating output file");
        fclose(input);
        return 1;
    }

    int num1, num2, count = 0;
    while (fscanf(input, "%d %d", &num1, &num2) == 2) {
        fprintf(output, "GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
        count++;
    }

    fclose(input);
    fclose(output);

    printf("Done. %d pairs processed.\n", count);
    return 0;
}