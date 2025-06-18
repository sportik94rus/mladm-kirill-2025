#include <iostream>
#include <climits>
#include <locale.h>
using namespace std;

const int MAX = 26;

int graph[MAX][MAX];
char vertexNames[MAX];
int vertexCount = 0;

int getIndexByName(char name) {
    for (int i = 0; i < vertexCount; i++) {
        if (vertexNames[i] == name) return i;
    }
    vertexNames[vertexCount] = name;
    return vertexCount++;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество рёбер: ";
    cin >> n;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = -1;
        }
    }

    cout << "Введите рёбра (буква1 буква2 вес):\n";
    for (int i = 0; i < n; i++) {
        char a, b;
        int weight;
        cin >> a >> b >> weight;
        int ia = getIndexByName(a);
        int ib = getIndexByName(b);
        graph[ia][ib] = weight;
        graph[ib][ia] = weight;
    }

    char startChar, endChar;
    cout << "Введите начальную вершину (буква): ";
    cin >> startChar;
    cout << "Введите конечную вершину (буква): ";
    cin >> endChar;

    int start = getIndexByName(startChar);
    int end = getIndexByName(endChar);

    int dist[MAX];
    bool visited[MAX];
    int prev[MAX];

    for (int i = 0; i < MAX; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < vertexCount; i++) {
        int u = -1;
        int minDist = INT_MAX;

        for (int j = 0; j < vertexCount; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < vertexCount; v++) {
            if (graph[u][v] != -1 && !visited[v]) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    prev[v] = u;
                }
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "Путь между " << startChar << " и " << endChar << " не найден.\n";
    }
    else {
        cout << "Кратчайший путь: ";
        char path[MAX];
        int pathLen = 0;
        int curr = end;

        while (curr != -1) {
            path[pathLen++] = vertexNames[curr];
            curr = prev[curr];
        }

        for (int i = pathLen - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " -> ";
        }

        cout << "\nСуммарный вес пути: " << dist[end] << endl;
    }

    return 0;
}
