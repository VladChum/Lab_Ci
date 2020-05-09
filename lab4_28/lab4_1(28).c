#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ScanStartWord(char** str, int i, int j, int lengthline)
{
	while (str[i][j] == ' ' && j < lengthline)
	{
		j++;
	}
	return j;
}

int ScanEndWord(char** str, int i, int j, int lenghtline)
{
	while (str[i][j] != ' ' && j < lenghtline)
	{
		j++;
	}
	return j;
}

void Showe(int i, char** str, int startWord, int endWord)
{
	int k = 0;
	for (k = startWord; k < endWord; k++)
		printf("%c", str[i][k]);
	printf(" ");
}



void main()
{
	int n = 0;
	printf("Enter number of lines : ");
	scanf_s("%d", &n);

	if (n < 1)
	{
		while (n < 1)
		{
			printf("\nError, n < 1; Plese repeat enter : ");
			rewind(stdin);
			scanf_s("%d", &n);
		}
	}
	n++;

	int i;
	int j = 0;

	char** str = malloc(n * sizeof(char*));
	for (i = 0; i < n; ++i)
	{
		str[i] = malloc(256 * sizeof(char));
	}

	for (i = 0; i < n; i++)
		fgets(str[i], 256, stdin);

	int** startWord = malloc(n * sizeof(int*));
	for (i = 0; i < n; ++i)
	{
		startWord[i] = malloc(20 * sizeof(int));
	}

	int** endWord = malloc(n * sizeof(int*));
	for (i = 0; i < n; ++i)
	{
		endWord[i] = malloc(20 * sizeof(int));
	}

	int* kolWord = malloc(n * sizeof(int));
	for (i = 1; i <= n; i++)
		kolWord[i] = 0;

	int* lengthline = malloc(n * sizeof(int));
	for (int i = 1; i < n; i++)
	{
		lengthline[i] = 0;
		j = 0;
		while (str[i][j] != '\n')
		{
			lengthline[i]++;
			j++;
		}
		lengthline[i];
	}

	int* maxWordNumber = malloc(n * sizeof(int));
	for (i = 1; i <= n; i++)
		maxWordNumber[i] = 1;

	int* minWordNumber = malloc(n * sizeof(int));
	for (i = 1; i <= n; i++)
		minWordNumber[i] = lengthline[i];


	for (i = 1; i < n; i++)
	{
		if (lengthline[i] <= 0) continue;
		j = 0;

		while (j < lengthline[i] - 1)
		{
			kolWord[i]++;

			j = ScanStartWord(str, i, j, lengthline[i]);
			startWord[i][kolWord[i]] = j;

			if (j >= lengthline[i]) continue;
			j = ScanEndWord(str, i, j, lengthline[i]);
			endWord[i][kolWord[i]] = j;

			if (j - startWord[i][kolWord[i]] > maxWordNumber[i])
			{
				maxWordNumber[i] = kolWord[i];
			}
			else
				if (j - startWord[i][kolWord[i]] < minWordNumber[i])
				{
					minWordNumber[i] = kolWord[i];
				}


			if (j < lengthline[i] - 1)	j++;
		}

	}


	for (i = 1; i < n; i++)
	{
		printf("\n%i  %i  %i", kolWord[i], maxWordNumber[i], minWordNumber[i]);
	}




	for (i = 1; i < n; i++)
	{
		j = 1;
		if (kolWord[i] < 2)
		{
			int k = 0;
			while (str[i][k] != '\n')
			{
				printf("%c", str[i][k]);
				k++;
			}
			continue;
		}
		else
		{
			while (j <= kolWord[i])
			{
				if (j != maxWordNumber[i] && j != minWordNumber[i])
				{
					Showe(i, str, startWord[i][j], endWord[i][j]);
				}
				else
					if (j == maxWordNumber[i])
					{
						Showe(i, str, startWord[i][minWordNumber[i]], endWord[i][minWordNumber[i]]);
					}
					else
						if (j == minWordNumber[i])
						{
							Showe(i, str, startWord[i][maxWordNumber[i]], endWord[i][maxWordNumber[i]]);
						}
				j++;
			}
		}


		printf("\n");

	}

	int maxLenght = endWord[1][1] - startWord[1][1];
	int minLenght = endWord[1][1] - startWord[1][1];
	for (i = 1; i < n; i++)
		for (j = 1; j < kolWord[i]; j++)
		{
			if (endWord[1][1] - startWord[1][1] > maxLenght) maxLenght = endWord[1][1] - startWord[1][1];
			if (endWord[1][1] - startWord[1][1] < minLenght) minLenght = endWord[1][1] - startWord[1][1];
		}

	printf("\nmaxLenght = %d \nminLenght = %d", maxLenght, minLenght);

	for (i = 0; i < n; i++)
		free(str[i]);
	free(str);
	for (i = 1; i < n; i++)
		free(startWord[i]);
	free(startWord);
	for (i = 1; i < n; i++)
		free(endWord[i]);
	free(endWord);
	free(lengthline);
	free(kolWord);
	free(maxWordNumber);
	//free(minWordStart);
	free(minWordNumber);

}