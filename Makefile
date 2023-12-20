CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = towers_of_hanoi

SRC = main.c input.c gamePlay.c display.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(EXEC)
	$(RM) $(OBJ) $(TARGET)

# Detect the operating system for the 'clean' target
ifeq ($(OS),Windows_NT)
    EXEC = towers_of_hanoi.exe
    RM = del /Q
else
    EXEC = ./towers_of_hanoi
    RM = rm -f
endif
