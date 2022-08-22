CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: ht

ht: ll.o ht.o
	$(CC) ll.o ht.o -o ht

ll.o: ll.c ll.h
	$(CC) $(CFLAGS) -c ll.c

ht.o: ht.c ll.h
	$(CC) $(CFLAGS) -c ht.c

clean:
	rm -f ht ht.o ll.o

format:
	clang-format -i -style=file *.[ch]
