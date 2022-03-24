#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void gen(ll left, ll n, vector<ll> &v, vector<ll> &ans) {
    if (n <= 1) {
        ans[left] = v[left];
        return;
    }
    ll mid = left + n / 2;
    gen(left, n / 2, v, ans);
    gen(mid, n / 2, v, ans);
    for (ll i = 0; i < n / 2; ++i) {
        ans[left + i] = ans[left + i] + ans[mid + i];
    }
    for (ll i = 0; i < n / 2; ++i) {
        ans[mid + i] = ans[left + i] - (2 * ans[mid + i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<ll> ans(n);
    gen(0, n, v, ans);
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}
