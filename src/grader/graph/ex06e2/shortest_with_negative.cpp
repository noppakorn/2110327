#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e, s;
    cin >> n >> e >> s;
    vector<iii> v(n);
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(a, b, c);
    }
    vector<int> d(n, 5000);
    d[s] = 0;
    for (int i = 1; i < n; ++i) {
        for (auto &[a, b, c] : v) {
            if (d[a] + c < d[b]) {
                d[b] = d[a] + c;
            }
        }
    }
    for (auto &[a, b, c] : v) {
        if (d[a] + c < d[b]) {
            cout << "-1\n";
            return 0;
        }
    }
    for (auto &x : d) {
        cout << x << " ";
    }
    cout << "\n";
}
