#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
ll table[31][31];

ll binomial(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    } else if (table[n][k] != 0) {
        return table[n][k];
    } else {
        ll ret = binomial(n - 1, k - 1) + binomial(n - 1, k);
        table[n][k] = ret;
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << binomial(n, k) << "\n";
}