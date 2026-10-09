CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Iinclude

SRC = src/main.c src/core/result.c src/core/conversion.c src/cli/menu.c

TARGET = digitallab

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
