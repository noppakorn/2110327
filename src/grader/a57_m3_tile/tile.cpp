#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> table;
int solve(int pos, int k) {
    if (pos < 0) {
        if (k == 0)
            return 0;
        return 1e9;
    }
    if (k < 0) {
        return 1e9;
    }
    if (table[pos][k]) {
        return table[pos][k];
    }
    int mn = solve(pos - 1, k - v[pos] * v[pos]);
    for (int i = 1; i <= 100; ++i) {
        int res =
            solve(pos - 1, k - (i * i)) + abs(v[pos] - i) * abs(v[pos] - i);
        if (res < mn) {
            mn = res;
        }
    }
    table[pos][k] = mn;
    return mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    v = vector<int>(n);
    table = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (m < n) {
        cout << "-1\n";
    } else {
        int res = solve(n - 1, m);
        cout << (res >= 1e8 ? -1 : res) << "\n";
    }
}