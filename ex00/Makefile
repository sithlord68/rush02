CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 

all: rush-02

rush-02: rush02.o part.o translate.o
	$(CC) $(LDFLAGS) -o rush-02 rush02.o part.o translate.o

main.o: rush02.c
	$(CC) $(CFLAGS) -c rush02.c

translate.o: translate.c
	$(CC) $(CFLAGS) -c translate.c

part.o: part.c
	$(CC) $(CFLAGS) -c part.c 

clean:
	rm -f *.o rush-02