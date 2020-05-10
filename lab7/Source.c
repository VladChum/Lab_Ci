#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Doctors.h"
#include "Patients.h"	
#include "Header.h"

int main(void)
{
	int switch_menu;
	
	int switch_departaments_menu;
	int switch_departament_menu;
	int switch_chambers;
	int kol_patients;

	//everu element array this kol free places in departament
	int* free_places = malloc(4 * sizeof(int));  
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		free_places[i] = 24;
	}
	free_places[3] = 3;
	//free_palces[3] - neurologikal departament have 3 free places for clarity

	char* menu;
	struct Doctors* doctor = NULL;
	struct Patients* patient = NULL;
	
	FILE* Doctors;
	Doctors = fopen("Doctors.txt", "r+");
	if (Doctors == NULL)
	{
		printf("Error opening file\n");
		exit(4);
	}
	else
	{
		printf("File is open\n");
		while (doctors_Input(&doctor, Doctors));
	}

	FILE* Patients;
	Patients = fopen("Patients.txt", "r+");
	if (Patients == NULL)
	{
		printf("Error opening file\n");
		exit(4);
	}
	else
	{
		printf("File is open\n");
		while (patients_Input(&patient, Patients));
	}
	char* departament = calloc(128, sizeof(char));
	
	while (1)
	{
		switch_menu = 0;
		switch_departament_menu = 0;
		switch_departaments_menu = 0;
		switch_chambers = 0;
		Start_menu();
		
		switch_menu = check(0, 6);
		switch (switch_menu)
		{
		case 1:
			menu = "departaments";
			departaments_menu(menu);
			switch_departaments_menu = check(0, 5);	
			if (switch_departaments_menu == 5) break;
			switch (switch_departaments_menu)
			{
			case 1:
				departament = "therapeutic";
				break;
			case 2:
				departament = "cardeologi";
				break;
			case 3:
				departament = "surgery";
				break;
			case 4:
				departament = "neurological";
				break;
			case 5:
				departament = "back";
				break;
			}
			departament_menu(menu, departament, free_places[switch_departaments_menu - 1]);
			switch_departament_menu = check(0, 4);
			if (switch_departament_menu == 5) break;				
			switch (switch_departament_menu)
			{
			case 1:
				Scanf_doctors_on_this_departament(departament, doctor);
				break;
			case 2:
				Scanf_patients_on_this_departament(departament, patient);
				break;
			case 3:				//print historu
				kol_patients = show_patients_on_departament(departament, patient);
				if (kol_patients > 0)
				{
					int number_patient;
					number_patient = check(0, kol_patients);
					print_histori(patient, departament, number_patient);
				}
				break;
			case 4:
				break;
			}
			break;
		case 2:
			push_doctor(&doctor);			
			break;
		case 3:
			push_patients(&patient, free_places, patient, doctor);		
			break;
		case 4:
			load_on_departament(free_places);
			break;
		case 5:
			printf("Menu -> print histori -> ");
			menu = "print histori";
			departaments_menu(menu);
			switch_departaments_menu = check(0, 5);
			if (switch_departaments_menu == 5) break;
			switch (switch_departaments_menu)
			{
			case 1:
				departament = "therapeutic";
				break;
			case 2:
				departament = "cardeologi";
				break;
			case 3:
				departament = "surgery";
				break;
			case 4:
				departament = "neurological";
				break;
			case 5:
				departament = "back";
				break;
			}
			kol_patients = show_patients_on_departament(departament, patient);
			if (kol_patients > 0)
			{
				int number_patient;
				number_patient = check(0, kol_patients);
				print_histori(patient, departament, number_patient);
			}
			break;
		case 6:	  //exit
			In_file_doctors(doctor, Doctors);
			In_file_patients(patient, Patients);
			fclose(Doctors);
			fclose(Patients);
			free(free_places);
			free(departament);
			exit(0);
		}
	}
	return 0;
}

void Start_menu()
{
	printf("Menu\n");
	printf("1) departament\n");
	printf("2) add doctors\n");
	printf("3) add patient\n");
	printf("4) load on departaments\n");
	printf("5) print histori\n");
	printf("6) Exit\n");
}

void departaments_menu(char* menu)
{	
	printf("\n%s -> ...\n", menu );
	printf("\n1) therapeutic department	(1-2 floor)\n");
	printf("2) cardiology department	(3-4 floor)\n");
	printf("3) surgery department		(5-6 floor)\n");
	printf("4) neurological department	(7-8 floor)\n");
	printf("5) back\n");
}

void departament_menu(char* menu, char* depatament, int kol_free_mests)
{
	printf("\n%s -> %s\ -> ...\n", menu, depatament);
	printf("In this departamen %d mests", kol_free_mests);
	printf("\n1) doctors in this department\n");
	printf("2) patientsin this department\n");
	printf("3) print histori pathion in this departament\n");
	printf("4) back\n");
}

