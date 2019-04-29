CC = gcc -Wall
CFLAGS = -c

all: fs

fs: fs.o
	$(CC) $< -o $@

fs.o: fs.c
	$(CC) $(CFLAGS) $< -o $@
