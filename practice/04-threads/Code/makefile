# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -Wextra -std=c11
SRC_DIR = src
BIN_DIR = bin

# Source files and output binaries
SRC = $(SRC_DIR)/array_sum.c $(SRC_DIR)/bank.c $(SRC_DIR)/increment_mutex.c
BIN = $(BIN_DIR)/array_sum $(BIN_DIR)/bank $(BIN_DIR)/increment_mutex

# Phony targets
.PHONY: all clean array_sum bank increment_mutex

# Default target
all: $(BIN)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Individual targets
array_sum: $(BIN_DIR)/array_sum
bank: $(BIN_DIR)/bank
increment_mutex: $(BIN_DIR)/increment_mutex

# Compilation rules
$(BIN_DIR)/array_sum: $(SRC_DIR)/array_sum.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/array_sum.c -o $(BIN_DIR)/array_sum

$(BIN_DIR)/bank: $(SRC_DIR)/bank.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/bank.c -o $(BIN_DIR)/bank

$(BIN_DIR)/increment_mutex: $(SRC_DIR)/increment_mutex.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/increment_mutex.c -o $(BIN_DIR)/increment_mutex

# Clean up binaries
clean:
	rm -f $(BIN)
	rmdir $(BIN_DIR)
