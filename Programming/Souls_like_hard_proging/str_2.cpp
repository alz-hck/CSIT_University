#include <iostream>
#include <string>
using namespace std;

int main() {
    char c; // символ
    char cc;
    cin.get(c);
    cin.get();

    cc = isupper(c) ? tolower(c) : toupper(c); // переводим регистр

    string str;
    getline(cin, str); // вводим строку
    string punc = " ?!,.:;-"; // знаки препинания
    int wl = 0; // длина слова
    int si = 0; // индекс начала слова
    int lc = 0; // счетчик букв

    for (int i = 0; i < str.size(); i++) {
        if (wl == 0) lc = 0; // обнуление счетчика
        if (punc.find(str[i]) == string::npos) { // не знак препинания
            wl++; // увеличиваем длину
            lc++; // увеличиваем счетчик
        }
        if (punc.find(str[i + 1]) != string::npos) { // если следующий символ - знак препинания
            si = i - wl + 1; // индекс первой буквы
            wl = 0; // обнуление
            if (str[si] == c || str[si] == cc) { 
                str.insert(si + lc, ":");
            }
        }
    }
    cout << str;
    return 0;
}
// Пример:
// Ввод:
// p Privet! Ya Oleg Propanov! Pokupka, avto, podverjeno, karrozii!
// Вывод:
// Privet:! Ya Oleg Propanov:! Pokupka:, avto, podverjeno:, karrozii!