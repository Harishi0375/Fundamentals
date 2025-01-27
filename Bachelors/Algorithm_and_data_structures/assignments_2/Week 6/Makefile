CC = g++
CFLAGS = -Wall -Wextra -std=c++11

SRCS = Heap.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = heap

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)