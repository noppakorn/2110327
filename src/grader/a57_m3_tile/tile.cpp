#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int solve(int pos, int k) {
    if (k <= 0) {
        return 0;
    }
    if (pos == 0) {
        int res = abs(v[pos] - sqrt(k));
        return res * res;
    }
    int mn = INT_MAX;
    for (int i = 1; i * i <= k; ++i) {
        int res = solve(pos - 1, k - i) + abs(v[pos] - i) * abs(v[pos] - i);
        if (res < mn) {
            mn = res;
        }
    }
    return mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (m < n) {
        cout << "-1\n";
    } else {
        cout << solve(n - 1, m) << "\n";
    }
}