CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
all: 1.1_second_smallest_largest 1.2_prefix_sum 1.3_duplicate_analysis 1.4_array_rotation

1.1_second_smallest_largest: 1.1_second_smallest_largest.c
	$(CC) $(CFLAGS) -o 1.1_second_smallest_largest 1.1_second_smallest_largest.c

1.2_prefix_sum: 1.2_prefix_sum.c
	$(CC) $(CFLAGS) -o 1.2_prefix_sum 1.2_prefix_sum.c

1.3_duplicate_analysis: 1.3_duplicate_analysis.c
	$(CC) $(CFLAGS) -o 1.3_duplicate_analysis 1.3_duplicate_analysis.c

1.4_array_rotation: 1.4_array_rotation.c
	$(CC) $(CFLAGS) -o 1.4_array_rotation 1.4_array_rotation.c

# Test targets
test1: 1.1_second_smallest_largest
	@echo "Testing Second Smallest and Largest Element Finder..."
	./1.1_second_smallest_largest

test2: 1.2_prefix_sum
	@echo "Testing Prefix Sum Calculator..."
	./1.2_prefix_sum

test3: 1.3_duplicate_analysis
	@echo "Testing Duplicate Analysis..."
	./1.3_duplicate_analysis

test4: 1.4_array_rotation
	@echo "Testing Array Rotation..."
	./1.4_array_rotation

# Test all programs
test: test1 test2 test3 test4
	@echo "All tests completed!"

# Clean target
clean:
	rm -f 1.1_second_smallest_largest 1.2_prefix_sum 1.3_duplicate_analysis 1.4_array_rotation

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Compile all programs"
	@echo "  test1   - Test second smallest/largest finder"
	@echo "  test2   - Test prefix sum calculator"
	@echo "  test3   - Test duplicate analysis"
	@echo "  test4   - Test array rotation"
	@echo "  test    - Run all tests"
	@echo "  clean   - Remove compiled programs"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Individual compilation:"
	@echo "  make 1.1_second_smallest_largest"
	@echo "  make 1.2_prefix_sum"
	@echo "  make 1.3_duplicate_analysis"
	@echo "  make 1.4_array_rotation"
	@echo ""
	@echo "Input files:"
	@echo "  input.txt - Used by programs 1.1, 1.2, 1.3"
	@echo "  rotation_input.txt - Used by program 1.4"

.PHONY: all test test1 test2 test3 test4 clean help 