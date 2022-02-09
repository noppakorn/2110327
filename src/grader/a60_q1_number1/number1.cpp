#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll get_len(ll n) {
    if (n <= 1) {
        return 1;
    }
    return 2 * get_len(n / 2) + get_len(n % 2);
}

ll solve(ll n, ll l, ll r) {
    if (l > r) return 0;
    if (n == 1) return 1;
    ll len = get_len(n/2);
    if (r <= len) {
        return solve(n/2, l, r);
    } else if (l >= len+2) {
        return solve(n/2, l-len-1, r-len-1);
    } else {
        return n%2 + solve(n/2, l, len) + solve(n/2, 1, r-len-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, l, r) << endl;
}