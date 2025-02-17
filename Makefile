CC = gcc
CFLAGS = -fopenmp

all: program
program: task.o
	$(CC) $(CFLAGS) -o program task.o -lgomp
task.o: task.c
	$(CC) $(CFLAGS) -c task.c

clean:
	rm -f *.o program
