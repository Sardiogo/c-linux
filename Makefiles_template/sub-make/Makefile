CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
EXEC = submake
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(EXEC)
	@echo "compiling sub-makefile"
	@echo "sub-makefile compiled"

submake: $(OBJ)
	@$(CC) -o $@ $^

clean:
	@ rm -rf *.o $(EXEC)