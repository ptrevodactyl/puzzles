all: compile link clean

compile: main.cpp
	g++ -c main.cpp

link: main.o
	g++ -o main main.o -lm

clean:
	del *.o