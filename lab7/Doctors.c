#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Doctors.h"

void push_doctor(struct Doctors** head_ref)
{
	printf("\nMenu -> add doctor");
	struct Doctors* new_node = (struct Doctors*)malloc(sizeof(struct Doctors));
	printf("\nEnter Surname: ");
	char* surname = calloc(128, sizeof(char));
	surname = gets(surname);

	printf("Name: ");
	char* name = calloc(128, sizeof(char));
	name = gets(name);

	printf("Father name: ");
	char* father_name = calloc(128, sizeof(char));
	father_name = gets(father_name);

	printf("Position: ");
	char* position = calloc(128, sizeof(char));
	position = gets(position);

	printf("Enter spesialty: ");
	char* spesialty = calloc(128, sizeof(char));
	spesialty = gets(spesialty);

	new_node->kol_patients = 0;
	strcpy(new_node->surname, surname);
	strcpy(new_node->name, name);
	strcpy(new_node->father_name, father_name);

	strcpy(new_node->departament, scanf_departament());
	strcpy(new_node->position, position);
	strcpy(new_node->spesialty, spesialty);
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;

}

char* scanf_departament()
{
	printf("Enter dapartament\n");
	printf("1) therapeutic department	(1-2 floor)\n");
	printf("2) cardiology department	(3-4 floor)\n");
	printf("3) surgery department		(5-6 floor)\n");
	printf("4) neurological department	(7-8 floor)\n");
	int number = check(0, 4);
	switch (number)
	{
	case 1:
		return "therapeutic";
	case 2:
		return "cardiology";
	case 3:
		return "surgery";
	case 4:
		return "neurological";
	default:
		break;
	}
}

void Scanf_doctors_on_this_departament(char* departament, struct Doctors* doctor)
{
	printf("Departament -> %s -> Doctors\n", departament);
	int kol_doctors = 0;
	while (doctor != NULL)
	{

		if (strcmp(doctor->departament, departament) == 0)
		{
			printf("%s %s %s %s %s %d\n",
				doctor->surname, doctor->name, doctor->father_name, doctor->position, doctor->spesialty, doctor->kol_patients);
			kol_doctors++;
		}
		doctor = doctor->next;
	}
	if (kol_doctors == 0)
		printf("In this departament not doctors!\n\n)");
}

char* choose_doctor(struct Doctors* doctor, char* departament)
{
	printf("Choose you docter: ");
	int kol_doctors;
	kol_doctors = doctors_on_this_departament(departament, doctor);
	if (kol_doctors > 0)
	{
		int number = check(0, kol_doctors);
		struct Doctors* last;
		int number_doctor = 0;
		while (doctor != NULL)
		{

			if (doctor->departament == departament)
			{
				number_doctor++;
				if (number_doctor == kol_doctors)
					doctor->kol_patients = doctor->kol_patients + 1;
				return doctor->surname;
			}
			last = doctor;
			doctor = doctor->next;
		}
	}
}

int doctors_on_this_departament(char* departament, struct Doctors* doctor)
{
	printf("Departament -> %s -> Doctors\n", departament);
	int kol_doctors = 0;
	while (doctor != NULL)
	{

		if (strcmp(doctor->departament, departament) == 0)
		{
			kol_doctors++;
			printf("%d) %s %s %s %s %s %d\n",
				kol_doctors, doctor->surname, doctor->name, doctor->father_name, doctor->position, doctor->spesialty, doctor->kol_patients);

		}

		doctor = doctor->next;
	}
	if (kol_doctors == 0)
		printf("In this departament not doctors!\n\n)");
	return kol_doctors;
}
