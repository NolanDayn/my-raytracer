CC = g++
CFLAGS = -Wall -g 

raytracer: main.o
	$(CC) $(CFLAGS) -o raytracer main.o

main.o:
	$(CC) $(CFLAGS) -c main.cc
