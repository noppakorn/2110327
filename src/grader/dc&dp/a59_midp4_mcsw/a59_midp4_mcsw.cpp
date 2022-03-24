#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> s(n);
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        s[i] += v[i - 1] + s[i - 1];
    }
    deque<int> d;
    int mx = INT_MIN;
    d.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (!d.empty() && i - d.front() > k) d.pop_front();
        mx = max(mx, s[i] - s[d.front()]);
        while (!d.empty() && s[d.back()] > s[i])
            d.pop_back();
        d.push_back(i);
    }
    cout << mx << "\n";
}
