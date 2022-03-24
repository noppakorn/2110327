#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
int n, m, k;
int table[31][2][31][31];

int solve(int pos, int color, int consec, int swap) {
    if (consec >= m || swap > k || n - pos < k - swap)
        return 0;
    if (table[pos][color][consec][swap] != 0) {
        return table[pos][color][consec][swap];
    }
    if (pos == n - 1) {
        return swap == k;
    }
    if (color) {
        int val = solve(pos + 1, 0, 0, swap + 1) +
                  solve(pos + 1, 1, consec + 1, swap);
        table[pos][color][consec][swap] = val;
        return val;

    } else {
        int val = solve(pos + 1, 0, consec + 1, swap) +
                  solve(pos + 1, 1, 0, swap + 1);
        table[pos][color][consec][swap] = val;
        return val;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cout << solve(0, 1, 0, 0) << "\n";
}