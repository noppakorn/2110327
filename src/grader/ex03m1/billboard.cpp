#include <bits/stdc++.h>
using namespace std;

int table[10001][10001];
vector<int> v;
int solve(int start, int stop) {
    if (stop - 1 < start) {
        return 0;
    } else if (table[start][stop] != 0) {
        return table[start][stop];
    } else {
        int res1 = solve(start, stop - 1);
        int res2 = solve(start, stop - 2);
        table[start][stop] = max(res1, res2 + v[stop - 1]);
        return table[start][stop];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(0, n) << "\n";
}
