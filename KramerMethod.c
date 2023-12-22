#include <stdio.h>
#include <stdlib.h>

#include "inverseMatrix.h"
#include "KramerMethod.h"

void read_slay(double** k, double* s, int size)
{
    printf("Введите коэффиценты СЛАУ:\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf_s("%lf", &k[i][j]);
        }
    }

    printf("Введите столбец свободных членов:\n");
    for (int i = 0; i < size; i++)
    {
        printf("B[%d]: ", i + 1);
        scanf_s("%lf", &s[i]);
    }
}

void replace_col(double** matrix, int rows, int new_cols, double* new_column)
{

    for (int i = 0; i < rows; i++)
    {
        matrix[i][new_cols] = new_column[i];
    }
}


void cramer(double** k, double* s, int size)
{
    double** cop = copy_matrix(k, size, size);

    double D = determinant(cop, size);

    if (D == 0)
    {
        printf("Определитель равен нулю, СЛАУ имеет бесконечное количество решений или решений нет.\n");
        exit(1);
    }

    printf("Определитель матрицы коэффициентов равен: %.3lf\n", D);

    double* answer = malloc(size * sizeof(double));

    for (int i = 0; i < size; i++)
    {
        double** km = copy_matrix(k, size, size);
        replace_col(km, size, i, s);
        printf("Дельта %d:\n", i + 1);
        print_matrix(km, size, size);

        double d = determinant(km, size);
        printf("Определитель дельта %d = %.3lf\n", i + 1, d);
        printf("\n");

        answer[i] = d / D;
    }

    printf("Решение СЛАУ:\n");

    for (int i = 0; i < size; i++)
    {
        printf("X[%d] = %3.3lf\n", i + 1, answer[i]);
    }
}