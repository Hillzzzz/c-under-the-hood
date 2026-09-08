app: main.o command.o
	cc main.o command.o -o app

main.o: main.c command.h
	cc -c main.c

command.o: command.c command.h
	cc -c command.c

clean:
	rm -f app main.o command.o