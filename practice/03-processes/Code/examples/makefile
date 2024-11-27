# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -Wextra -std=c11

# Source files
SRC = eexec.c efork.c ekill.c ewait.c

# Output binaries
BIN = eexec efork ekill ewait

# Default target
all: $(BIN)

# Compilation rules
eexec: eexec.c
	$(CC) $(CFLAGS) eexec.c -o eexec

efork: efork.c
	$(CC) $(CFLAGS) efork.c -o efork

ekill: ekill.c
	$(CC) $(CFLAGS) ekill.c -o ekill

ewait: ewait.c
	$(CC) $(CFLAGS) ewait.c -o ewait

# Clean up compiled binaries
clean:
	rm -f $(BIN)
