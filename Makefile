SRC_DIR   := src
BUILD_DIR := build
BIN 	  := $(BUILD_DIR)/zcalc
CC_FLAGS := -g -ansi -Wall -pedantic
CC := gcc
LDFLAGS= -lm


SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(subst $(SRC_DIR), $(BUILD_DIR), $(SRCS:.c=.o))

all : $(OBJS) $(BIN)

$(BIN) : $(OBJS) | $(BUILD_DIR)
	@echo "------ Make $(BIN) ------"
	rm -f $(BIN)
	$(CC) $(CC_FLAGS) -o $(BIN) $(OBJS) $(LDFLAGS)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "------ Make $(@) ------"
	rm -f $@
	$(CC) $(CC_FLAGS) -c -o $@ $< $(LDFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(BUILD_DIR)/*.d

clean:
	rm -rf $(BUILD_DIR)/*
