#include <bits/stdc++.h>
using namespace std;
vector<int> v, table;
int solve(int stop) {
    if (stop < 0) {
        return 0;
    }
    if (table[stop]) {
        return table[stop];
    }
    int res =
        max(v[stop] + solve(stop - 3), max(solve(stop - 1), solve(stop - 2)));
    table[stop] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v = vector<int>(n);
    table = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(n - 1) << "\n";
}