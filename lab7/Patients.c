#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Doctors.h"
#include "Patients.h"

void search_nearest_date(struct Patients* patient, char* departament)
{
	struct Patients* last;
	int min_date = 30000;
	char* surname;
	int min_day = 0;
	int min_mans = 0;
	int min_year = 0;
	while (patient != NULL)
	{
		if (patient->departament == departament)
		{
			int sum = patient->arrival_day + 31 * patient->arrival_mans
				+ (patient->arrivel_year - 2018) * 372;
			if (sum < min_date)
			{
				min_date = sum;
				min_day = patient->discarge_day;
				min_mans = patient->discarge_mans;
				min_year = patient->discarge_year;
			}
		}

		last = patient;
		patient = patient->next;
	}

	printf("\nThe nearest date when you can put patient: %d.%d.%d\n",
		min_day, min_mans, min_year);
	printf("But fill out the form and you will be recorded in the queue\n");
}

int show_patients_on_departament(char* departament, struct Patients* patient)		//return kol patiens departament
{
	printf("Menu ->  print historu -> Departament -> %s \nEnter number patient:\n", departament);
	int number_patients = 0;
	while (patient != NULL)
	{
		if (strcmp(patient->departament, patient) == 0)
		{
			number_patients++;
			printf("%d) %s\t%s\t%s\t%s\t%d\n",
				number_patients, patient->surname, patient->name, patient->father_name, patient->deagnosis, patient->chember_number);
		}
		patient = patient->next;
	}

	if (number_patients == 0)
		printf("In this time this departament free!\n\n");

	return number_patients;
}

void Scanf_patients_on_this_departament(char* departament, struct Patients* patient)
{
	printf("Departament -> %s -> Patients\n", departament);
	struct Patients* last;
	int kol_patients = 0;
	while (patient != NULL)
	{

		if (strcmp(patient->departament, departament) == 0)
		{
			printf("%s %s %s %s %d\n",
				patient->surname, patient->name, patient->father_name, patient->deagnosis, patient->chember_number);
			kol_patients++;
		}
		last = patient;
		patient = patient->next;
	}
	if (kol_patients == 0)
		printf("In this departament not patients!\n\n)");
}

void print_histori(struct Patients* patient, char* departament, int number_patinent)
{
	int num_patient = 0;
	while (patient != NULL)
	{
		if (patient->departament == departament)
		{
			num_patient++;
			if (number_patinent == num_patient)
			{
				printf("Patirnt: %s %s %s \ndeagnosis: %s \nDoctor : %s\nHistori: %s\n",
					patient->surname, patient->name, patient->father_name,
					patient->deagnosis, patient->doctor, patient->treatment_history);
				break;
			}
		}

		patient = patient->next;
	}
}

void push_patients(struct Patients** head_ref, int* free_places, struct Patients* patient, struct Doctors* docto)
{
	printf("\nMenu -> add patient: ");
	struct Patients* new_patient = (struct Patients*)malloc(sizeof(struct Patients));
	printf("\nEnter Surname: ");
	char* surname = calloc(128, sizeof(char));
	surname = gets(surname);

	printf("Name: ");
	char* name = calloc(128, sizeof(char));;
	name = gets(name);

	printf("Father name: ");
	char* father_name = calloc(128, sizeof(char));;
	father_name = gets(father_name);

	printf("Enter address: ");
	char* address = calloc(128, sizeof(char));;
	address = gets(address);

	char* departament;
	departament = scanf_departament();
	if (check_free_place_in_departament(free_places, departament) < 1)
		search_nearest_date(patient, departament);

	printf("Enter year of birth: ");
	int year_of_birth;
	year_of_birth = check(1900, 2020);

	printf("Enter date arrive(min date 1.1.2018): ");
	int arrival_day;
	int arrival_mans;
	int arrivel_year;
	printf("Enter day: ");
	arrival_day = check(0, 31);
	printf("Enter mans: ");
	arrival_mans = check(0, 12);
	printf("Enter year: ");
	arrivel_year = check(2017, 2020);


	int discarge_day;
	int discarge_mans;
	int discarge_year;
	int repit_input_date = 0;
	while (repit_input_date == 0)
	{
		printf("Enter date discarge: ");

		printf("Enter day: ");
		discarge_day = check(0, 31);
		printf("Enter mans: ");
		discarge_mans = check(0, 12);
		printf("Enter year: ");
		discarge_year = check(2017, 2021);
		repit_input_date = check_date(arrival_day, arrival_mans, arrivel_year,
			discarge_day, discarge_mans, discarge_year);
	}

	
	printf("Deagnosis: ");
	char* deagnosis = calloc(128, sizeof(char));;
	deagnosis = gets(deagnosis);

	printf("treatment history: ");
	char* treatment_history = calloc(256, sizeof(char));;
	treatment_history = gets(treatment_history);

	printf("Chang a doctors: ");
	char* doctor;
	doctor = choose_doctor(docto, departament);

	printf("Enter number of chember (1 - 10): ");
	int chember_number;
	chember_number = check(0, 10);

	strcpy(new_patient->surname, surname);
	strcpy(new_patient->name, name);
	strcpy(new_patient->father_name, father_name);
	strcpy(new_patient->departament, departament);
	strcpy(new_patient->address, address);
	strcpy(new_patient->deagnosis, deagnosis);
	new_patient->year_of_birth = year_of_birth;
	new_patient->arrival_day = arrival_day;
	new_patient->arrival_mans = arrival_mans;
	new_patient->arrivel_year = arrivel_year;
	new_patient->chember_number = chember_number;
	new_patient->discarge_day = discarge_day;
	new_patient->discarge_mans = discarge_mans;
	new_patient->discarge_year = discarge_year;
	strcpy(new_patient->treatment_history, treatment_history);
	strcpy(new_patient->doctor, doctor);
	new_patient->next = (*head_ref);
	new_patient->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_patient;

	(*head_ref) = new_patient;

}