SRCS = main.c input_output.c z_math.c
OBJS = main.o input_output.o z_math.o
BIN 	  = zcalc
CC_FLAGS = -g -ansi -Wall -pedantic
CC = gcc
LDFLAGS = -lm


all : $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CC_FLAGS) -o $(BIN) $(OBJS) $(LDFLAGS)
