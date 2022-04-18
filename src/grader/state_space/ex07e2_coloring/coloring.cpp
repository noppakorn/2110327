#include <bits/stdc++.h>
using namespace std;

int n, e, mn;
vector<vector<int>> graph;
void solve(int vertex, vector<int> colors) {
    vector<bool> free(n, true);
    if (vertex == n) {
        set<int> s;
        for (auto &x : colors) {
            s.insert(x);
        }
        mn = min(mn, (int)s.size());
        return;
    }

    for (auto &x : graph[vertex]) {
        if (colors[x] != -1) {
            free[x] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (free[i]) {
            colors[vertex] = i;
            solve(vertex + 1, colors);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    mn = n;
    graph = vector<vector<int>>(n);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<int> colors(n, -1);
    solve(0, colors);
    cout << mn << "\n";
}