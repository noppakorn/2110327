#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int> v;
vector<bool> used;
bool check(int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (v[j] == v[i] + (j - i) || v[j] == v[i] - (j - i)) {
                return false;
            }
        }
    }
    return true;
}
void solve(int m, int &count) {
    if (m == n) {
        if (check(m)) {
            ++count;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (!used[i] && check(m)) {
                used[i] = true;
                v[m] = i;
                solve(m + 1, count);
                used[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int count = 0;
    v = vector<int>(n);
    used = vector<bool>(n);
    solve(0, count);
    cout << count << "\n";
}
