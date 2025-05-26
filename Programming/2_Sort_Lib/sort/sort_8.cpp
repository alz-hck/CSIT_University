#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    string surname;
    string position;
    int day;
    int month;
    int year;
    int experience; 
    double salary; 
};

// Функция для чтения данных из файла
void readEmployeesFromFile(Employee employees[], int &count, const string& filename) {
    ifstream inputFile(filename);
    count = 0;
    while (inputFile >> employees[count].surname >> employees[count].position 
           >> employees[count].day >> employees[count].month >> employees[count].year 
           >> employees[count].experience >> employees[count].salary) {
        count++;
    }
    inputFile.close();
}

// Функция для записи данных в файл
void writeEmployeesToFile(const Employee employees[], int count, const string& filename) {
    ofstream outputFile(filename);

    for (int i = 0; i < count; i++) {
        outputFile << "Фамилия: " << employees[i].surname 
                  << ", Должность: " << employees[i].position 
                  << ", Дата рождения: " << employees[i].day << "." << employees[i].month << "." << employees[i].year 
                  << ", Стаж работы: " << employees[i].experience << " лет" 
                  << ", Зарплата: " << employees[i].salary << " руб." << endl;
    }
    outputFile.close();
}

// Функция для слияния двух частей массива
void merge(Employee employees[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Размер левой части
    int n2 = right - mid;    // Размер правой части

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];
    // Копируем данные в временные массивы
    for (int i = 0; i < n1; i++) {
        L[i] = employees[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = employees[mid + 1 + j];
    }

    // Сливаем временные массивы обратно в employees
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].salary <= R[j].salary) {
            employees[k] = L[i];
            i++;
        } else {
            employees[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        employees[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы из R ( если они есть )
    while (j < n2) {
        employees[k] = R[j];
        j++;
        k++;
    }
}

// Рекурсивная функция для сортировки слиянием
void mergeSort(Employee employees[], int left, int right) {
    if (left >= right) {
        return; // Default: если массив отсортирован
    }

    int mid = left + (right - left) / 2;
    mergeSort(employees, left, mid);     
    mergeSort(employees, mid + 1, right); 
    merge(employees, left, mid, right);  // Слияние обеих частей
}

int main() {
    const int MAX_EMPLOYEES = 20; 
    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    string inputFilename = "input_sort.txt";  
    string outputFilename = "output_sort8.txt"; 

    
    readEmployeesFromFile(employees, count, inputFilename);
    
    mergeSort(employees, 0, count - 1);

    writeEmployeesToFile(employees, count, outputFilename);

    cout << "Прога сработана)" << endl << "Чекай файл " << outputFilename << endl;

    return 0;
}