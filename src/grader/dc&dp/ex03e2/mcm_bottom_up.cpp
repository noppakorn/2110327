#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<vector<int>> table(n, vector<int>(n, 0));
    for (int i = 0; i <= n; ++i) {
        cin >> v[i];
    }
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            int mn = INT_MAX;
            for (int k = i; k < i + j; ++k) {
                int curr = table[i][k] + table[k + 1][i + j] +
                           v[i] * v[k + 1] * v[i + j + 1];
                mn = min(mn, curr);
            }
            table[i][i + j] = mn;
        }
    }
    cout << table[0][n - 1] << endl;
}
