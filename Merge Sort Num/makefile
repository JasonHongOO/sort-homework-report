all: main.c merge.o mergeSort.o print.o
	gcc main.c merge.o mergeSort.o print.o -o main

merge.o: merge.c merge.h
	gcc -c merge.c -o merge.o

mergeSort.o: mergeSort.c mergeSort.h
	gcc -c mergeSort.c -o mergeSort.o

print.o: print.c print.h
	gcc -c print.c -o print.o

clean: 
	rm -f mergeSort.o merge.o print.o main
