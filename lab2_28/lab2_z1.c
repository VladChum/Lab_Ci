#include <stdio.h>

int input()
{
	int maks;
	do
	{
		scanf_s("%i", &maks);
		rewind(stdin);
		if (maks >= 0 && maks <= 100)
		{
			break;
		}
		else
		{
			printf("please retype : ");
		}

	} while (1);
	
	return maks;
}

float input_certificat()
{
	 float maks;
	do
	{
		scanf_s("%f", &maks);
		rewind(stdin);
		if (maks >= 0 && maks <= 10)
		{
			break;
		}
		else
		{
			printf("please retype : ");
		}

	} while (1);

	return maks;
}


void passes(int sum, int fke, int fitm, int fksis, int fre, int fi)
{
	if (sum >= fke || sum >= fitm || sum >= fksis || sum >= fre || sum >= fi)
	{
		printf("You pass on : \n");
		if (sum >= fke)
		{
			printf("FKE\n");
		}
		if (sum >= fitm)
		{
			printf("FITM\n");
		}
		if (sum >= fksis)
		{
			printf("FKSIS\n");
		}
		if (sum >= fre)
		{
			printf("FRE\n");
		}
		if (sum >= fi)
		{
			printf("FI\n");
		}
	}
	else
	{
		printf("do not waste time go to another university");
	}
}

int main()
{
	int math;
	int fiz;
	int leng;
	float at;
	char pauz = 'y';

	while (pauz == 'y')
	{

		printf("enter maks for math : ");
		math = input();

		printf("enter maks for fiz : ");
		fiz = input();

		printf("enter maks for leng : ");
		leng = input();

		printf("enter maks for atestat : ");
		at = input_certificat();

		int ball_fke = 323;
		int ball_fitm = 319;
		int ball_fksis = 335;
		int ball_fre = 253;
		int ball_fi = 309;

		printf("\nPassing ball on FKE : %i", ball_fke);
		printf("\nPassing ball on FITM : %i", ball_fitm);
		printf("\nPassing ball on FKSIS : %i", ball_fksis);
		printf("\nPassing ball on FRE : %i", ball_fre);
		printf("\nPassing ball on FI : %i\n", ball_fi);

		int sum = 0;
		sum = math + fiz + leng + at * 10;

		printf("\nsum your ball : %d\n", sum);

		if ((leng > (math + 20)) || (leng > (fiz + 20)))
		{
			printf("\nrecommend entering humanitarium universati");
		}
		else
		{
			passes(sum, ball_fke, ball_fitm, ball_fksis, ball_fre, ball_fi);
		}

		printf("\n\nIf yoy vont restart enter \"y\" else enter other : ");

		scanf_s("%c", &pauz);
		rewind(stdin);

	}

	return 0;
}