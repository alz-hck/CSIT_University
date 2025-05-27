#include <iostream>
using namespace std;

// Рекурсивная функция для вычисления полинома Чебышева
int T(int n, int Tn1, int Tn, int x, int targetN) {
    if (n == targetN) return Tn; // Возвращаем значение Tn, если достигли нужного n
    return T(n + 1, Tn, 2 * (2 * x - 1) * Tn - Tn1, x, targetN);
}

int main() {
    int x, n;
    cout << "Введите x и n: "; cin >> x >> n; // Ввод значений x и n

    // Начальные значения T0 и T1
    int T0 = 1; // T0
    int T1 = 2 * x - 1; // T1
    int cnt = 1; // Счетчик для n

    // Вычисление значения с помощью рекурсивной функции
    cout << T(cnt, T0, T1, x, n) << endl;

    // Итеративный способ вычисления
    T0 = 1; // T0
    T1 = 2 * x - 1; // T1
    cnt = 1; // Счетчик для n

    while (cnt < n) {
        int temp = T1; // Временная переменная для хранения Tn
        T1 = 2 * (2 * x - 1) * T0 - temp; // Вычисляем Tn
        T0 = temp; // Обновляем Tn-1
        cnt++;
    }

    cout << T1; // Выводим Tn
    return 0;
}

