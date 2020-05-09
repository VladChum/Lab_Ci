TARGET = lab.exe
CC = gcc

all: build run clean
Lab6.o: Source.c
	$(CC) -c -o Lab6.o Source.c
build: Lab6.o
	$(CC) -o Lab6 Lab6.o
run:
	Lab6.exe
clean:
	del *.o Lab6 