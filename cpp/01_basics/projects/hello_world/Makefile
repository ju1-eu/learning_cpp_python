CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: hello_world

hello_world: hello_world.cpp
	$(CXX) $(CXXFLAGS) -o hello_world hello_world.cpp

run: hello_world
	./hello_world

clean:
	rm -f hello_world

.PHONY: all run clean