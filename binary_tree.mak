CC = gcc
CFLAGS = -Wall

all: binary_tree

binary_tree: main.o binary_tree.o
	$(CC) $(CFLAGS) -o binary_tree main.o binary_tree.o

main.o: main.c binary_tree.h
	$(CC) $(CFLAGS) -c main.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c binary_tree.c

clean:
	rm -f *.o binary_tree