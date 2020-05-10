#pragma once
#ifndef DOCTORS_H
#define DOCTORS_H
#include <stdlib.h>
#define STR_BUFFER 128

//DLL doctors
struct Doctors {
	char surname[STR_BUFFER];
	char name[STR_BUFFER];
	char father_name[STR_BUFFER];
	char position[STR_BUFFER];
	char departament[STR_BUFFER];
	char spesialty[STR_BUFFER];
	int kol_patients;
	struct Doctors* next;
	struct Doctors* prev;
};

void push_doctor(struct Doctors** head_ref);

char* scanf_departament();

void Scanf_doctors_on_this_departament(char* departament, struct Doctors* doctor);

int doctors_on_this_departament(char* departament, struct Doctors* doctor);

char* choose_doctor(struct Doctors* doctor, char* departament);

int doctors_on_this_departament(char* departament, struct Doctors* doctor);


#endif