CFLAGS = -g -Wall -ansi -pedantic
CC = gcc
SRC = main.c
OBJ = main.o



test: $(SRC)
	$(CC) $(CFLAGS) -o z_calc $(SRC)

all: $(OBJ)
	$(CC) $(CFLAGS) -o z_calc$(OBJ)

clean:
	rm -f $(OBJ)

clean_all:
	rm -f $(OBJ) z_calc

