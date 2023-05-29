CC = gcc
CFLAGS = -std=c89 -Wall -ansi -pedantic

test: test.c
	$(CC) $(CFLAGS) -o test test.c

run: test
	./test

clean:
	rm -f test
