CXX = gcc 

CXXFLAGS = -Wall
LDFLAGS = -lpthread 

all: createThreads

createThreads: createThreads.o
	$(CXX)  createThreads.o -o createThreads $(LDFLAGS)

createThreads.o: createThreads.c
	$(CXX) $(CXXFLAGS) -c createThreads.c

clean:
	rm createThreads *.o
