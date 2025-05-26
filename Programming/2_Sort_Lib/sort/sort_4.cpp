#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
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

// Блочная сортировка по стажу работы
void bucketSortEmployeesByExperience(Employee employees[], int count) {
    if (count == 0) return;

    int minExperience = employees[0].experience;
    int maxExperience = employees[0].experience;
    for (int i = 1; i < count; i++) {
        if (employees[i].experience < minExperience) minExperience = employees[i].experience;
        if (employees[i].experience > maxExperience) maxExperience = employees[i].experience;
    }

    // Создаем блоки
    int bucketCount = count;
    vector<vector<Employee>> buckets(bucketCount);

    // Распределяем элементы по блокам
    for (int i = 0; i < count; i++) {
        int bucketIndex = (employees[i].experience - minExperience) * (bucketCount - 1) / (maxExperience - minExperience);
        buckets[bucketIndex].push_back(employees[i]);
    }

    // Сортируем каждый блок
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end(), [](const Employee &a, const Employee &b) {
            return a.experience < b.experience;
        });

        // Объединяем блоки обратно в массив
        for (Employee &emp : buckets[i]) {
            employees[index++] = emp;
        }
    }
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

int main() {
    const int MAX_EMPLOYEES = 20; 
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    
    string inputFilename = "input_sort.txt";  
    string outputFilename = "output_sort4.txt"; 

    readEmployeesFromFile(employees, count, inputFilename);

    bucketSortEmployeesByExperience(employees, count);

    writeEmployeesToFile(employees, count, outputFilename);

    cout << "Прога сработана)" << endl << "Чекай файл " << outputFilename << endl;

    return 0;
}