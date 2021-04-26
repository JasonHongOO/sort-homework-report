all: main.c f1.o f2.o
	gcc main.c f1.o f2.o -o main

f1.o: f1.c f1.h
	gcc -c f1.c -o f1.o

f2.o: f2.c f2.h
	gcc -c f2.c -o f2.o

clean: 
	rm -f f2.o f1.o main
