CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
all: lab2q1 lab2q2

lab2q1: lab2q1.c
	$(CC) $(CFLAGS) lab2q1.c -o lab2q1

lab2q2: lab2q2.c
	$(CC) $(CFLAGS) lab2q2.c -o lab2q2

# Test targets
test1: lab2q1
	./lab2q1 10 inDec.dat outBin.dat

test2: lab2q2
	./lab2q2 inGcd.dat outGcd.dat

# Clean target
clean:
	rm -f lab2q1 lab2q2 outBin.dat outGcd.dat

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Compile both programs"
	@echo "  lab2q1  - Compile decimal to binary converter"
	@echo "  lab2q2  - Compile GCD calculator"
	@echo "  test1   - Test lab2q1 with sample data"
	@echo "  test2   - Test lab2q2 with sample data"
	@echo "  clean   - Remove compiled programs and output files"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Usage examples:"
	@echo "  ./lab2q1 150 inDec.dat outBin.dat"
	@echo "  ./lab2q2 inGcd.dat outGcd.dat"

.PHONY: all test1 test2 clean help 