CC=gcc
CFLAGS=-std=c15 -Wall -ansi -pedantic

ifdef PULL
CFLAGS += -DPULL
PULL : clean box
endif

box: box.o map.o helper_funcs.o io.o movement.o LinkedList.o
	$(CC) $(CFLAGS) -o box box.o map.o helper_funcs.o io.o movement.o LinkedList.o

box.o: box.c map.h helper_funcs.h io.h LinkedList.h
	$(CC) $(CFLAGS) -c box.c

map.o: map.c map.h helper_funcs.h LinkedList.h
	$(CC) $(CFLAGS) -c map.c

helper_funcs.o: helper_funcs.c helper_funcs.h LinkedList.h
	$(CC) $(CFLAGS) -c helper_funcs.c

io.o: io.c io.h LinkedList.h
	$(CC) $(CFLAGS) -c io.c

movement.o: movement.c movement.h LinkedList.h
	$(CC) $(CFLAGS) -c movement.c

LinkedList.o: LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

clean:
	rm -f box *.o
