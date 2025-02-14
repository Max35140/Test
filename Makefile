CC = gcc
CFLAGS = -fopenmp

all:
	$(CC) $(CFLAGS) task.c -o task

clean:
	rm -f *.o program
