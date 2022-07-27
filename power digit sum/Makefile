all: compile link clean

compile: main.c
	gcc -c main.c

link: main.o
	gcc -o main main.o

clean:
	del *.o