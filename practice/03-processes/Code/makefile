# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -Wextra -std=c11
SRC_DIR = src
BIN_DIR = bin

# Source files and output binaries
SRC = $(SRC_DIR)/shell_args.c $(SRC_DIR)/shell_simple.c $(SRC_DIR)/zombie.c
BIN = $(BIN_DIR)/shell_args $(BIN_DIR)/shell_simple $(BIN_DIR)/zombie

# Phony targets
.PHONY: all clean shell_args shell_simple zombie

# Default target
all: $(BIN)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Individual targets
shell_args: $(BIN_DIR)/shell_args
shell_simple: $(BIN_DIR)/shell_simple
zombie: $(BIN_DIR)/zombie


# Compilation rules
$(BIN_DIR)/shell_args: $(SRC_DIR)/shell_args.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/shell_args.c -o $(BIN_DIR)/shell_args

$(BIN_DIR)/shell_simple: $(SRC_DIR)/shell_simple.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/shell_simple.c -o $(BIN_DIR)/shell_simple

$(BIN_DIR)/zombie: $(SRC_DIR)/zombie.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/zombie.c -o $(BIN_DIR)/zombie

# Clean up binaries
clean:
	rm -f $(BIN) 
	rmdir $(BIN_DIR)
