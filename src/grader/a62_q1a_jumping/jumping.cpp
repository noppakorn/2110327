#include <bits/stdc++.h>
using namespace std;
vector<int> v, table;
pair<int, bool> solve(int start) {
    if (start >= v.size()) {
        return make_pair(0, 0);
    }
    if (table[start]) {
        return make_pair(table[start], 1);
    }
    if (start == v.size() - 1) {
        return make_pair(v[v.size() - 1], 1);
    }
    auto r1 = solve(start + 1);
    auto r2 = solve(start + 2);
    auto r3 = solve(start + 3);
    int tmp = INT_MIN;
    if (r1.second) {
        tmp = max(tmp, r1.first);
    }
    if (r2.second) {
        tmp = max(tmp, r2.first);
    }
    if (r3.second) {
        tmp = max(tmp, r3.first);
    }
    int ret = v[start] + tmp;
    table[start] = ret;
    return make_pair(ret, r1.second || r2.second || r3.second);
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
    cout << solve(0).first << "\n";
}