#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v + 1);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int count = 0;
    vector<int> visited(v + 1);
    for (int i = 1; i < v + 1; ++i) {
        if (visited[i]) {
            continue;
        }
        ++count;
        stack<int> stack;
        stack.push(i);
        visited[i] = 1;

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();
            for (auto &x : g[current]) {
                if (!visited[x]) {
                    visited[x] = 1;
                    stack.push(x);
                }
            }
        }
    }
    cout << count << "\n";
}
