CC	=	gcc
CFLAGS	=	-c	-Wall

all: build run clean

magic:	Doctors.obj	Patients.obj	Source.obj
	$(CC)	-o	magic	Doctors.obj	Patients.obj	Source.obj 

Source.o:	Source.c
	$(CC)	$(CFLAGS)	Source.c

Doctors.o:	Doctors.c
	$(CC) $(CFLAGS)	Doctors.c

Patients.o:	Patients.c
	$(CC) $(CFLAGS)	Patients.c
	
build: Source.o	Patients.o	Doctors.o
	$(CC) -o lab7 Source.o	Patients.o	Doctors.o
	
run:
	lab7.exe
clean:
	del *.o lab7  