CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
.PHONY: all clean test help force

all: merge_sort quick_sort

# Force recompilation target
force: clean all

merge_sort: merge_sort.c
	$(CC) $(CFLAGS) merge_sort.c -o merge_sort

quick_sort: quick_sort.c
	$(CC) $(CFLAGS) quick_sort.c -o quick_sort

# Test targets
test: merge_sort
	@echo "Testing Merge Sort Program..."
	@echo "The program will generate test files and run interactively."
	@echo "You can test with options 1, 2, 3, or 4 to exit."
	./merge_sort

test-quick: quick_sort
	@echo "Testing Quick Sort Program..."
	@echo "The program will generate test files and run interactively."
	@echo "You can test with options 1, 2, 3, or 4 to exit."
	./quick_sort

# Clean target
clean:
	rm -f merge_sort quick_sort inAsce.dat inDesc.dat inRand.dat outMergeAsce.dat outMergeDesc.dat outMergeRand.dat outQuickAsce.dat outQuickDesc.dat outQuickRand.dat

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Compile both merge sort and quick sort programs"
	@echo "  merge_sort - Compile merge sort program only"
	@echo "  quick_sort - Compile quick sort program only"
	@echo "  force      - Force recompilation (clean + all)"
	@echo "  test       - Run merge sort program"
	@echo "  test-quick - Run quick sort program"
	@echo "  clean      - Remove compiled programs and generated files"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Input files (generated automatically):"
	@echo "  inAsce.dat  - Ascending data (10 20 30 40...)"
	@echo "  inDesc.dat  - Descending data (90 80 70 60...)"
	@echo "  inRand.dat  - Random data"
	@echo ""
	@echo "Output files:"
	@echo "  outMergeAsce.dat  - Sorted ascending data (merge sort)"
	@echo "  outMergeDesc.dat  - Sorted descending data (merge sort)"
	@echo "  outMergeRand.dat  - Sorted random data (merge sort)"
	@echo "  outQuickAsce.dat  - Sorted ascending data (quick sort)"
	@echo "  outQuickDesc.dat  - Sorted descending data (quick sort)"
	@echo "  outQuickRand.dat  - Sorted random data (quick sort)"
