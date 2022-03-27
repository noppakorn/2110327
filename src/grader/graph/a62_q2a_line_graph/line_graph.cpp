#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int count = 0;
    vector<int> visited(v);
    for (int i = 0; i < v; ++i) {
        if (visited[i] == 2)
            continue;
        stack<pii> stack;
        stack.push({i, -1});
        visited[i] = 1;

        bool linear = true;
        while (!stack.empty()) {
            pii current = stack.top();
            stack.pop();
            if (g[current.first].size() > 1 + (current.second != -1)) {
                linear = false;
                break;
            } else {
                visited[current.first] = 2;
            }
            for (auto &x : g[current.first]) {
                if (!visited[x]) {
                    visited[x] = 1;
                    stack.push({x, current.first});
                }
            }
        }
        for (auto &x : visited) {
            if (x != 2)
                x = 0;
        }
        count += linear;
    }
    cout << count << "\n";
}