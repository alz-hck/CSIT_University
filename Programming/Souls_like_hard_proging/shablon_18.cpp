#include <iostream>
#include <type_traits>
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

// Функция для проверки четности элемента
bool isEven(int value) {
    return value % 2 == 0;
}

// Функция для проверки четности элемента для double
bool isEven(double value) {
    return static_cast<int>(value) % 2 == 0;
}

// Функция для проверки четности элемента для char
bool isEven(char value) {
    return int(value) % 2 == 0;
}

// Функция для замены столбцов, содержащих только четные элементы
template <typename T>
void rcoll(T **arr, int n, int m, const T &replacement) {
    for (int j = 0; j < m; j++) {
        bool allEven = true; // флаг для проверки, все ли элементы четные в столбце
        for (int i = 0; i < n; i++) {
            if (!isEven(arr[i][j])) { // проверяем четность
                allEven = false; // устанавливаем флаг в false
                break; // выходим из внутреннего цикла
            }
        }
        // Если все элементы в столбце четные, заменяем столбец
        if (allEven) {
            for (int i = 0; i < n; i++) {
                arr[i][j] = replacement; // замена столбца на значение replacement
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

// Основная функция
int main() {
    int n, m;
    cout << "Введите количество строк (n): "; cin >> n; // вводим количество строк
    cout << "Введите количество столбцов (m): "; cin >> m; // вводим количество столбцов

    // Работа с массивом типа int
    cout << "Работа с массивом int:\n";
    int **arrInt = create<int>(n, m);
    
    // Ввод значения замены
    int rVal;
    cout << "Введите значение замены (X): ";
    cin >> rVal; // считывание значения замены

    rcoll(arrInt, n, m, rVal);
    cout << "Результат после замены:\n";
    printmas(arrInt, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] arrInt[i];
    }
    delete[] arrInt;

    // Работа с массивом типа double
    cout << "\nРабота с массивом double:\n";
    double **arrDouble = create<double>(n, m);
    
    // Ввод значения замены
    double rValDouble;
    cout << "Введите значение замены (X): ";
    cin >> rValDouble; // считывание значения замены

    rcoll(arrDouble, n, m, rValDouble);
    cout << "Результат после замены:\n";
    printmas(arrDouble, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] arrDouble[i];
    }
    delete[] arrDouble;

    // Работа с массивом типа char
    cout << "\nРабота с массивом char:\n";
    char **arrChar = create<char>(n, m);
    
    // Ввод значения замены
    char rValChar;
    cout << "Введите значение замены (X): ";
    cin >> rValChar; // считывание значения замены

    rcoll(arrChar, n, m, rValChar);
    cout << "Результат после замены:\n";
    printmas(arrChar, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] arrChar[i];
    }
    delete[] arrChar;

    return 0;
}
