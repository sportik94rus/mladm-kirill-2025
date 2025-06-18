#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

const int MAX = 100;

int main() {
    setlocale(LC_ALL, "Russian");

    string domain[MAX];
    string codomain[MAX];
    string from[MAX];
    string to[MAX];
    int domainSize, codomainSize, n;

    cout << "Введите количество элементов в A (первом множестве): ";
    cin >> domainSize;
    cin.ignore();

    cout << "Введите элементы A через пробел:\n";
    for (int i = 0; i < domainSize; i++) {
        cin >> domain[i];
    }
    cin.ignore();

    cout << "Введите количество элементов в B (втором множестве): ";
    cin >> codomainSize;
    cin.ignore();

    cout << "Введите элементы B через пробел:\n";
    for (int i = 0; i < codomainSize; i++) {
        cin >> codomain[i];
    }
    cin.ignore();

    cout << "Введите количество пар (a b): ";
    cin >> n;
    cin.ignore();

    cout << "Введите пары (a b), по одной на строке:\n";
    for (int i = 0; i < n; i++) {
        cin >> from[i] >> to[i];
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < domainSize; j++) {
            if (from[i] == domain[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Ошибка: " << from[i] << " не найден в A.\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < codomainSize; j++) {
            if (to[i] == codomain[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Ошибка: " << to[i] << " не найден в B.\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (from[i] == from[j]) {
                cout << "Ошибка: значение " << from[i] << " встречается более одного раза.\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < domainSize; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (from[j] == domain[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Ошибка: элемент " << domain[i] << " не участвует в паре.\n";
            return 0;
        }
    }

    cout << "Данное отношение ЯВЛЯЕТСЯ функцией.\n";
    return 0;
}