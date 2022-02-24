#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v, table;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    v = vector<vector<int>>(n, vector<int>(n));
    table = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    int mx = v[0][0];
    for (int i = 0; i < n; ++i) {
        int max_now = v[0][i];
        for (int j = 1; j < n - i; ++j) {
            max_now = max(v[j][i + j], max_now + v[j][i + j]);
            mx = max(mx, max_now);
        }
        max_now = v[i][0];
        for (int j = 1; j < n - i; ++j) {
            max_now = max(v[i + j][j], max_now + v[i + j][j]);
            mx = max(mx, max_now);
        }
    }
    cout << mx << "\n";
}
