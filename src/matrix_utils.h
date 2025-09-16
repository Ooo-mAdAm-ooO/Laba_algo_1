#pragma once
#include <iostream>

int** init_matrix(int rows, int cols, int* sum_cols);
void show_matrix(int** matrix, int rows, int cols);
void show_col_sums(int* sum_cols, int cols);
