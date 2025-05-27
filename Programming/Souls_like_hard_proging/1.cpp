#include <iostream>
#include <string>
using namespace std;

int main () {
    string s1;
    getline(cin, s1);
    
    for(int i = 0; i < s1.size(); i++){
        if (s1[i] == 'a' || s1[i] == 'A' || s1[i] == 'e' || s1[i] == 'E' || s1[i] == 'i' 
        || s1[i] == 'I' || s1[i] == 'o' || s1[i] == 'O' || s1[i] == 'u' || s1[i] == 'U'){
            continue;
        }
        s1.insert(i + 1, "!");
        i++;
    }
    cout << s1 << endl;
    return 0;
    
} 