# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -Wextra -std=c11
SRC_DIR = src
BIN_DIR = bin

# Source files and output binaries
SRC = $(SRC_DIR)/mycat.c $(SRC_DIR)/mycp.c $(SRC_DIR)/myhead.c $(SRC_DIR)/test.c \
      $(SRC_DIR)/dump.c $(SRC_DIR)/load.c

BIN = $(BIN_DIR)/mycat $(BIN_DIR)/mycp $(BIN_DIR)/myhead $(BIN_DIR)/test \
      $(BIN_DIR)/dump $(BIN_DIR)/load

# Phony targets
.PHONY: all clean mycat mycp myhead test dump load

# Default target
all: $(BIN)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Individual targets
mycat: $(BIN_DIR)/mycat
mycp: $(BIN_DIR)/mycp
myhead: $(BIN_DIR)/myhead
test: $(BIN_DIR)/test
dump: $(BIN_DIR)/dump
load: $(BIN_DIR)/load

# Compilation rules
$(BIN_DIR)/mycat: $(SRC_DIR)/mycat.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/mycat.c -o $(BIN_DIR)/mycat

$(BIN_DIR)/mycp: $(SRC_DIR)/mycp.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/mycp.c -o $(BIN_DIR)/mycp

$(BIN_DIR)/myhead: $(SRC_DIR)/myhead.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/myhead.c -o $(BIN_DIR)/myhead

$(BIN_DIR)/test: $(SRC_DIR)/test.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/test.c -o $(BIN_DIR)/test

$(BIN_DIR)/dump: $(SRC_DIR)/dump.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/dump.c -o $(BIN_DIR)/dump

$(BIN_DIR)/load: $(SRC_DIR)/load.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/load.c -o $(BIN_DIR)/load

# Clean up binaries
clean:
	rm -f $(BIN)
	rmdir $(BIN_DIR)

