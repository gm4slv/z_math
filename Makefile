CFLAGS = -g -Wall -ansi -pedantic
CC = gcc
SRC = main.c z_math.c input_output.c defs.h
OBJ = main.o z_math.o input_output.c
LDFLAGS = -lm


z_calc: $(SRC)
	$(CC) $(CFLAGS) -o z_calc $(SRC) $(LDFLAGS)

all: $(OBJ)
	$(CC) $(CFLAGS) -o z_calc $(OBJ)

clean:
	rm -f $(OBJ)

clean_all:
	rm -f $(OBJ) z_calc

