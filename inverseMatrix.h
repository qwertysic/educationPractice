#pragma once
/**
 * @brief ���� �������
 * @param matrix ������� � ������� ������
 * @param row ���������� ����� � �������
 * @param cols ���������� �������� � �������
*/
void read_matrix(double** matrix, int rows, int cols);

/**
 * @brief ����� ������� 
 * @param matrix ��������� �������
 * @param row ���������� ����� � �������
 * @param cols ���������� �������� � �������
*/
void print_matrix(double** matrix, int rows, int cols);

/**
* @brief ������� ���������� �������
* @param matrix ������� ������� ��������
* @param rows ���������� ����� � ���������� �������
* @param cols ���������� �������� � ���������� �������
* @return ������������� �������
*/
double** copy_matrix(double** matrix, int rows, int cols);

/**
* @brief ������� �������� ������� ��� ������ � �������
* @param matrix ������� � ������� ������ ������� ������
* @param row_1 ������ ������
* @param row_2 ������ ������
* @param size ������ �������
*/
void swap_row(double** matrix, int row_1, int row_2, int size);

/**
* @brief ������� ���������� �� ����� ������ ������� ������
* @param matrix �������
* @param row_1 ������ ������� ��������
* @param row_2 ������ �� ������� ��������
* @param size ������ �������
* @param a ����� �� ������� �������� ���������� ������
*/
void subtract_row(double** matrix, int row_1, int row_2, int size, double a);

/**
* @brief ������� ����������� ������������ �������
* @param matrix �������, ������������� ������� �������
* @param size ������ �������
* @return ������������ �������
*/
double determinant(double** matrix, double size);

/**
 * @brief ������� ��������������� �������
 * @param matrix ��������������� �������
 * @param rows ���������� ����� � �������������� �������
 * @param cols ���������� ������� � � �������������� �������
 * @return ����������������� �������
*/
double** transpose_matrix(double** matrix, int rows, int cols);

/**
 * @brief ������� ������� ����� ������ ������� ������� �� �����
 * @param matrix ������� �������� ������� �����
 * @param rows ���������� ����� � �������
 * @param cols ���������� ������� � �������
 * @param num ����� �� ������� ����� �������� �������
*/
void div_matrix(double** matrix, int rows, int cols, double num);

/**
 * @brief ������� ������� ������� ����� � ����� n m
 * @param matrix ������� � ������� ��������� �����
 * @param rows ���������� ����� � �������
 * @param cols ���������� �������� � �������
 * @param n ����� ������ � ������� ���� �����
 * @param m ����� ������� � ������� ���� �����
 * @return �����
*/
double** minor(double** matrix, int rows, int cols, int n, int m);

/**
 * @brief ������� �� ���������� �������������� ����������
 * @param matrix ������� � ������� ��������� �������������� ����������
 * @param rows ���������� ����� � �������
 * @param cols ���������� �������� � �������
 * @return �������������� ����������
*/
double** alg_comp(double** matrix, int rows, int cols);

/**
 * @brief ������� ����������� �������� ������
 * @param matrix ������� � ������� ������� ��������
 * @param rows ���������� ����� � �������
 * @param cols ���������� �������� � �������
 * @return �������� �������
*/
double** reverse_matrix(double** matrix, int rows, int cols);

