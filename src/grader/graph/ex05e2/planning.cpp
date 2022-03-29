#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int t = 0;
vector<vector<int>> v;
vector<int> visited, f;
void dfs(int node) {
    visited[node] = 1;
    for (auto &x : v[node]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
    f[node] = ++t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v = vector<vector<int>>(n);
    for (int i = 0; i < n; ++i) {
        int n2;
        cin >> n2;
        for (int j = 0; j < n2; ++j) {
            int tmp;
            cin >> tmp;
            v[i].emplace_back(tmp);
        }
    }
    visited = vector<int>(n, 0);
    f = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    vector<pii> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        res.emplace_back(f[i], i);
    }
    sort(res.begin(), res.end());
    for (auto &[_, x] : res) {
        cout << x << " ";
    }
    cout << "\n";
}