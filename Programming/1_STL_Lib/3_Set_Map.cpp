#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//Функция для разделения текста
vector<string> splitSent(const string& text) {
    vector<string> s;
    string t;
    for (char c : text) {
        t += c;
        if (c == '.' || c == '?' || c == '!') {
            s.push_back(t);
            t.clear();
        }
    }
    return s;
}

//Функция для разделения предложения на слова
set<string> splitWords(const string& sentence) {
    set<string> w;
    string word;
    for (char c : sentence) {
        if (isalpha(c)) {
            word += tolower(c); 
        } else if (!word.empty()) {
            w.insert(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        w.insert(word);
    }
    return w;
}

int main() {
    string text = "How are you world? I am fine world. What about you world? Fine, thanks world.";

    //Разделение текста на предложения
    vector<string> s = splitSent(text);

    //Разделения на повествовательные и вопросительные предложения
    set<string> nWords; //Повествовательные
    set<string> qWords; //Вопросительные

    //Классифицируем предложения и собираем слова
    for (const string& t : s) {
        if (!t.empty()) {
            char last = t.back();
            set<string> w = splitWords(t);
            if (last == '.') {
                nWords.insert(w.begin(), w.end());
            } else if (last == '?') {
                qWords.insert(w.begin(), w.end());
            }
        }
    }

    //Нахождение общих слов
    set<string> common;
    for (const string& word : nWords) {
        if (qWords.count(word)) {
            common.insert(word);
        }
    }

    //Вывод
    cout << "Слова, которые есть и в повествовательных, и в вопросительных предложениях:\n";
    for (const string& word : common) {
        cout << word << "\n";
    }

    return 0;
}