#include <bits/stdc++.h>
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int v;
    cin >> v;
    vector<int> start(k);
    for (int i = 0; i < k; ++i) {
        cin >> start[i];
    }
    vector<iii> g;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g.emplace_back(b, a, w);
    }
    vector<int> d(n, 1e9);
    d[v] = 0;
    for (int i = 0; i < n; ++i) {
        for (auto &[a, b, w] : g) {
            if (d[a] + w < d[b]) {
                d[b] = d[a] + w;
            }
        }
    }
    int mn = INT_MAX;
    for (auto &s : start) {
        mn = min(mn, d[s]);
    }
    cout << mn << "\n";
}