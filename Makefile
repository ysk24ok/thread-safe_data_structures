CC = g++
CFLAGS = -Wall -I. -std=c++11

all: example_stack

example_stack: example/stack.cpp stack.o
	$(CC) $(CFLAGS) -pthread -o $@ $<

stack.o: stack.cpp stack.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:; rm -f ./*.o ./example_*
