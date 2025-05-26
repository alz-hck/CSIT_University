#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, a;
    cout << "n = "; cin >> n;
    vector<int> vec; // Создание вектора vec 

    // Заполнение вектора
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }
    //Вывод элементов вектора
    cout << "Элементы вектора:\n";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

    cout << "\n";
    a = 0;
    for (int i = 0; i < n; i++) {
        if ( vec[i] >= a ) {
            a = vec[i];
        }
    }
    cout << "Максимальный элемент вектора: " << a << endl;

    //Создание нового вектора без максимального элемента
    vector<int> newVec;
    for (int i = 0; i < vec.size(); i++) {
        int vecc = vec[i];
        if (vecc != a) {
            newVec.push_back(vecc);
        }
    }

    cout << "Вектор без максимального элемента: ";
    for (int i = 0; i < newVec.size(); i++) {
        cout << newVec[i] << " ";
    }
    //Нахождение минимального элемента
    a = INT8_MAX; 
    for (int i = 0; i < newVec.size(); i++) {
        if (a >= newVec[i]) {
            a = newVec[i];
        }
    }
    cout << endl;
    cout << "Минимальный элемент вектора: " << a << endl;

    //Создание новго вектора без минимальных элементов
    vector<int> newVec2;
    for (int i = 0; i < newVec.size(); i++) {
        int veccc = newVec[i];
        if (veccc % 2 != 0) {
            newVec2.push_back(veccc);
        }
        else {
            newVec2.push_back(a);
        }
    }
    cout << "Вектор без минимального элемента: ";
    for (int i = 0; i < newVec2.size(); i++) {
        cout << newVec2[i] << " ";
    }
    cout<< endl;

    //Сортировка нового вектора
    sort(newVec2.begin(), newVec2.end());
    cout << "Вектор без минимального элемента (отсортированный): ";
    for (int i = 0; i < newVec2.size(); i++) {
        cout << newVec2[i] << " ";
    }
    cout << endl;
    newVec2.erase(
        unique(newVec2.begin(), newVec2.end()), newVec2.end());
    cout << "Вектор после всех условий: ";
    for (int i = 0; i < newVec2.size(); i++) {
        cout << newVec2[i] << " ";
    }
    return 0;
}