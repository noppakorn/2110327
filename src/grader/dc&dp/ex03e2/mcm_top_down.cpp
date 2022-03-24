#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
vector<int> v;
vector<vector<int>> table;
int solve(int start, int stop) {
    if (start < stop) {
        if (table[start][stop] != -1)
            return table[start][stop];
        int mn = INT_MAX;
        for (int i = start; i < stop; ++i) {
            int curr = solve(start, i) + solve(i + 1, stop) +
                       (v[start] * v[i + 1] * v[stop + 1]);
            mn = min(mn, curr);
        }
        table[start][stop] = mn;
        return mn;
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v = vector<int>(n + 1);
    table = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; ++i) {
        cin >> v[i];
    }
    cout << solve(0, n - 1) << "\n";
}
