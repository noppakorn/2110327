#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> qs(n + 1, vector<int>(m + 1, 0));
    qs[1][1] = v[0][0];
    for (int j = 2; j <= m; ++j) {
        qs[1][j] = qs[1][j - 1] + v[0][j - 1];
    }
    for (int i = 2; i <= n; ++i) {
        qs[i][1] = qs[i - 1][1] + v[i - 1][0];
        for (int j = 2; j <= m; ++j) {
            qs[i][j] = qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1] +
                       v[i - 1][j - 1];
        }
    }
    for (int i = 0; i < k; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        ++r1;
        ++c1;
        ++r2;
        ++c2;
        cout << qs[r2][c2] - qs[r1 - 1][c2] - qs[r2][c1 - 1] + qs[r1 - 1][c1 - 1] << "\n";
    }
}