#include <iostream>
#include <locale.h>
using namespace std;

const int MAX = 100;

int main() {
    setlocale(LC_ALL, "Russian");

    int matrix[MAX][MAX];
    int n;

    cout << "Анализ свойств бинарного отношения\n";
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    cout << "Введите элементы матрицы (0 или 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool valid = true;
    bool reflexive = true;
    bool symmetric = true;
    bool antisymmetric = true;
    bool transitive = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                valid = false;
            }
        }
    }

    if (!valid) {
        cout << "Ошибка: в матрице есть элементы, отличные от 0 и 1.\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] != 1) {
            reflexive = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                antisymmetric = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                        transitive = false;
                    }
                }
            }
        }
    }

    cout << "\nСвойства отношения:\n";
    cout << "1. Рефлексивность: ";
    if (reflexive) {
        cout << "Да";
    }
    else {
        cout << "Нет";
    }
    cout << endl;
    cout << "2. Симметричность: ";
    if (symmetric) {
        cout << "Да";
    }
    else {
        cout << "Нет";
    }
    cout << endl;
    cout << "3. Антисимметричность: ";
    if (antisymmetric) {
        cout << "Да";
    }
    else {
        cout << "Нет";
    }
    cout << endl;
    cout << "4. Транзитивность: ";
    if (transitive) {
        cout << "Да";
    }
    else {
        cout << "Нет";
    }
    cout << endl;

    return 0;
}
