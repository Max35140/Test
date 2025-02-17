CC = gcc
CFLAGS = -fopenmp

all: program
program: task.o
	$(CC) $(CFLAGS) program -o task.o
task.o: task.c
	$(CC) $(CFLAGS) -c task.c

clean:
	rm -f *.o program
