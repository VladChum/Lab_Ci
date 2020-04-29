TARGET = lab.exe
CC = gcc

all: build run clean
LR5.o: Source.c
	$(CC) -c -o LR5.o Source.c
build: LR5.o
	$(CC) -o LR5 LR5.o
run:
	LR5.exe
clean:
	del *.o LR5  