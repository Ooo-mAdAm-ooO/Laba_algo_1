#include <iostream>
#include <locale>
#include <Windows.h>
#include "array_utils.h"
#include "matrix_utils.h"
#include "student_utils.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1215);
    std::setlocale(LC_ALL, "Russian");
    StudentDatabase db;
    int choice;

    do {
        std::cout << "\nВыберите задание:\n"
            << "1 - Разница между макс. и мин. элементами массива\n"
            << "2 - Инициализация массива случайными числами\n"
            << "3 - Создание массива произвольного размера\n"
            << "4 - Сумма значений по столбцам двумерного массива\n"
            << "5 - Работа со студентами\n"
            << "0 - Выход\n\n"
            << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int size = size_arr();
            int* arr = init_arr(size);
            show_arr(arr, size);
            std::cout << "Разница: " << maxDiff_arr(arr, size) << "\n";
            delete[] arr;
            break;
        }
        case 2: {
            int size = 10;
            int* arr = init_arr(size);
            show_arr(arr, size);
            delete[] arr;
            break;
        }
        case 3: {
            int size = size_arr();
            int* arr = init_arr(size);
            show_arr(arr, size);
            delete[] arr;
            break;
        }
        case 4: {
            int rows = 4, cols = 4;
            int* sum_cols = new int[cols];
            int** matrix = init_matrix(rows, cols, sum_cols);
            show_matrix(matrix, rows, cols);
            show_col_sums(sum_cols, cols);
            for (int i = 0; i < rows; i++) delete[] matrix[i];
            delete[] matrix;
            delete[] sum_cols;
            break;
        }
        case 5: {
            int subchoice;
            do {
                std::cout << "\n=== МЕНЮ СТУДЕНТОВ ===\n"
                    << "1. Добавить студента\n"
                    << "2. Удалить по ID\n"
                    << "3. Найти по имени\n"
                    << "4. Показать всех\n"
                    << "0. Назад\n\n"
                    << "Ваш выбор: ";
                std::cin >> subchoice;

                switch (subchoice) {
                case 1: {
                    std::string name, lastName;
                    int nomZach;
                    std::cout << "Имя: "; std::cin >> name;
                    std::cout << "Фамилия: "; std::cin >> lastName;
                    std::cout << "Номер зачётки: "; std::cin >> nomZach;
                    db.addStudent(name, lastName, nomZach);
                    break;
                }
                case 2: {
                    db.printStudents();
                    int id;
                    std::cout << "Введите ID: "; std::cin >> id;
                    db.removeStudentById(id);
                    break;
                }
                case 3: {
                    std::string name;
                    std::cout << "Введите имя: "; std::cin >> name;
                    db.findStudentName(name);
                    break;
                }
                case 4:
                    db.printStudents();
                    break;
                case 0:
                    std::cout << "Возврат в главное меню...\n";
                    break;
                default:
                    std::cout << "Неверный выбор!\n";
                }
            } while (subchoice != 0);
            break;
        }
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}