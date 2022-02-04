#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

vector<ll> mat_mul(vector<ll> m, vector<ll> n, ll k) {
    return {((m[0] * n[0]) % k + (m[1] * n[2]) % k) % k,
            ((m[0] * n[1]) % k + (m[1] * n[3]) % k) % k,
            ((m[2] * n[0]) % k + (m[3] * n[2]) % k) % k,
            ((m[2] * n[1]) % k + (m[3] * n[3]) % k) % k};
}

vector<ll> gen(ll n, ll k, const vector<ll> &v) {
    if (n == 2) {
        return mat_mul(v, v, k);
    } else if (n == 1) {
        return v;
    }

    vector<ll> mat = gen(n / 2, k, v);
    if (n % 2 == 0) {
        return mat_mul(mat, mat, k);
    } else {
        return mat_mul(mat_mul(mat, mat, k), v, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> v(4);
    for (ll i = 0; i < 4; ++i) {
        cin >> v[i];
    }
    vector<ll> res = gen(n, k, v);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";
}
