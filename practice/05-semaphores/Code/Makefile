CC = gcc
CFLAGS = -Wall -pthread
SOURCES = 00-anonymous.c 00-named.c 01-library.c 01-library-threads.c
TARGETS = anonymous named library library_threads
OUT_DIR = out

all: $(TARGETS)

anonymous: 00-anonymous.c
	$(CC) $(CFLAGS) -o $@ $<

named: 00-named.c
	$(CC) $(CFLAGS) -o $@ $<

library: 01-library.c
	$(CC) $(CFLAGS) -o $@ $<

library_threads: 01-library-threads.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
	rm -f $(OUT_DIR)/*

# Ensure the `out` directory exists for the programs to write their output files.
prepare:
	mkdir -p $(OUT_DIR)

# Default target includes preparing the output directory.
.PHONY: all clean prepare
