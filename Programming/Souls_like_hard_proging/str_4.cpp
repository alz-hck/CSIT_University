#include <iostream>   
#include <fstream>    
#include <string>    
#include <cctype>      

using namespace std;  

// Структура для хранения информации о поезде
struct Train {
    string r; // маршрут
    string d; // время отправления 
};

// Функция для преобразования времени в строковом формате (HH:MM) в минуты
int toMin(const string& time) {
    // Извлекаем часы и минуты из строки и преобразуем их в общее количество минут
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

// Функция для проверки корректности формата времени
bool isTimeValid(const string& time) {

    return time.size() == 5 && time[2] == ':' &&
           isdigit(time[0]) && isdigit(time[1]) &&
           isdigit(time[3]) && isdigit(time[4]);
}

int main() {
    // Открываем файл для чтения входных данных и файл для записи выходных данных
    ifstream in("str_4_input.txt");
    ofstream out("str_4_output.txt");

    // Проверяем, успешно ли открыты файлы
    if (!in || !out) {
        return 1; // Если не удалось открыть хотя бы один файл, завершаем программу с кодом ошибки 1
    }

    string line; // Переменная для хранения текущей строки из файла
    while (getline(in, line)) {
        Train tr; // Создаем объект структуры Train для хранения данных о текущем поезде

        // Находим позицию символа '-' в строке
        size_t dashPos = line.find('-');
        // Проверяем, был ли найден символ '-'
        if (dashPos != string::npos) {
            // Извлекаем маршрут (все символы до '-') и время отправления (все символы после '-')
            tr.r = line.substr(0, dashPos);
            tr.d = line.substr(dashPos + 1);

            // Удаляем лишние пробелы из маршрута
            tr.r.erase(tr.r.find_last_not_of(" \n\r\t") + 1);
            // Удаляем пробелы в начале времени отправления
            tr.d.erase(0, tr.d.find_first_not_of(" \n\r\t"));
            // Удаляем пробелы в конце времени отправления
            tr.d.erase(tr.d.find_last_not_of(" \n\r\t") + 1);

            // Проверка на корректность времени отправления
            if (isTimeValid(tr.d)) {
                // Преобразуем время отправления в минуты
                int depMin = toMin(tr.d);

                // Проверяем, что время отправления в диапазоне между 12:00 и 15:00
                if (depMin >= toMin("12:00") && depMin < toMin("15:00")) {
                    // Записываем маршрут и время отправления в выходной файл
                    out << tr.r << " - " << tr.d << endl;
                }
            }
        }
    }

    // Закрываем файлы
    in.close();
    out.close();
    return 0;
}
