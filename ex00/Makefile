CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 

all: rush-02

rush-02: main.o part.o read.o parse.o 
	$(CC) $(LDFLAGS) -o rush-02 main.o part.o read.o parse.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

part.o: part.c
	$(CC) $(CFLAGS) -c part.c 

read.o: read.c 
	$(CC) $(CFLAGS) -c read.c 

parse.o: parse.c 
	$(CC) $(CFLAGS) -c parse.c 

fclean:
	rm -f *.o