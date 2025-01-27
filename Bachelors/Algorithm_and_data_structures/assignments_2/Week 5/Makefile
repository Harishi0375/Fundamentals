CC = g++
CFLAGS = -Wall -Wextra -g -std=c++14


all: fib

fib: fib.o main.o
	$(CC) $(CFLAGS) -o fib fib.o main.o 

fib.o: fib.cpp fib.h
	$(CC) $(CFLAGS) -c fib.cpp

main.o: main.cpp fib.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f fib *.o