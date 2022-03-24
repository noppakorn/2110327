#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> table(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; ++i) {
        table[i][1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            table[i][j] = (table[i - 1][j - 1] + j * table[i - 1][j]) % 1997;
        }
    }
    cout << table[n][k] << '\n';
}