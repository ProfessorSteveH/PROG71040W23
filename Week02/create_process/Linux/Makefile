CXX = gcc 

CXXFLAGS = -Wall
LDFLAGS =  

all: hello fork_a_child_process 

hello: hello_world.o
	$(CXX)  hello_world.o -o hello $(LDFLAGS)

hello_world.o: hello_world.c
	$(CXX) $(CXXFLAGS) -c hello_world.c

fork_a_child_process: fork_a_child_process.o
	$(CXX) fork_a_child_process.o -o fork_a_child_process $(LDFLAGS)

fork_a_child_process.o: fork_a_child_process.c
	$(CXX) $(CXXFLAGS) -c fork_a_child_process.c

clean:
	rm hello fork_a_child_process *.o
