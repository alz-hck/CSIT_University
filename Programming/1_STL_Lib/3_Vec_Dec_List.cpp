#include <iostream>
#include <vector>
#include <numeric> 
#include <functional> 
using namespace std;

int main() {
    int n;
    cout << "Введите размер списков: ";
    cin >> n;

    vector<int> list1(n);
    vector<int> list2(n);

    //Ввод элементов первого списка
    cout << "Введите элементы первого списка: \n";
    for (int i = 0; i < n; ++i) {
        cin >> list1[i];
    }

    //Ввод элементов второго списка
    cout << "Введите элементы второго списка: \n";
    for (int i = 0; i < n; ++i) {
        cin >> list2[i];
    }

    //Подсчет количества совпадающих элементов
    int count = inner_product(list1.begin(), list1.end(), list2.begin(), 0, plus<int>(), bind(equal_to<int>(), placeholders::_1, placeholders::_2));

    cout << "Количество попарно совпадающих элементов: " << count << endl;

    return 0;
}
