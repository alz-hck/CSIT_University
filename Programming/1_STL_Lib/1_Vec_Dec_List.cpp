#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, a, count = 0;
    cout << "n = "; cin >> n;
    vector<int> vec; // Создание ветора vec

    // Заполненеие вектора
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }

    // Вывод элементов вектора
    cout << "Элементы вектора:\n";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

    // Цикл поиска максимального элемента вектора
    a = 0;
    for (int i = 0; i < n; i++) {
        if ( vec[i] >= a ) {
            a = vec[i];
        }
    }
    cout << "Максимальный элемент вектора:\n" << a;
    
    // Цикл поиска максимальных элементов в векторе и 
    for (int i = 0; i < n; i++) {
        if ( vec[i] == a ) {
            count++;
        }
    }

    cout << "\n";
    cout << "Кол-во максимальных эементов вектора:\n" << count;
    return 0;
}