CC = gcc
CFLAGS = -g -Wall
OBJECTS = main.o algo.o nodes.o edges.o

all: $(OBJECTS)
	$(CC) $(CFLAGS) -o graph $(OBJECTS)

algo.o: algo.c algo.h
	$(CC) $(CFLAGS) -c algo.c

nodes.o: nodes.c nodes.h
	$(CC) $(CFLAGS) -c nodes.c

edges.o: edges.c edges.h
	$(CC) $(CFLAGS) -c edges.c

main.o: main.c edges.h nodes.h algo.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f graph *.o my_out1