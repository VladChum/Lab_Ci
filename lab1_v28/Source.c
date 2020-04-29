#include <stdio.h>
#include <stdlib.h>


int main()
{
	int x1 = 1;
	int x2 = 1;
	int n = 0;
	int kol = 2;

	printf("Enter number of element : ");

	while (n <= 0)
	{

		rewind(stdin);
		scanf_s("%i", &n);
		
		if (n == 1) printf("\n%i element = 1", n);
		else
		if ((n >= 1) && (n < INT_MAX))
		{
			printf("11");

			while (kol < n)
			{
				int time;
				time = x2;
				x2 += x1;
				x1 = time;
				
				
				int kol_element = x2;

				printf("%i", x2);

				while (kol_element > 0)
				{
					kol++;
					kol_element /= 10;
				}

			}

			int i = 0;
			for (i = 0; i < kol - n; ++i)
			{
				x2 /= 10;
			}

			printf("\n%i element = %i", n, x2 % 10);
		}
		else
			printf("Repeat enter: ");
	}

	return 0;
} 
