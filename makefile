all: reverse.c file_utils.c
	clang -o reverse reverse.c file_utils.c 
clean:
	rm reverse myFile1.txt
run:
	./reverse myFile.txt myFile1.txt
complete:
	make clean && make && make run
