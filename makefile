CC = gcc
CFlags = -Wall -g
OBJECTS = main.o algo.o nodes.o edges.o

all: graph

graph: $(OBJECTS)
	$(CC) $(CFlags) $(OBJECTS) -o graph

edges.o: edges.c edges.h
	$(CC) $(CFlags) -c edges.c

algo.o: algo.c algo.h
	$(CC) $(CFlags) -c algo.c

nodes.o: nodes.c nodes.h
	$(CC) $(CFlags) -c nodes.c

main.o : main.c edges.h algo.h nodes.h
	$(CC) $(CFlags) -c main.c

.PHONY:clean all

clean:
	rm -f *.o graph