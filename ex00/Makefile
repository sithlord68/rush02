CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 

all: rush-02

rush-02: rush02.o part.o translate.o strings.o readdict.o is.o
	$(CC) $(LDFLAGS) -o rush-02 rush02.o part.o translate.o strings.o readdict.o is.o

rush02.o: rush02.c
	$(CC) $(CFLAGS) -c rush02.c 

part.o: part.c
	$(CC) $(CFLAGS) -c part.c 

translate.o: translate.c
	$(CC) $(CFLAGS) -c translate.c

strings.o: strings.c
	$(CC) $(CFLAGS) -c strings.c 

readdict.o: readdict.c
	$(CC) $(CFLAGS) -c readdict.c 

is.o: is.c
	$(CC) $(CFLAGS) -c is.c 

fclean:
	rm -f *.o rush-02