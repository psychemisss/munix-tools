all: fs/fs vm/vm
	mkdir bin
	cat fs/fs > bin/fs
	cat vm/vm > bin/vm

fs/fs:
	(cd fs; make)

vm/vm:
	(cd vm; make)

clean:
	rm -f -r bin
	(cd fs; make clean)
	(cd vm; make clean)
