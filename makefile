index: index.o list.o node.o
	gcc -Wall -ansi -pedantic index.o list.o node.o -o index

index.o: index.c node.h list.h
	gcc -g -c -Wall -ansi -pedantic index.c -o index.o

node.o: node.c node.h
	gcc -g -c -ansi -Wall -pedantic node.c -o node.o

list.o: list.c list.h
	gcc -g -c -ansi -Wall -pedantic list.c -o list.o