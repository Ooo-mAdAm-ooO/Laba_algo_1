#include "matrix_utils.h"
#include <random>

int** init_matrix(int rows, int cols, int* sum_cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    for (int j = 0; j < cols; j++)
        sum_cols[j] = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 49);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = dist(gen);
            sum_cols[j] += matrix[i][j];
        }
    return matrix;
}

void show_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void show_col_sums(int* sum_cols, int cols) {
    std::cout << "Суммы столбцов:\n";
    for (int j = 0; j < cols; j++)
        std::cout << "Столбец " << j + 1 << ": " << sum_cols[j] << "\n";
}
