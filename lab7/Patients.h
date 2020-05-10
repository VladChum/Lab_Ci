#pragma once
#ifndef PATIENTS_H
#define PATIENTS_H
#include <stdlib.h>
#define STR_BUFFER 128

// DLL patient
struct Patients {
	char surname[STR_BUFFER];
	char name[STR_BUFFER];
	char father_name[STR_BUFFER];
	char address[STR_BUFFER];
	char deagnosis[STR_BUFFER];
	char departament[STR_BUFFER];
	char treatment_history[STR_BUFFER];
	char doctor[STR_BUFFER];
	int year_of_birth;
	int arrival_day;
	int arrival_mans;
	int arrivel_year;
	int discarge_day;
	int discarge_mans;
	int discarge_year;
	int chember_number;
	struct Patients* next;
	struct Patients* prev;
};


void search_nearest_date(struct Patients* patient, char* departament);

int  show_patients_on_departament(char* departament, struct Patients* patient);

void Scanf_patients_on_this_departament(char* departament, struct Patients* patient);

void print_histori(struct Patients* patient, char* departament, int number_patinent);

void push_patients(struct Patients** head_ref, int* free_places, struct Patients* patient, struct Doctors* docto);

#endif