#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

bool hasAll(const string& w, const set<char>& l) {
    for (char c : l) {
        if (w.find(c) == string::npos) {
            return false; // Если буква не найдена, возвращаем false
        }
    }
    return true; // Все буквы найдены
}

int main() {
    string t; // целевое слово
    getline(cin, t); // вводим слово для проверки

    set<char> l(t.begin(), t.end()); // создаем множество букв

    string in; // входная строка
    getline(cin, in); // вводим строку с текстом

    stringstream ss(in);
    string w;
    string res; // результат

    while (ss >> w) {
        if (!hasAll(w, l)) {
            res += w + " "; // добавляем слово, если не содержит все буквы
        }
    }

    cout << res << endl; // выводим результат
    return 0;
}

// Пример ввода:
// apple
// I have an apple and a banana.
// Вывод:
// I have an and a banana. 
