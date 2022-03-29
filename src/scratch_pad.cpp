#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pii>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
    }
    vector<int> d(n, 1e9);
    vector<bool> in_mst(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (!pq.empty()) {
        auto &[weight, pos] = pq.top();
        pq.pop();
        in_mst[pos] = true;
        for (auto &[b, c] : v[pos]) {
            if (!in_mst[b] && c < d[b]) {
                d[b] = c;
                pq.emplace(c, b);
            }
        }
    }
    cout << 
}