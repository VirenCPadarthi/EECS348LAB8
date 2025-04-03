CC = g++
CFLAGS = -std=c++11

# Target to build the executable
all: matrixOperations

matrixOperations: main.cpp matrix.cpp
	$(CC) $(CFLAGS) -o matrixOperations main.cpp matrix.cpp

# Clean up the build files
clean:
	rm -f matrixOperations
