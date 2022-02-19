#include <bits/stdc++.h>
using namespace std;
vector<int> v, table;
int n, k;
int solve(int stop) {
    if (stop < 0) {
        return 0;
    }
    if (table[stop])
        return table[stop];
    int res = INT_MAX;
    for (int i = max(stop - k, 0); i <= min(stop + k, n - 1); ++i) {
        res = min(res, v[i] + solve(i - k - 1));
    }
    table[stop] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    v = vector<int>(n);
    table = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(n - 1) << "\n";
}