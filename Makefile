.POSIX:

example: example.o
	$(CC) -o example example.o

example.o: example.c
	$(CC) -c -o example.o example.c

clean:
	rm -f example example.o
