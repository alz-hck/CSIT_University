#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;

int main() {
    ifstream input("input.txt"); //Открытие файла

    map<int, int> freq; //Подсчёт частотый чисел "frequency"
    string token;
    
    while (input >> token) { //Ввод и использование слов слов
        bool isNumber = true;
        //Проверяем, состоит ли символ только из цифр
        for (char c : token) {
            if (!(isdigit(c) || (c == '-' && &c == &token[0]))) {
                isNumber = false;
                break;
            }
        }
        
        if (isNumber && !token.empty()) {
            //Преобразуем строку в число
            int num;
            istringstream iss(token);
            if (iss >> num) {
                freq[num]++;
            }
        }
    }

    //Преобразуем мапы в вектор пар для сортировки
    vector<pair<int, int>> vec(freq.begin(), freq.end());

    //Сортировка по убыванию частоты
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    //Запрос и ввод числа
    int k;
    cout << "Введите k: ";
    cin >> k;

    // Вывод
    cout << "Самые частые числа:\n";
    for (int i = 0; i < k && i < vec.size(); ++i) {
        cout << "Число " << vec[i].first << " — " << vec[i].second << " раз\n";
    }

    input.close(); 
    return 0;
}