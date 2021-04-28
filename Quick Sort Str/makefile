all: main.c partition.o quicksort.o print.o freestr.o
	gcc main.c partition.o quicksort.o print.o freestr.o -o main

partition.o: partition.c partition.h
	gcc -c partition.c -o partition.o

quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c -o quicksort.o

print.o: print.c print.h
	gcc -c print.c -o print.o

freestr.o: freestr.c freestr.h
	gcc -c freestr.c -o freestr.o

clean: 
	rm -f partition.o quicksort.o print.o freestr.o main
