#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> table(102, vector<int>(102));
    int ans;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < i + 1; ++j) {
            cin >> table[i][j];
            table[i][j] += max(table[i - 1][j - 1], table[i - 1][j]);
            ans = max(ans, table[i][j]);
        }
    }
    cout << ans << "\n";
}
