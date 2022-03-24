#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = (ll)1e8 + 7;
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator() (const std::pair<T1,T2> &p) const {
      auto h1 = std::hash<T1>{}(p.first);
      auto h2 = std::hash<T2>{}(p.second);
      return h1 ^ h2;
  }
};

int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    unordered_map<pair<ll, ll>, ll, pair_hash> m;
    m[{0, 0}] = 1;
    m[{0, 1}] = 1;
    m[{1, 0}] = 1;
    m[{0, 2}] = 1;
    m[{1, 2}] = 1;
    m[{2, 0}] = 1;
    m[{2, 1}] = 1;
    for (int a = 0; a < n - 2; ++a) {
        unordered_map<pair<ll, ll>, ll, pair_hash> m2;
        for (int i = 0; i < 8; ++i) {
            if (i == 3 || i == 6 || i == 7) {
                continue;
            }
            for (int j = 0; j < 8; ++j) {
                if (j == 3 || j == 6 || j == 7) {
                    continue;
                }
                bool check = true;
                if (i >= 1 && i <= 5) {
                    if ((i & 1) == 1 && (j & 1) == 1) {
                        check = false;
                    }
                }
                if (check) {
                    m2[{i & 3, j & 3}] += m[{i >> 1, j >> 1}];
                    m2[{i & 3, j & 3}] %= MOD;
                }
            }
        }
        m = std::move(m2);
    }
    ll count = 0;
    for (auto x : m) {
        count += x.second;
        count %= MOD;
    }
    cout << count % MOD << "\n";
}