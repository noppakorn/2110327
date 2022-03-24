#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gen(ll start, ll stop, ll A, ll B, vector<ll> &v) {
    ll mid = (start + stop) / 2;
    ll aven = lower_bound(v.begin(), v.end(), stop) - lower_bound(v.begin(), v.end(), start);
    if (!aven) return A;
    else if (stop - start >= 2) return min(gen(start, mid, A, B, v) + gen(mid, stop, A, B, v), B * aven * (stop - start));
    else return B * aven * (stop - start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll p, k, A, B;
    cin >> p >> k >> A >> B;
    vector<ll> v(k);
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
        v[i]--;
    }
    std::sort(v.begin(), v.end());
    cout << gen(0, 1 << p, A, B, v) << '\n';
}