CC = gcc
CFlags = -Wall -g

all: graph

graph : main.o algo.o
	$(CC) $(CFlags) main.o algo.o -o graph

algo.o : algo.c nodes.h
	$(CC) $(CFlags) -c algo.c

main.o : main.c nodes.h
	$(CC) $(CFlags) -c main.c

.PHONY:clean all

clean:
	rm -f *.o graph