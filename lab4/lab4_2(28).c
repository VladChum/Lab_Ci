#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <vss.h>

char* FirstFile = "first.txt";
char* Vocabulary = "vocabulary.txt";
char* Result = "result.txt";


int CompareAndChange(char* Word, char* fearst, char* seakond)
{
	int Index = 0;
	int Similar = 0;
	do {
		if (Word[Index] == '\0' && fearst[Index] != '\0')
		{
			Similar = 0;
			break;
		}
		if (Word[Index] != '\0' && fearst[Index] == '\0')
		{
			Similar = 0;
			break;
		}
		if (Word[Index] == fearst[Index])
		{
			if (Word[Index] == '\0')
				break;
			Similar = 1;
			Index++;
		}
		else
		{
			Similar = 0;
			break;
		}

	} while (Index < (128 - 1));
	Index = 0;
	if (Similar == 1)
	{
		while (Index < (128 - 1) && seakond[Index] != '\0')
		{
			Word[Index] = seakond[Index];
			Word[Index + 1] = '\0';
			Index++;
		}
	}
	return Similar;
}

void CheckList(char* word)
{
	char fearst[128];
	char sekond[128];
	int found = 0;

	FILE* SynonymsList = fopen(Vocabulary, "rt");
	if (!SynonymsList)
	{
		printf("\nError,couldn't open %s", Vocabulary);
		_getch();
		return;
	}
	rewind(SynonymsList);
	while (!feof(SynonymsList) && found == 0)
	{
		fscanf(SynonymsList, "%s %s\n", fearst, sekond);
		found = CompareAndChange(word, fearst, sekond);
	}
	fclose(SynonymsList);

}

void AddToFile(char* word)
{
	FILE* DestinationFile = fopen(Result, "at");
	if (!DestinationFile)
	{
		printf("\n Error Couldn't open %s", Result);
		_getch();
		return;
	}
	fprintf(DestinationFile, " %s ", word);
	fclose(DestinationFile);

}

void ReadAWord(char* word)
{
	char NextChar = '\0';
	int WordIndex = 0;
	FILE* OriginFile = fopen("first.txt", "rt");
	if (!OriginFile)
	{
		printf("\n Error Couldn't open %s", FirstFile);
		_getch();
		return;
	}


	while (!feof(OriginFile))
	{
		fscanf(OriginFile, "%s", word);
		CheckList(word);
		AddToFile(word);
	}

	fclose(OriginFile);
	return;

}

int main()
{

	char Word[256];
	fclose(fopen("result.txt", "wt"));
	ReadAWord(Word);

	return 0;
}