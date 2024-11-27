# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -Wextra -std=c11

# Source files
SRC = eunistd.c estdio.c esystypes.c estat.c efcntl.c eerno.c

# Output binaries
BIN = eunistd estdio esystypes estat efcntl eerno

# Default target
all: $(BIN)

# Compilation rules
eunistd: eunistd.c
	$(CC) $(CFLAGS) eunistd.c -o eunistd

estdio: estdio.c
	$(CC) $(CFLAGS) estdio.c -o estdio

esystypes: esystypes.c
	$(CC) $(CFLAGS) esystypes.c -o esystypes

estat: estat.c
	$(CC) $(CFLAGS) estat.c -o estat

efcntl: efcntl.c
	$(CC) $(CFLAGS) efcntl.c -o efcntl

eerno: eerno.c
	$(CC) $(CFLAGS) eerno.c -o eerno

# Clean up compiled binaries
clean:
	rm -f $(BIN)
