#include <iostream>
#include <string>
using namespace std;

int main() {
    char l;//буква
    char l1;
    cin.get(l);
    cin.get();

    if (isupper(l)) l1 = tolower(l); //если ввели в верхнем регистре, l1 будет в нижнем
    else l1 = toupper(l); // и наоборот

    string s;
    getline(cin, s); //вводим строку
    string r = " ?!,.:;-"; //строка со знаками препинания и пробелом
    int dl = 0; //здесь будем считать длину слова
    int p = 0; //сохраняем индекс начала слова
    int k = 0; //счетчик букв в слове
    for(int  i = 0; i < s.size(); i++){
        if (dl == 0) k = 0;
        if (r.find(s[i]) > r.length()){ //если символ НЕ знак препинания
            dl++; //увеличиваем длину слова
            k++; //и счетчик
        }
        if (r.find(s[i+1]) < r.length()) { //если следующий символ знак препинания
            p = i - dl + 1;//индекс первой буквы слова
            dl = 0;//обнуляем длину
            if (s[p] == l || s[p] == l1){ 
                s.insert(p + k, ":");
            }
        }
    }
    cout << s;
    return 0;
}
//privet, poka, privet poka.
//p