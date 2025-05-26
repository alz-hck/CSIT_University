#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_ATTEMPTS = 6; // Максимальное количество попыток


const string WORDS[] = {
    "algorithm", "encryption", "javascript", "debugging", "framework", "interface", "recursion", "structure", "variable", "blockchain"
};


const string HANGMAN_PICS[] = {
    "   +---+\n   |   |\n       |\n       |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n       |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n   |   |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|   |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|\\  |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|\\  |\n  /    |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n========="
};

int main() { 
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    string word = WORDS[rand() % (sizeof(WORDS) / sizeof(WORDS[0]))]; // Случайное слово
    vector<bool> guessed(word.length(), false); // Угаданные буквы
    int attempts = 0;

    // Массив для отслеживания состояния букв 
    vector<bool> usedLetters(26, false); // true = буква использована

    cout << "Добро пожаловать в игру 'Виселица'!" << endl;

    while (attempts < MAX_ATTEMPTS) {
        //Кол-во попыток
        cout << HANGMAN_PICS[attempts] << endl;

        //Вывод слова, либо чёрточек, если не угадано ещё
        for (size_t i = 0; i < word.length(); ++i) {
            cout << (guessed[i] ? word[i] : '_') << ' ';
        }
        cout << endl;

        //Вывод доступных и использованных букв
        cout << "Доступные буквы: ";
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!usedLetters[c - 'a']) {
                cout << c << ' ';
            }
        }
        cout << endl;

        cout << "Использованные буквы: ";
        for (char c = 'a'; c <= 'z'; ++c) {
            if (usedLetters[c - 'a']) {
                cout << c << ' ';
            }
        }
        cout << endl;

        cout << "Введите букву или слово целиком: ";
        string input;
        cin >> input;

        //Проверка, ввел ли пользователь слово целиком
        if (input.length() > 1) {
            if (input == word) {
                cout << "Поздравляем! Вы угадали слово: " << word << endl;
                return 0;
            } else {
                cout << "Неправильно! Игра окончена." << endl;
                return 0;
            }
        }

        char letter = tolower(input[0]);
        bool found = false;

        //Проверка, есть ли буква в загаданном слове
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == letter) {
                guessed[i] = true;
                found = true;
            }
        }

        //Помечаем букву как использованную
        usedLetters[letter - 'a'] = true;

        if (!found) {
            attempts++;
            cout << "Неправильно! У вас осталось попыток: " << MAX_ATTEMPTS - attempts << endl;
        }

        //Проверка на выигрыш
        bool won = true;
        for (bool g : guessed) {
            if (!g) {
                won = false;
                break;
            }
        }

        if (won) {
            cout << "Поздравляем! Вы угадали слово: " << word << endl;
            return 0;
        }
    }

    //Отображение финального состояния виселицы
    cout << HANGMAN_PICS[attempts] << endl;
    cout << "Игра окончена! Загаданное слово было: " << word << endl;
    return 0;
}