#include <bits/stdc++.h> #define ll long long
#define pii pair<int, int>
using namespace std;

void solve(int left, int right, vector<int> &v, int &m, int &elem) {
    if (m >= 3 && (right - left) > 1) {
        m -= 2;
        int mid = (left + right) / 2;
        solve(mid, right, v, m, elem);
        solve(left, mid, v, m, elem);
    } else {
        for (int i = left; i < right; ++i) {
            v[i] = ++elem;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m % 2 == 0 || m > 2 * n - 1)
        cout << -1 << "\n";
    else {
        int elem = 0;
        vector<int> v(n);
        solve(0, n, v, m, elem);
        for (auto &x : v)
            cout << x << " ";
        cout << "\n";
    }
}
