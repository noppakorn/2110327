#include <bits/stdc++.h>
using namespace std;
int n, w, k;
vector<int> l, r;
int table_k[200001][2][51];

int solve_k(int stop, int count, bool right) {
    if (stop < 0) {
        return 0;
    }
    if (count == 0) {
        return 0;
    }
    if (table_k[stop][right][count]) {
        return table_k[stop][right][count];
    }
    int ret;
    if (right) {
        ret = max(l[stop] + solve_k(stop - w - 1, count - 1, false),
                  solve_k(stop - 1, count, right));
    } else {
        ret = max(r[stop] + solve_k(stop - w - 1, count - 1, true),
                  solve_k(stop - 1, count, right));
    }
    table_k[stop][right][count] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> k;
    l = vector<int>(n);
    r = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    cout << max(solve_k(n - 1, k, 0), solve_k(n - 1, k, 1)) << "\n";
}