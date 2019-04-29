CC = gcc -Wall
CFLAGS = -c

all: vm

vm: vm.o
	$(CC) $< -o $@

vm.o: vm.c
	$(CC) $(CFLAGS) $< -o $@

