#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX = 26;
    int n;
    cout << "Введите количество вершин графа: ";
    cin >> n;

    int adjMatrix[MAX][MAX] = { 0 };
    cout << "Введите матрицу смежности размерностью (" << n << "x" << n << "):\n";

    for (int i = 0; i < n; i++) {
        cout << "Строка " << i << ": ";
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                cout << "Ошибка: Матрица должна быть симметричной!\n";
                return 1;
            }
        }
    }

    int reachMatrix[MAX][MAX] = { 0 };

    for (int start = 0; start < n; start++) {

        int queue[MAX] = { 0 };
        int head = 0, tail = 0;
        bool visited[MAX] = { false };

        queue[tail++] = start;
        visited[start] = true;

        while (head < tail) {
            int current = queue[head++];

            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    queue[tail++] = neighbor;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                reachMatrix[start][j] = 1;
            }
            else {
                reachMatrix[start][j] = 0;
            }
        }
    }
    cout << "\nМатрица достижимости:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reachMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
