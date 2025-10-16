CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
.PHONY: all clean test help force

all: heap_program

# Force recompilation target
force: clean all

heap_program: heap_program.c
	$(CC) $(CFLAGS) heap_program.c -o heap_program

# Test target
test: heap_program
	@echo "Testing Heap Program..."
	@echo "The program will create a sample data file and run interactively."
	@echo "You can test with options 1-7 to exit."
	./heap_program

# Clean target
clean:
	rm -f heap_program persons_data.txt

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Compile heap program"
	@echo "  heap_program - Compile heap program only"
	@echo "  force       - Force recompilation (clean + all)"
	@echo "  test        - Run heap program"
	@echo "  clean       - Remove compiled program and data files"
	@echo "  help        - Show this help message"
	@echo ""
	@echo "Program features:"
	@echo "  1. Read Data from file"
	@echo "  2. Create Min-heap based on age"
	@echo "  3. Create Max-heap based on weight"
	@echo "  4. Display weight of youngest person"
	@echo "  5. Insert new person into heap"
	@echo "  6. Delete oldest person"
	@echo "  7. Exit"
