#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void b(const vector<vector<int>>& g, int s) {
    vector<bool> v(g.size());
    queue<int> q;
    q.push(s);
    v[s] = true;
    cout << "BFS: ";
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        cout << c << " ";
        for (int n : g[c]) {
            if (!v[n]) {
                v[n] = true;
                q.push(n);
            }
        }
    }
    cout << endl;
}

void d(const vector<vector<int>>& g, int s) {
    vector<bool> v(g.size());
    stack<int> st;
    st.push(s);
    cout << "DFS: ";
    while (!st.empty()) {
        int c = st.top();
        st.pop();
        if (!v[c]) {
            v[c] = true;
            cout << c << " ";
            for (auto it = g[c].rbegin(); it != g[c].rend(); ++it) {
                if (!v[*it]) {
                    st.push(*it);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> g = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };
    b(g, 0);
    d(g, 0);
    return 0;
}