all: main.c countingSort.o radixsort.o getMax.o print.o
	gcc main.c countingSort.o radixsort.o getMax.o print.o -o main

countingSort.o: countingSort.c countingSort.h
	gcc -c countingSort.c -o countingSort.o

radixsort.o: radixsort.c radixsort.h
	gcc -c radixsort.c -o radixsort.o

print.o: print.c print.h
	gcc -c print.c -o print.o

getMax.o: getMax.c getMax.h
	gcc -c getMax.c -o getMax.o

clean: 
	rm -f countingSort.o radixsort.o getMax.o print.o main
