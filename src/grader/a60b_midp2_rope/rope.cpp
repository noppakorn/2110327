#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int table[4001];
int solve(int length) {
    if (length == 0) {
        return 0;
    }
    if (length < 0) {
        return INT_MIN;
    }
    if (table[length])
        return table[length];
    int ret = max(solve(length - a), solve(length - b));
    ret = max(ret, solve(length - c));
    table[length] = ++ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    cout << solve(n) << "\n";
}