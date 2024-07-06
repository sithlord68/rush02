CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 

all: rush-02

rush-02: -o main.o part.o
	$(CC) $(LDFLAGS) -o rush-02 main.o part.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

part.o: part.c
	$(CC) $(CFLAGS) -c part.c 

clean:
	rm -f *.o rush-02