#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функция для создания двумерного массива
template <typename T>
T **create(int n, int m) {
    T **arr = new T *[n]; // выделение памяти для строк
    for (int i = 0; i < n; i++) {
        arr[i] = new T[m]; // выделение памяти для столбцов
    }

    for (int i = 0; i < n; i++) { // ввод массива
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; // считывание значений
        }
    }
    return arr; // возвращаем указатель на массив
}

// Функция для замены строк с минимальным элементом
template <typename T>
void rrow(T **arr, int n, int m, const T *replacement) {
    T minVal = arr[0][0]; // начальное значение минимального элемента

    // Поиск минимального элемента
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j]; // обновляем минимальное значение
            }
        }
    }

    // Замена строк, содержащих минимальный элемент
    for (int i = 0; i < n; i++) {
        bool hasMin = false; // флаг для проверки наличия минимального элемента в строке
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == minVal) {
                hasMin = true; // нашли минимальный элемент в строке
                break; // выходим из внутреннего цикла
            }
        }
        // Если строка содержит минимальный элемент, заменяем ее
        if (hasMin) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = replacement[j]; // замена строки
            }
        }
    }
}

// Функция для вывода массива
template <typename T>
void printmas(T **arr, int n, int m) {
    for (int i = 0; i < n; i++, cout << endl) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " "; // выводим элементы массива
        }
    }
}

int main() {
    int n, m;
    cout << "Введите количество строк (n): "; cin >> n; // вводим количество строк
    cout << "Введите количество столбцов (m): "; cin >> m; // вводим количество столбцов

    // Работа с массивом типа int
    cout << "Работа с массивом int:\n";
    int **arrInt = create<int>(n, m);
    
    // Ввод строки замены
    int *rrowint = new int[m];
    cout << "Введите строку замены (через пробел): ";
    for (int j = 0; j < m; j++) {
        cin >> rrowint[j]; // считывание строки замены
    }

    rrow(arrInt, n, m, rrowint);
    cout << "Результат после замены:\n";
    printmas(arrInt, n, m);


    delete[] arrInt;
    delete[] rrowint;

    // Работа с массивом типа double
    cout << "\nРабота с массивом double:\n";
    double **arrDouble = create<double>(n, m);
    
    // Ввод строки замены
    double *rrowDouble = new double[m];
    cout << "Введите строку замены (через пробел): ";
    for (int j = 0; j < m; j++) {
        cin >> rrowDouble[j]; // считывание строки замены
    }

    rrow(arrDouble, n, m, rrowDouble);
    cout << "Результат после замены:\n";
    printmas(arrDouble, n, m);


    delete[] arrDouble;
    delete[] rrowDouble;

    // Работа с массивом типа char
    cout << "\nРабота с массивом char:\n";
    char **arrChar = create<char>(n, m);
    
    // Ввод строки замены
    char *rrowChar = new char[m];
    cout << "Введите строку замены (через пробел): ";
    for (int j = 0; j < m; j++) {
        cin >> rrowChar[j]; // считывание строки замены
    }

    rrow(arrChar, n, m, rrowChar);
    cout << "Результат после замены:\n";
    printmas(arrChar, n, m);

    delete[] arrChar;
    delete[] rrowChar;

    return 0;
}
