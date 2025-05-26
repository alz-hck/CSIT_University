#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int pr(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string toPref(string s) {
    stack<char> st;
    string res = "";
    reverse(s.begin(), s.end());

    for (char c : s) {
        if (isalnum(c)) res += c;
        else if (c == ')') st.push(c);
        else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else if (isOp(c)) {
            while (!st.empty() && pr(st.top()) > pr(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << "Введите выражение: ";
    string s;
    cin >> s;
    cout << "Результат: " << toPref(s);
    return 0;
}
