#pragma once

/**
 * @brief функция по вводу матрицы
 * @param k матрица коэффициентов
 * @param s столбец свободных членов
 * @param size количество неизвестных
*/
void read_slay(double** k, double* s, int size);

/**
 * @brief функция заменяет в матрице один столбец на другой
 * @param matrix матрица в которой заменяем столбец
 * @param rows количество строк в матрице
 * @param new_cols номер столбца который заменяем
 * @param new_colmn новый столбец
*/
void replace_col(double** matrix, int rows, int new_cols, double* new_column);

/**
 * @brief функция, которая решает СЛАУ методом Крамера
 * @param k матрица коэффициентов
 * @param s столбец свободных членов
 * @param size количество неизвестных
*/
void cramer(double** k, double* s, int size);

