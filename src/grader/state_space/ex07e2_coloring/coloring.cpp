#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<vector<int>> v;
vector<int> color;

bool solve(int m, int max_color) {
    bool res = false;
    if (m == n) {
        return true;
    }
    for (int i = 0; i < max_color; ++i) {
        bool valid = true;
        for (auto &x : v[m]) {
            if (color[x] == i) {
                valid = false;
                break;
            }
        }
        if (valid) {
            color[m] = i;
            res |= solve(m + 1, max_color);
            if (res) break;
            color[m] = -1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    v = vector<vector<int>>(n);
    color = vector<int>(n, -1);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for (int i = 0; i <= n; ++i) {
        if (solve(0, i)) {
            cout << i << "\n";
            return 0;
        }
    }
}