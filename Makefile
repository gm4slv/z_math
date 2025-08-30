CFLAGS = -g -Wall -ansi -pedantic
CC = gcc
SRC = main.c z_math.c input_output.c defs.h
OBJ = main.o z_math.o input_output.o
LDFLAGS = -lm
PREFIX = /home/g4slv/bin
BIN = zcalc

zcalc: $(SRC)
	$(CC) $(CFLAGS) -o zcalc $(SRC) $(LDFLAGS)

all: $(OBJ)
	$(CC) $(CFLAGS) -o zcalc $(OBJ)

clean:
	rm -f $(OBJ)

clean_all:
	rm -f $(OBJ) zcalc

install : zcalc
	@echo "Installing $(BIN) $(DESTDIR)$(PREFIX)..."
	@install -m 755 $(BIN) "$(DESTDIR)$(PREFIX)/$(BIN)"
