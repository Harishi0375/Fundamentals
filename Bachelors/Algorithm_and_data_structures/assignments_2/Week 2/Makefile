# create a Makefile
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

all: a2_p1 a2_p2 a2_p4 a2_p5

a2_p1: a2_p1.cpp
	$(CC) $(CFLAGS) -o a2_p1 a2_p1.cpp

a2_p2: a2_p2.cpp
	$(CC) $(CFLAGS) -o a2_p2 a2_p2.cpp

a2_p3 : WindGauge.cpp testWindGauge.cpp
	$(CC) $(CFLAGS) -o a2_p3 WindGauge.cpp testWindGauge.cpp

a2_p4 : a2_p4.cpp
	$(CC) $(CFLAGS) -o a2_p4 a2_p4.cpp

a2_p5 : a2_p5.cpp
	$(CC) $(CFLAGS) -o a2_p5 a2_p5.cpp

clean:
	rm -f a2_p1 a2_p2 a2_p3 a2_p4 a2_p5 a2_p6
