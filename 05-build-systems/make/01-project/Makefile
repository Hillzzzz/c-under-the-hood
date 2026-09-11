CC=gcc
CFLAGS=-std=c17 -Wall -Wextra -Wpedantic
app: students.o main.o
	$(CC) $(CFLAGS) students.o main.o -o app
main.o: main.c students.h
	$(CC) $(CFLAGS) -c main.c
students.o: students.c students.h
	$(CC) $(CFLAGS) -c students.c
clean:
	rm -f main.o students.o app
run:
	./app