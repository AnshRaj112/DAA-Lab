CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = merge_sort
SOURCE = merge_sort.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET) *.exe *.dat

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run 