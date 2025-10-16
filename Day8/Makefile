# Makefile for Day8 - Dynamic Programming Problems
# Matrix Chain Multiplication and Longest Common Subsequence

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET1 = matrix_chain_multiplication
TARGET2 = longest_common_subsequence
SOURCE1 = matrix_chain_multiplication.c
SOURCE2 = longest_common_subsequence.c

# Default target
all: $(TARGET1) $(TARGET2)

# Build matrix chain multiplication program
$(TARGET1): $(SOURCE1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCE1)

# Build longest common subsequence program
$(TARGET2): $(SOURCE2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCE2)

# Clean up generated files
clean:
	rm -f $(TARGET1) $(TARGET2) *.exe

# Run matrix chain multiplication with sample input
test-matrix: $(TARGET1)
	@echo "Testing Matrix Chain Multiplication..."
	@echo "4" | echo "30 35" | echo "35 15" | echo "15 5" | echo "5 10" | ./$(TARGET1)

# Run LCS with sample input
test-lcs: $(TARGET2)
	@echo "Testing Longest Common Subsequence..."
	@echo "10010101" | echo "010110110" | ./$(TARGET2)

# Run both tests
test: test-matrix test-lcs

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build both programs"
	@echo "  $(TARGET1)   - Build matrix chain multiplication program"
	@echo "  $(TARGET2)   - Build longest common subsequence program"
	@echo "  clean        - Remove generated files"
	@echo "  test-matrix  - Run matrix chain multiplication with sample input"
	@echo "  test-lcs     - Run LCS with sample input"
	@echo "  test         - Run both tests"
	@echo "  help         - Show this help message"

.PHONY: all clean test test-matrix test-lcs help
