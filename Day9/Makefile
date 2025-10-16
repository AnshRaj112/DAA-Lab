CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = floyd_warshall
SOURCE = floyd_warshall.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET) $(TARGET).exe

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
