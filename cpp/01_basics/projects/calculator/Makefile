CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
DEBUGFLAGS = -g

SRCS = main.cpp calculator.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = calculator

all: $(TARGET)

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean debug run