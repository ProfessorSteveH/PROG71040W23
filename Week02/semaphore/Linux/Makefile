CXX = gcc 

CXXFLAGS = -Wall
LDFLAGS = -lpthread -lrt

all: semaphores

semaphores: semaphores.o
	$(CXX)  semaphores.o -o semaphores $(LDFLAGS)

semaphores.o: semaphores.c
	$(CXX) $(CXXFLAGS) -c semaphores.c

clean:
	rm semaphores *.o
