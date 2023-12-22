#include <stdio.h>
#include <stdlib.h>

#include "inverseMatrix.h"
#include "KramerMethod.h"

void read_matrix(double** matrix, int rows, int cols)
{
    printf("Введите элементы строки матрицы через пробел:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf_s("%lf", &matrix[i][j]);
        }
    }
    printf("\n");
}

void print_matrix(double** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%4.3lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double** copy_matrix(double** matrix, int rows, int cols)
{
    double** m = malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; i++)
    {
        m[i] = malloc(cols * sizeof(double));

        for (int j = 0; j < cols; j++)
        {
            m[i][j] = matrix[i][j];
        }
    }

    return m;
}

void swap_row(double** matrix, int row_1, int row_2, int size)
{
    for (int i = 0; i < size; i++)
    {
        double c = matrix[row_1][i];

        matrix[row_1][i] = matrix[row_2][i];
        matrix[row_2][i] = c;
    }
}

void subtract_row(double** matrix, int row_1, int row_2, int size, double a)
{
    for (int i = 0; i < size; i++)
    {
        matrix[row_2][i] -=  matrix[row_1][i] * a;
    }
}

double determinant(double** matrix, double size)
{
    double res = 0;

    if (size == 1) 
    {
        return matrix[0][0];
    }

    else if (size == 2) 
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    else
    {
        double** copy = malloc((size - 1) * sizeof(double*));

        for (int i = 0; i < size - 1; i++)
        {
            copy[i] = malloc((size - 1) * sizeof(double));
        }

        int sign = 1;

        for (int k = 0; k < size; k++) 
        {
            int ii = 0;

            for (int i = 1; i < size; i++) 
            {
                int jj = 0;

                for (int j = 0; j < size; j++) 
                {
                    if (j == k) 
                    {
                        continue;
                    }

                    copy[ii][jj] = matrix[i][j];

                    jj++;
                }

                ii++;
            }

            res += sign * matrix[0][k] * determinant(copy, size - 1);

            sign = -sign;
        }

    }

    return res;
}

double** transpose_matrix(double** matrix, int rows, int cols)
{
    double** res = malloc(cols * sizeof(double*));

    for (int i = 0; i < cols; i++)
    {
        res[i] = malloc(rows * sizeof(double));

        for (int j = 0; j < rows; j++)
        {
            res[i][j] = matrix[j][i];
        }
    }

    return res;
}

void div_matrix(double** matrix, int rows, int cols, double num)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] /= num;
        }
    }
}

double** minor(double** matrix, int rows, int cols, int n, int m)
{
    int z = 0;
    int y = 0;

    double** res = malloc(rows * sizeof(double*));
    if (!res)
        return 1;

    for (int i = 0; i < rows; i++)
    {
        res[i] = malloc(cols * sizeof(double));
        if (!res[i])
            return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != n && j != m)
            {
                res[z][y] = matrix[i][j];

                y++;

                if (y == rows - 1)
                {
                    y = 0;

                    z++;
                }
            }
        }
    }

    return res;
}

double** alg_comp(double** matrix, int rows, int cols)
{
    double** alg = malloc(rows * sizeof(double*)); 

    if (!alg)
        return 1;

    for (int i = 0; i < rows; i++)
    {
        alg[i] = malloc(cols * sizeof(double*));

        if (!alg[i])
            return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double** minr = minor(matrix, rows, cols, i, j);

            int sign = 1;

            if ((i + j) % 2 != 0)
            {
                sign = -1;
            }

            alg[i][j] = sign * determinant(minr, rows - 1);

            for (int p = 0; p < rows - 1; p++)
            {
                free(minr[p]);
            }
            free(minr);
        }
    }
    return alg;
}

double** reverse_matrix(double** matrix, int rows, int cols)
{
    double** cop = copy_matrix(matrix, rows, cols);

    double d = determinant(cop, rows);


    if (d == 0)
    {
        printf("Опредедитель матрицы равен нулю.\n");
        printf("Обратной матрицы не существует.\n");

        exit(1);
    }

    double** alg = alg_comp(matrix, rows, cols);

    double** res = transpose_matrix(alg, rows, cols);

    div_matrix(res, rows, cols, d);

    return res;
}