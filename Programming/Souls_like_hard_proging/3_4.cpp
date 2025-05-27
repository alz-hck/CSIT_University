//Реализовать функции для работы с датой: определение количества прошедших дней, определение даты через N дней, 
//корректность даты, определение дня недели, определение сколько времени прошло между двумя датами.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct date{
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

void WeekDay(date date){//определение дня недели
    int D = date.day;
    int M = date.month;
    int Y = date.year;
    int a, y, m, R;
    a = (14 - M) / 12;
    y = Y - a;
    m = M + 12 * a - 2;
    R = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    cout << "День недели: ";
    R = R % 7;
    switch(R){
        case 0:
            cout << "Воскресенье\n";
            break;
        case 1:
            cout << "Понедельник\n";
            break;
        case 2:
            cout << "Вторник\n";
            break;
        case 3:
            cout << "Среда\n";
            break;
        case 4:
            cout << "Четверг\n";
            break;
        case 5:
            cout << "Пятница\n";
            break;
        case 6:
            cout << "Суббота\n";
            break;
    }
}

void After(date date, int n){//определение даты через n дней
    date.day += n;
    while(date.day > EndOfMonth(date.month, date.year)){
        date.day -= EndOfMonth(date.month, date.year);
        date.month++;
        if(date.month > 12){
            date.month = 1;
            date.year++;
        }
    }
    cout << "Дата после N дней: " << date.day << "." << date.month << "." << date.year << "\n";
}

void print(date date1, date date2, int n){
    date start = STR_date("01.01.2000");
    cout << "Количество прошедших дней с 01.01.2000 = " << Period(date1, start) << "\n";
    After(date1, n);
    WeekDay(date1);
    cout << "Между двумя датами прошло: " << Period(date1, date2) << " суток";
}

int main() {
    string date_1, date_2;
    cout << "Введите 1-ю дату\n"; cin >> date_1;
    cout << "Введите 2-ю дату\n"; cin >> date_2;
    if(!correct(date_1) || !correct(date_2)){
        cout <<"Некорректный ввод даты\n";
        return 0;
    }

    date date1 = STR_date(date_1);
    date date2 = STR_date(date_2);

    int n;
    cout << "Введите n: "; cin >> n;

    cout <<"\n";
    print(date1, date2, n);

    return 0;

}