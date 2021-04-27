all: main.c countingSort.o radixsort.o freestr.o print.o
	gcc main.c countingSort.o radixsort.o freestr.o print.o -o main

countingSort.o: countingSort.c countingSort.h
	gcc -c countingSort.c -o countingSort.o

radixsort.o: radixsort.c radixsort.h
	gcc -c radixsort.c -o radixsort.o

print.o: print.c print.h
	gcc -c print.c -o print.o

freestr.o: freestr.c freestr.h
	gcc -c freestr.c -o freestr.o

clean: 
	rm -f countingSort.o radixsort.o freestr.o print.o main
