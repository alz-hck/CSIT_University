#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "n = "; cin >> n;
    vector<int> v;

    //Заполнение вектора
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    cout << "Элементы вектора:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    set<int> d2; // Двухзначные цифры
    set<int> d3; // Трёх значные цифры

    //Цикл для нахождения всех цифр в двухзначных и трёхзначных числах
    for (int x : v) {
        if (x >= 10 && x <= 99) { //Двузнычные 
            d2.insert(x / 10); 
            d2.insert(x % 10); 
        } else if (x >= 100 && x <= 999) { //Трехзначные 
            d3.insert(x / 100); 
            d3.insert((x / 10) % 10); 
            d3.insert(x % 10); 
        }
    }

    //Нахождение общих пересечений чисел
    set<int> res;
    for (int d : d2) {
        if (d3.count(d)) res.insert(d);
    }

    //Вывод 
    cout << "Цифры, встречающиеся в двузначных и в трехзначных числах:\n";
    for (int d : res) cout << d << " ";
    cout << "\n";

    return 0;
}