# compiler
CC = g++
# include directories
INCDIRS = -I.
# compiler optimizations
OPT = -O0
# compiler flags
CFLAGS = -Wall -Wextra -g $(INCDIRS) $(OPT)

FILES = main.cpp
OBJECTS = main.o

BINARY = main

all: $(BINARY) clean

# linking
$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# compiling
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	del *.o	