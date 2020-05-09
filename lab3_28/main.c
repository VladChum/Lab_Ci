#include <stdio.h>
#include <stdlib.h>

int KolNull(int m, int n)
{
    int i = 1;
    int kol_null = 0;
    while (i < n)
    {
        if (i < m)
        {
            kol_null += i;
        }
        else
        {
            kol_null += m;
        }
        i++;
    }

    return kol_null;
}

int KolNullInColumn(int j, int** arr, int n)
{
    int kol = 0;
    int i;
    for (i = 0; i < n; ++i)
        if (arr[i][j] == 0) ++kol;
    return kol;
}

int KolNullInLine(int i, int** arr, int m)
{
    int kol = 0;
    int j;
    for (j = 0; j < m; j++)
        if (arr[i][j] == 0) ++kol;
    return kol;
}

void Shov(int** arr, int n, int m)
{
    int j;
    int i;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

}

void main(void)
{
    int n = 0;
    int m = 0;
    while (n <= 1 && m <= 1)
    {
        printf("Enter size of array n*m: \nn = ");
        rewind(stdin);
        scanf("%i", &n);
        printf("m = ");
        rewind(stdin);
        scanf("%i", &m);
    }

    int max_line;
    int max_column;
    if (m >= n)
    {
        max_line = n - 1;
        max_column = n - 1;
    }
    else
    {
        max_line = m;
        max_column = n - 1;
    }

    int i;
    int** arr = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; ++i)
    {
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    while (1)
    {
        printf("\nEnter array\n");
        //Вводим массив
        int j;
        rewind(stdin);
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
            {
                scanf("%i", &arr[i][j]);
            }

        //счётчик нулей в массиве
        int kol_null = 0;
        kol_null = KolNull(m, n);		//колличество нулей которое необходимо
        int kol_nul_in_mass = 0;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                if (arr[i][j] == 0) kol_nul_in_mass++;
            }
        }

        if (kol_nul_in_mass != kol_null || kol_null == 0)
        {
            printf("Error !!!  This matrixis not restored");
            continue;
        }

        for (j = 0; j < m; j++)
        {
            int kol_column;
            kol_column = KolNullInColumn(j, arr, n);
            if ((j != (max_column - kol_column)) && kol_column != 0)
            {
                for (i = 0; i < n; ++i)
                {
                    int dp;
                    dp = arr[i][max_column - kol_column];
                    arr[i][max_column - kol_column] = arr[i][j];
                    arr[i][j] = dp;
                }
                j = -1;
            }
        }

        for (i = 0; i < n; i++)
        {
            int kol_line = 0;
            kol_line = KolNullInLine(i, arr, m);
            if (kol_line != i && kol_line != max_line )
            {
                for (j = 0; j < m; ++j)
                {
                    int dp;
                    dp = arr[kol_line][j];
                    arr[kol_line][j] = arr[i][j];
                    arr[i][j] = dp;
                }
                i = -1;
            }
        }
        break;
    }


    Shov(arr, n, m);

    for (i = 0; i < n; ++i)
    {
        free(arr[i]);
    }
    free(arr);
}