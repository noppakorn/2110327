#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v, w, res;
vector<vector<int>> table;
void solve(int i, int j) {
    if (i <= 0 || j <= 0) {
        return;
    }
    if ((w[i - 1] > m && table[i - 1][j] > table[i - 1][j - w[i - 1]] + v[i - 1]) || table[i][j] == table[i-1][j]) {
        solve(i - 1, j);
    } else {
        res.push_back(i);
        solve(i - 1, j - w[i - 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    w = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    table = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cin >> table[i][j];
        }
    }
    solve(n, m);
    cout << res.size() << "\n";
    for (auto &x : res) {
        cout << x << " ";
    }
    cout << "\n";
}
