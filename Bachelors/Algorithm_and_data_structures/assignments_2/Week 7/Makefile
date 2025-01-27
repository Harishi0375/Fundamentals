CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: main

main: quick.o main.o
	$(CC) $(CFLAGS) -o main quick.o main.o

quick.o: quick.cpp quick.h
	$(CC) $(CFLAGS) -c quick.cpp

main.o: main.cpp quick.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o main