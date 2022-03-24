#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> table(n, vector<int>(m));
    int s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0 || v[i][j] == '0') {
                table[i][j] = v[i][j] - '0';
            } else {
                table[i][j] = min(table[i-1][j-1], min(table[i-1][j], table[i][j-1])) + 1;
            }
            s = max(s, table[i][j]);
        }
    }
    cout << s << "\n";
}