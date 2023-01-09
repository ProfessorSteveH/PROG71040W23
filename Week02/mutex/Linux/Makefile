CXX = gcc 

CXXFLAGS = -Wall
LDFLAGS = -lpthread -lrt

all: mutex

mutex: mutex.o
	$(CXX)  mutex.o -o mutex $(LDFLAGS)

mutex.o: mutex.c
	$(CXX) $(CXXFLAGS) -c mutex.c

clean:
	rm mutex *.o