int check(int min, int max)
{
	int num = 0;
	char temp = '\n';
	do
	{
		scanf("%d", &num);
		if (num > min && num <= max)
		{
			break;
		}
		rewind(stdin);
		printf("\nError: Incorrect input !!! Pleas repeat enter\n\n");
	} while (1);
	return num;
}



void load_on_departament(int* free_places)
{
	printf("\nMenu -> load on departaments\n");
	if (free_places[0] > 0)
	{
		printf("1) terapeutic  : all mests 24 , free masts %d\n", free_places[0]);
	}
	else
	{
		printf("1) terapeutic  : all mests 24 , free masts 0 and %d peaple in queue\n", abs(free_places[0]));
	}

	if (free_places[1] > 0)
	{
		printf("2) cardiologi  : all mests 24 , free masts %d\n", free_places[1]);
	}
	else
	{
		printf("2) cardiologi  : all mests 24 ,free masts 0 and %d peaple in queue\n", abs(free_places[1]));
	}

	if (free_places[2] > 0)
	{
		printf("3) surgery     : all mests 24 , free masts %d\n", free_places[2]);
	}
	else
	{
		printf("3) surgery     : all mests 24 , free masts 0 and %d peaple in queue\n", abs(free_places[2]));
	}

	if (free_places[3] > 0)
	{
		printf("4) neurological: all mests 3  , free masts %d\n", free_places[3]);
	}
	else
	{
		printf("4) neurological: all mests 3  , free masts 0 and %d peaple in queue\n", abs(free_places[3]));
	}

	printf("\nPress any keys to go Menu\n");
	getch();
}

int check_date(int start_day, int start_mans, int start_year, int end_day, int end_mans, int end_year)
{
	int sum_start;
	sum_start = start_day + start_mans * 31 + 372 * (start_year - 2018);
	int sum_end;
	sum_end = end_day + end_mans * 31 + 372 * (end_year - 2018);

	if (sum_end >= sum_start)
	{
		return 1;
	}
	else
	{
		printf("\nError!!! Discharge date cannot be less %d.%d.%d.\n",
			start_day, start_mans, start_year);
		return 0;
	}
}

int check_free_place_in_departament(int* free_places, char* departament)
{
	if (departament == "therapeutic") return free_places[0]--;
		else
	if (departament == "cardiology") return free_places[1]--;
		else
	if (departament == "surgery") return free_places[2]--;
		else
	if (departament == "neurological") return free_places[3]--;
	
}

int doctors_Input(struct Doctors** doctor, FILE* Doctors)
{
	struct Doctors* new_doctor = (struct Doctors*)malloc(sizeof(struct Doctors));
	if (fscanf(Doctors, "%s %s %s %s %s %d %s", new_doctor->surname, 
		new_doctor->name, new_doctor->father_name, new_doctor->position, 
		new_doctor->spesialty, &new_doctor->kol_patients,
		new_doctor->departament) != EOF)
	{
		new_doctor->next = NULL;
		new_doctor->prev = (doctor);
		if ((*doctor) != NULL)
			(*doctor)->next = new_doctor;

		(*doctor) = new_doctor;
		return 1;
	}
	else return 0;

}


int patients_Input(struct Patients** patient, FILE* Patient)
{
	struct Patients* new_patient = (struct Doctors*)malloc(sizeof(struct Doctors));
	if (fscanf(Patient, "%s %s %s %s %s %d %d %d %d %d %d %d %s %s %d %s",
		new_patient->surname, new_patient->name, new_patient->father_name,
		new_patient->address, new_patient->departament, &new_patient->year_of_birth, &new_patient->arrival_day,
		&new_patient->arrival_mans, &new_patient->arrivel_year, &new_patient->discarge_day, &new_patient->discarge_mans,
		&new_patient->discarge_year, new_patient->deagnosis, new_patient->treatment_history, &new_patient->chember_number,
		new_patient->doctor) != EOF)
	{
		new_patient->next = NULL;
		new_patient->prev = (patient);
		if ((*patient) != NULL)
			(*patient)->next = new_patient;

		(*patient) = new_patient;
		return 1;
	}
	else return 0;

}

void In_file_doctors(struct Doctors* doctor, FILE* Doctors)
{	
	while (doctor != NULL)
	{
		fprintf(Doctors, "%s %s %s %s %s %d %s\n",
			doctor->surname, doctor->name, doctor->father_name, doctor->position, doctor->spesialty, doctor->kol_patients, doctor->departament);
		doctor = doctor->next;
	}
	
}

void In_file_patients(struct Patients* patient, FILE* Patients)
{
	while (patient != NULL)
	{
		fprintf(Patients, "%s %s %s %s %s %d %d %d %d %d %d %d %s %s %d %s\n",
			patient->surname, patient->name, patient->father_name,
			patient->address, patient->departament, patient->year_of_birth, patient->arrival_day,
			patient->arrival_mans, patient->arrivel_year, patient->discarge_day, patient->discarge_mans,
			patient->discarge_year, patient->deagnosis, patient->treatment_history, patient->chember_number,
			patient->doctor);
		patient = patient->next;
	}

}