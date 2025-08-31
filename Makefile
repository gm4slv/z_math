SRCS = main.c input_output.c z_math.c
OBJS = main.o input_output.o z_math.o
BIN 	  = zcalc
CC_FLAGS = -g -ansi -Wall -pedantic
CC = gcc
LDFLAGS = -lm
PREFIX = $(HOME)/bin

all : $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CC_FLAGS) -o $(BIN) $(OBJS) $(LDFLAGS)


install : all
	@echo "Installing $(BIN) to $(DESTDIR)$(PREFIX)/bin...."
	@install -m 755 $(BIN) "$(DESTDIR)$(PREFIX)/$(BIN)"

clean:
	@echo "Removing object files $(OBJS) and executable $(BIN)..."
	@rm -f $(OBJS) $(BIN)


