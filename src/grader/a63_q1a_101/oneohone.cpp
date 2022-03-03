#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = (ll)1e8 + 7;

vector<vector<ll>> mat_mul(const vector<vector<ll>> &m,
                           const vector<vector<ll>> &n) {
    vector<vector<ll>> ret(4, vector<ll>(4, 0));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                ret[i][j] += (m[i][k] * n[k][j]) % mod;
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

vector<vector<ll>> gen(const vector<vector<ll>> &m, ll n) {
    if (n == 2) {
        return mat_mul(m, m);
    } else if (n == 1) {
        return m;
    } else if (n == 0) {
        return vector<vector<ll>>{
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
        };
    }

    vector<vector<ll>> mul = gen(m, n / 2);
    if (n % 2 == 0) {
        return mat_mul(mul, mul);
    } else {
        return mat_mul(mat_mul(mul, mul), m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> mat = {
        {1, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 1},
    };

    vector<ll> table{2, 1, 2, 2};
    n -= 3;
    vector<vector<ll>> v = gen(mat, n);
    vector<ll> res(4, 0);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res[i] += (v[i][j] * table[j]) % mod;
            res[i] %= mod;
        }
    }
    cout << accumulate(res.begin(), res.end(), 0) % mod << "\n";
}