#pragma once
#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <stdlib.h>
#define STR_BUFFER 128

void Start_menu();

void departament_menu(char* menu, char* departament, int kol_free_mests);

int doctors_Input(struct Doctors** doctor, FILE* Doctors);

int patients_Input(struct Patients** patient, FILE* Patient);

void In_file_doctors(struct Doctors* doctor, FILE* Doctors);

void In_file_patients(struct Patients* patient, FILE* Patients);
void load_on_departament(int* free_places);

int check_date(int start_day, int start_mans, int start_year, int end_day, int end_mans, int end_year);

int check_free_place_in_departament(int* free_places, char* departament);



int check(int min, int max);

void departaments_menu(char* menu);

#endif