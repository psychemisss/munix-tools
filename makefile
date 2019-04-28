CC=gcc
FLAGS=-c -Wall

build: fs vm
	make clean
	mkdir bin/


fs:	fs.o
	$(CC) fs.o -o fs

fs.o: fs.c
	$(CC) $(FLAGS) fs.c


vm:
	$(CC) vm.o -o vm

vm.o:	vm/vm.c
	$(CC) $(FLAGS) vm.c

clean:
	rm -rf bin/
