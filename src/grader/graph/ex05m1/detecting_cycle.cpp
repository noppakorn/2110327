#include <bits/stdc++.h>
using namespace std;

vector<int> visited;

vector<vector<int>> v;
bool dfs(int current, int parent) {
    if (visited[current])
        return true;
    visited[current] = 1;
    for (auto &x : v[current]) {
        if (x != parent && dfs(x, current))
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        v = vector<vector<int>>(n);
        for (int i = 0; i < e; ++i) {
            int n1, n2;
            cin >> n1 >> n2;
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }
        visited = vector<int>(n);
        bool check = false;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dfs(i, -1)) {
                check = true;
                break;
            }
        }
        cout << (check ? "YES\n" : "NO\n");
    }
}