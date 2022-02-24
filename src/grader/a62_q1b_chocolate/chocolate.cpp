#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(k), table(n + 1);
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
    }
    table[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i - v[j] >= 0) {
                table[i] += table[i - v[j]] % ((int)1e6 + 3);
                table[i] %= (int)1e6 + 3;
            }
        }
    }
    cout << table[n] << "\n";
}