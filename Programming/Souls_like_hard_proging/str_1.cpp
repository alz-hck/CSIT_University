#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    cout << "Введите текст:" << endl;

    // Считываем ввод пользователя
    getline(cin, input);

    int maxEvenNumber = -1; // Инициализируем максимальное четное число минимально возможным значением

    // Используем stringstream для разбивки строки на слова
    stringstream ss(input);
    string word;

    while (ss >> word) { // Считываем каждое слово
        // Проверяем, является ли слово числом
        if (isdigit(word[0]) || (word[0] == '-' && word.size() > 1)) { // Проверяем, что слово начинается с цифры или с '-' (отрицательное число)
            int number = stoi(word); // Преобразуем слово в число
            // Проверяем, является ли число четным
            if (number % 2 == 0) {
                // Сравниваем с текущим максимальным четным числом
                if (number > maxEvenNumber) {
                    maxEvenNumber = number;
                }
            }
        }
    }

    // Проверяем, было ли найдено четное число
    if (maxEvenNumber == -1) {
        cout << "Четные числа не найдены." << endl;
    } else {
        cout << "Максимальное четное число: " << maxEvenNumber << endl;
    }

    return 0;
}
// Примеры
// Lorem ipsum dolor sit 20 amet, consectetur 50 adipiscing elit. Sed do eiusmod tempor 60 incididunt ut labore et dolore 2023 magna aliqua. Ut enim ad 11 minim veniam, quis 22 nostrud exercitation ullamco laboris nisi ut 1000 aliquip ex ea commodo consequat. Duis aute irure dolor in 42 reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
// Я занаю русский язык на 50 баллов ЕГЭ, а кто-то может его знать на 94, или даже 100!