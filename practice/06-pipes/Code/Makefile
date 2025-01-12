# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic

# Executables with .out extension
EXECS = 00-introduction.out 01-ls-pipe-grep.out 02-ls-pipe-grep-pipe-cowsay.out 03-sender.out 03-receiver.out

# Default target
all: $(EXECS)

# Rules to compile each executable
00-introduction.out: 00-introduction.c
	$(CC) $(CFLAGS) -o $@ $<

01-ls-pipe-grep.out: 01-ls-pipe-grep.c
	$(CC) $(CFLAGS) -o $@ $<

02-ls-pipe-grep-pipe-cowsay.out: 02-ls-pipe-grep-pipe-cowsay.c
	$(CC) $(CFLAGS) -o $@ $<

03-sender.out: 03-sender.c
	$(CC) $(CFLAGS) -o $@ $<

03-receiver.out: 03-receiver.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up build artifacts
clean:
	rm -f $(EXECS)

# Phony targets
.PHONY: all clean
