#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int table[10001][21];

int solve(int amount, int coin_index) {
    if (amount <= 0) {
        return 0;
    }
    if (v[coin_index] == 1) {
        return amount;
    }
    if (table[amount][coin_index] != 0) {
        return table[amount][coin_index];
    }
    int res = INT_MAX;
    int curr_count = amount / v[coin_index];
    for (int i = 0; i <= curr_count; ++i) {
        int remain = amount - v[coin_index] * i;
        res = min(res, i + solve(remain, coin_index + 1));
    }
    table[amount][coin_index] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(m, 0) << "\n";
}