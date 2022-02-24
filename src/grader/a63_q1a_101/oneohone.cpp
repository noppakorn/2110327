#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> table(4, 1);
    for (int i = 3; i <= n; ++i) {
        vector<int> v(4);
        for (int j = 0; j < 8; ++j) {
            if (j != 5) {
                v[j & 3] += table[j >> 1];
                v[j & 3] %= (int)1e8 + 7;
            }
        }
        table = v;
    }
    cout << accumulate(table.begin(), table.end(), 0) % ((int)1e8 + 7) << "\n";
}
