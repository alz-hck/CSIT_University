#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    s += ".";
    string b = "ABEKMHOPCTX";
    string r = " ?!,.:;-";
    string v = "";
    int dl = 0; //здесь будем считать длину слова
    int p = 0; //сохраняем индекс начала слова
    int k = 0; //счетчик букв в слове

    for(int i = 0; i < s.size(); i++){
        if (dl == 0) k = 0;
        if (r.find(s[i]) > r.length()){ //если символ НЕ знак препинания
            dl++; //увеличиваем длину слова
             //и счетчик
            if(b.find(s[i]) < b.length()){
                k++;
                
            }
        }
        
        if (r.find(s[i+1]) < r.length()) { //если следующий символ знак препинания
            p = i - dl + 1;//индекс первой буквы слова
            if(r.find(s[p]) > r.length() && k == dl){ //если символ не знак и количество букв из набора равно длине
                v += s.substr(p, k);
                v += " ";
            }
            dl = 0;//обнуляем длину
        }
    }
    cout << v;
    return 0;
}
//MAMA, OBEC 
//AMAM, BAPBAMAXC OPLKDL: KOPOBKA BARK; KOPOPAMC?!