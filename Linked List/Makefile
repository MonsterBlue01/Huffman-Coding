CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: ll

ll: ll.o
	$(CC) -o ll ll.o

ll.o: ll.c ll.h
	$(CC) $(CFLAGS) -c ll.c

clean:
	rm -f ll ll.o

format:
	clang-format -i -style=file *.[ch]
