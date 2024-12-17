# Makefile for big_odd_number.cpp
# ifneq (,$(wildcard .env))
#     include .env
#     export
# endif

# Compiler flags
CFLAGS = -std=c++14 -O2

# Target executable
TARGET = main

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files
OBJS = $(SRCS:src/%.cpp=obj/%.o)

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJS)
	# scl enable gcc-toolset-12 bash
	$(CXX) $(CFLAGS) -o bin/$@ $^

# Compile the source files
obj/%.o: src/%.cpp
	# scl enable gcc-toolset-12 bash
	$(CXX) $(CFLAGS) -Iinc -c -o $@ $<

# Clean up
clean:
	rm -f $(OBJS) bin/$(TARGET)

.PHONY: all clean