#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i =0 ; i < n; ++i) {
        cin >> v[i].first;
    }
    for (int i =0 ; i < n; ++i) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pii a, pii b) {
        return a.second < b.second;
    });
    int cur = 0;
    int count = 0;
    for (auto &x : v) {
        if (x.first >= cur) {
            cur = x.second;
            ++count;
        }
    }
    cout << count << "\n";
}