#include <bits/stdc++.h>
using namespace std;
bool solve(int &count, int s, const int &n, int prev) {
    if (s > n) {
        return true;
    }
    if (s == n) {
        ++count;
        return false;
    }
    for (int i = prev; i < n; ++i) {
        if (solve(count, s + i, n, i))
            break;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int count = 0;
    solve(count, 0, n, 1);
    cout << count + 1 << "\n";
}