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

// Сортировка вставками по трем ключам: фамилия, стаж работы, год рождения
void insertionSortBySurnameExperienceYear(Employee employees[], int count) {
    for (int i = 1; i < count; i++) {
        Employee key = employees[i];
        int j = i - 1;

        // Сравнение по фамилии, затем по стажу работы, затем по году рождения
        while (j >= 0 && 
              ((employees[j].surname > key.surname) || 
               (employees[j].surname == key.surname && employees[j].experience > key.experience) || 
               (employees[j].surname == key.surname && employees[j].experience == key.experience && employees[j].year > key.year))) {
            employees[j + 1] = employees[j];
            j--;
        }
        employees[j + 1] = key;
    }
}

int main() {
    const int MAX_EMPLOYEES = 20; // Максимальное количество сотрудников
    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    string inputFilename = "input_sort.txt";  
    string outputFilename = "output_sort15.txt"; 

    readEmployeesFromFile(employees, count, inputFilename);

    insertionSortBySurnameExperienceYear(employees, count);

    writeEmployeesToFile(employees, count, outputFilename);

    cout << "Прога сработана)" << endl << "Чекай файл " << outputFilename << endl;

    return 0;
}