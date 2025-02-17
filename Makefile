CC = gcc
CFLAGS = -fopenmp

all: task.o
program: task.o
	$(CC) $(CFLAGS) -o task.o task.o
task.o: task.c
	$(CC) $(CFLAGS) -c task.c

clean:
	rm -f *.o program
