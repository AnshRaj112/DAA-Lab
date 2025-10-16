CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET1 = prims_algorithm
TARGET2 = prims_simple
SOURCE1 = prims_algorithm.c
SOURCE2 = prims_simple.c

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(SOURCE1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCE1)

$(TARGET2): $(SOURCE2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCE2)

clean:
	rm -f $(TARGET1) $(TARGET1).exe $(TARGET2) $(TARGET2).exe

run: $(TARGET2)
	./$(TARGET2)

.PHONY: all clean run
