# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -g

# Define the target executable
TARGET = testCase

# Define the source files and object files
SRCS = main.cpp Process.cpp Scheduler.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean