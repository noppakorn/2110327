#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            if (i > 0 && j > 0) {
                v[i][j] =
                    max(2 * v[i][j] + v[i - 1][j - 1],
                        max(v[i][j] + v[i][j - 1], v[i][j] + v[i - 1][j]));
            } else if (j > 0) {
                v[i][j] += v[i][j - 1];
            } else if (i > 0) {
                v[i][j] += v[i - 1][j];
            }
        }
    }
    cout << v[n - 1][m - 1] << "\n";
}