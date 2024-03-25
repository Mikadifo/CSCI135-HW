CC = g++ -std=c++11

all: run

run: CircuitClient.o Circuit.o
	$(CC) -o run CircuitClient.o Circuit.o

CircuitClient.o:  CircuitClient.cpp
	$(CC) -c CircuitClient.cpp

Circuit.o:  Circuit.cpp
	$(CC) -c Circuit.cpp

clean: 
	$(RM) memory *.o *~
