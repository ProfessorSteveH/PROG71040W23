CXX = gcc 

CXXFLAGS = -Wall -g
LDFLAGS = -lpthread 

all: main

main: main.o
	$(CXX)  main.o -o main $(LDFLAGS)

main.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c

clean:
	rm main *.o
