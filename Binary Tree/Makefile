CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: bt

bt: bt.o
	$(CC) -o bt bt.o

bt.o: bt.c bt.h
	$(CC) $(CFLAGS) -c bt.c

clean:
	rm -f bt bt.o

format:
	clang-format -i -style=file *.[ch]
