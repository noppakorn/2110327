#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x : v) {
        cin >> x.first >> x.second;
    }
    sort(v.begin(), v.end());
    int mn = INT_MAX;
    int sz = 10;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < min(n, i+sz); ++j) {
            int a = v[i].first - v[j].first;
            int b = v[i].second - v[j].second;
            mn = min(mn, a * a + b * b);
        }
    }
    cout << mn << "\n";
}