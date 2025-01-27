CC = g++
CFLAGS = -Wall -std=c++11

all: a1_p1 testStack Vector1 Vector2

a1_p1: a1_p1.cpp
	$(CC) $(CFLAGS) -o a1_p1 a1_p1.cpp

testStack: testStack.cpp Stack.h
	$(CC) $(CFLAGS) -o testStack testStack.cpp


Vectors1: Vectors1.cpp
	$(CC) $(CFLAGS) -o Vector1 Vector1.cpp

Vectors2: Vectors2.cpp
	$(CC) $(CFLAGS) -o Vector2 Vector2.cpp

clean:
	rm -f a1_p1 testStack testLinkedList Vectro1 Vector2
