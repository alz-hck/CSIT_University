//Создать структуру Hotel, содержащую следующие данные: ФИО туриста, дату прибытия и дату отъезда.
//Определить сколько дней турист проведет в отеле. Необходима проверка на корректность ввода дат.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

int EndOfMonth(int m, int y){//конец месяца
    switch(m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: 
            if((y%4 == 0 && y%100 != 0) || y % 400 == 0) return 29; 
            //високосный
            else return 28; //не високосный
    }
}

date STR_date(string str){//перевод из строки в дату
    date data;
    //day
    string str1 = str.substr(0, 2);
    const char *sd = str1.c_str();
    int dd = atoi(sd);
    data.day = dd;
    //month
    str1 = str.substr(3, 2);
    sd = str1.c_str();
    dd = atoi(sd);
    data.month = dd;
    //year
    str1 = str.substr(6, 4);
    sd = str1.c_str();
    dd = atoi(sd);
    data.year = dd;

    return data;
}

double correct(string str){//проверка корректности данных
    if(str.length() != 10)
        return false;
    for(string::size_type i = 0; i < str.length(); i++)
        if (i != 2 && i != 5){
            if(!isdigit(str[i])) 
                return false;
        }
    date data = STR_date(str);
    if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year))
        return false;
    if (data.month <= 0 || data.month > 12)
        return false;;
    if (data.year == 0)
        return false;
    return true;
}

int Period (date date1, date date2) {//количество дней между двумя датами
    int days = 1;
    days -= date1.day;
    days += date2.day;
    for(int i = 1; i < date2.month; i++){
        days += EndOfMonth(i, date2.year);
    }
    for(int i = 1; i < date1.month; i++){
        days -= EndOfMonth(i, date1.year);
    }
    days += (date2.year - date1.year)*365;
    return abs(days)-1;
}

struct Hotel {
    string name;
    string surname;
    string sursurname;
    date date1;
    date date2;
    int period = 0;
};

void print(Hotel hotel){
    setlocale(LC_ALL, "RUS");
    cout << "Время пребывания: " << Period(hotel.date1, hotel.date2) << " суток\n";
}

int main() {
    setlocale(LC_ALL, "RUS");
    Hotel braziliano;
    string date1, date2;
    cout << "Введите ФИО\n";
    cin >> braziliano.surname >> braziliano.name >> braziliano.sursurname;
    cout <<"Введите дату прибытиия\n";
    cin >> date1;
    cout << "Введите дату отъезда\n";
    cin >> date2; 

    if (!correct(date1) || !correct(date2)){
        cout << "Некорректный ввод даты\n";
        return 0;
    }
    braziliano.date1 = STR_date(date1);
    braziliano.date2 = STR_date(date2);

    print(braziliano);
    return 0;
}

