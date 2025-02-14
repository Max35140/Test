CC = gcc
CFLAGS = -fopenmp

all:
	$(CC) $(CFLAGS) task.c -o task.o

clean:
	rm -f *.o program
