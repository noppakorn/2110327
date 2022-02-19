#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v;
string res = "";
string s1, s2;

void solve(int i, int j) {
    if (i <= 0 || j <= 0) {
        return;
    }
    if (s1[i-1] == s2[j-1]) {
        res += s2[j-1];
        solve(i - 1, j - 1);
    } else if (v[i][j - 1] > v[i - 1][j]) {
        solve(i, j - 1);
    } else {
        solve(i - 1, j);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s1 >> s2;
    v = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cin >> v[i][j];
        }
    }
    solve(n, m);
    std::reverse(res.begin(), res.end());
    cout << res << "\n";
}