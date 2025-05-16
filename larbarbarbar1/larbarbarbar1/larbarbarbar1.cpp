#include <iostream>     
#include <string>       
#include <vector>       
#include <set>          
#include <sstream>      
#include <cctype>       
#include <locale.h>     

using namespace std;    

bool isValid(char c, int pos) {
    if (pos % 4 == 0) return isalpha(c); 
    if (pos % 4 == 1) return isdigit(c); 
    if (pos % 4 == 2) return isdigit(c); 
    if (pos % 4 == 3) return isdigit(c) && (c) % 2 == 0; 
    return false;
}

vector<char> parse(string line) {
    vector<char> elems; 
    stringstream ss(line);
    char c; 
    while (ss >> c) { 
        elems.push_back(c); 
    }
    return elems; 
}
// проверка для гита
set<char> makeSet(vector<char> v) {
    set<char> s; 
    for (int i = 0; i < v.size(); i++) { 
        if (isValid(v[i], i)) { 
            s.insert(v[i]); 
        }
    }
    return s; 
}

void printSet(set<char> s) {
    if (s.empty()) { 
        cout << "{}"; 
        return; 
    }
    cout << "{"; 
    for (char c : s) { 
        cout << " " << c; 
    }
    cout << " }"; 
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    cout << "Введите элементы множества A через пробел: ";
    string aLine;
    getline(cin, aLine);

    cout << "Введите элементы множества B через пробел: ";
    string bLine;
    getline(cin, bLine);

    vector<char> aVec = parse(aLine);
    vector<char> bVec = parse(bLine);

    bool valid = true;

    for (int i = 0; i < aVec.size(); i++) {
        if (!isValid(aVec[i], i)) valid = false;
    }

    for (int i = 0; i < bVec.size(); i++) {
        if (!isValid(bVec[i], i)) valid = false;
    }

    if (!valid) {
        cout << "Ошибка! Элементы не соответствуют шаблону bcci.\n";
        return 0;
    }

    set<char> aSet = makeSet(aVec);
    set<char> bSet = makeSet(bVec);

    set<char> uni, inter, diffAB, diffBA, symm;

    uni = aSet;
    for (char c : bSet) uni.insert(c);

    for (char c : aSet) {
        if (bSet.count(c)) inter.insert(c);
    }

    for (char c : aSet) {
        if (!bSet.count(c)) diffAB.insert(c);
    }

    for (char c : bSet) {
        if (!aSet.count(c)) diffBA.insert(c);
    }

    for (char c : uni) {
        if (!(aSet.count(c) && bSet.count(c))) symm.insert(c);
    }

    cout << "\nРезультаты:\n";
    cout << "Объединение: "; printSet(uni); cout << endl;
    cout << "Пересечение: "; printSet(inter); cout << endl;
    cout << "A \\ B: "; printSet(diffAB); cout << endl;
    cout << "B \\ A: "; printSet(diffBA); cout << endl;
    cout << "Симметрическая разность: "; printSet(symm); cout << endl;

    return 0;
}