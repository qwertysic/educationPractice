#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "inverseMatrix.h"
#include "KramerMethod.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // ������� 1

    /*int row;
    int col;

    printf("������� ���������� ����� � �������� ����� ������:");
    scanf_s("%d %d", &row, &col);

    if (col != row)
    {
        printf("��� ������������ ������� �������� �� ����������.\n");
        exit(1);
    }

    double** matrix = malloc(row * sizeof(double*)); 
    if (!matrix)
        return 1;

    for (int i = 0; i < row; i++)
    {
        matrix[i] = malloc(col * sizeof(double));
        if (!matrix[i])
            return 1;
    }
    read_matrix(matrix, row, col);

    double** answer = reverse_matrix(matrix, row, col); 

    printf("�������� �������:\n");
    print_matrix(answer, row, col);*/

    // ������� 2

    int size;

    printf("������� ���������� ����������� � ����: ");
    scanf_s("%d", &size);

    double** k = malloc(size * sizeof(double*)); 
    if (!k)
       return 1;

    for (int i = 0; i < size; i++)
    {
       k[i] = malloc(size * sizeof(double));
       if (!k[i])
          return 1;
    }

    double* s = malloc(size * sizeof(double)); 
    read_slay(k, s, size); 
    cramer(k, s, size);

    return 0;
}