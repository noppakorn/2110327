#include <bits/stdc++.h>
using namespace std;
vector<int> v, table;
int solve(int start) {
    if (start >= v.size()) {
        return 0;
    }
    if (table[start]) {
        return table[start];
    }
    int ret = v[start] +
              max(max(solve(start + 1), solve(start + 2)), solve(start + 3));
    return ret;
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
    cout << max(max(solve(0), solve(1)), solve(2)) << "\n";
}