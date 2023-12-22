#pragma once
/**
 * @brief ввод матрицы
 * @param matrix матрица в которую вводим
 * @param row количество строк в матрицу
 * @param cols количество столбцов в матрицу
*/
void read_matrix(double** matrix, int rows, int cols);

/**
 * @brief вывод матрицы 
 * @param matrix выводимая матрица
 * @param row количество строк в матрицу
 * @param cols количество столбцов в матрицу
*/
void print_matrix(double** matrix, int rows, int cols);

/**
* @brief функция копировния матрицы
* @param matrix матрица которую копируем
* @param rows количество строк в копируемой матрице
* @param cols количество столбцов в копируемой матрице
* @return скопированная матрица
*/
double** copy_matrix(double** matrix, int rows, int cols);

/**
* @brief функция меняющая местами две строки в матрице
* @param matrix матрица в которой меняем местами строки
* @param row_1 первая строка
* @param row_2 вторая строка
* @param size размер матрицы
*/
void swap_row(double** matrix, int row_1, int row_2, int size);

/**
* @brief функция вычитающая из одной строки матрицы другую
* @param matrix матрица
* @param row_1 строка которую вычитаем
* @param row_2 строка из которой вычитаем
* @param size размер матрицы
* @param a число на которое умножаем вычитаемую строку
*/
void subtract_row(double** matrix, int row_1, int row_2, int size, double a);

/**
* @brief функция вычисляющая определитель матрицы
* @param matrix матрица, определеитель которой считаем
* @param size размер матрицы
* @return определитель матрицы
*/
double determinant(double** matrix, double size);

/**
 * @brief функция транспонирующая матрицу
 * @param matrix транспонируемая матрица
 * @param rows количество строк в транспнируемой матрице
 * @param cols количество стобцов в в транспнируемой матрице
 * @return транспонированная матрица
*/
double** transpose_matrix(double** matrix, int rows, int cols);

/**
 * @brief функция которая делит каждый элемент матрицы на число
 * @param matrix матрица элементы которой делим
 * @param rows количество строк в матрице
 * @param cols количество стобцов в матрице
 * @param num число на которое делим элементы матрицы
*/
void div_matrix(double** matrix, int rows, int cols, double num);

/**
 * @brief функция которая находит минор к месту n m
 * @param matrix матрица в которой вычисляем минор
 * @param rows количество строк в матрице
 * @param cols количество столбцов в матрице
 * @param n номер строки к которой берём минор
 * @param m номер столбца к которой берём минор
 * @return минор
*/
double** minor(double** matrix, int rows, int cols, int n, int m);

/**
 * @brief функция по вычислению алгебраических дополнений
 * @param matrix матрица в которой вычисляем алгебраические дополнения
 * @param rows количество строк в матрице
 * @param cols количество столбцов в матрице
 * @return алгебраические дополнений
*/
double** alg_comp(double** matrix, int rows, int cols);

/**
 * @brief функция вычисляющая обратную марицу
 * @param matrix матрица к которой находим обратную
 * @param rows количество строк в матрице
 * @param cols количество столбцов в матрице
 * @return обратная матрица
*/
double** reverse_matrix(double** matrix, int rows, int cols);


