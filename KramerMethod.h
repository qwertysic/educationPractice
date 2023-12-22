#pragma once

/**
 * @brief ������� �� ����� �������
 * @param k ������� �������������
 * @param s ������� ��������� ������
 * @param size ���������� �����������
*/
void read_slay(double** k, double* s, int size);

/**
 * @brief ������� �������� � ������� ���� ������� �� ������
 * @param matrix ������� � ������� �������� �������
 * @param rows ���������� ����� � �������
 * @param new_cols ����� ������� ������� ��������
 * @param new_colmn ����� �������
*/
void replace_col(double** matrix, int rows, int new_cols, double* new_column);

/**
 * @brief �������, ������� ������ ���� ������� �������
 * @param k ������� �������������
 * @param s ������� ��������� ������
 * @param size ���������� �����������
*/
void cramer(double** k, double* s, int size);

