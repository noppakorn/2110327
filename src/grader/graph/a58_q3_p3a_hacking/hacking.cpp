#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> start_server(k), c(n);
    vector<vector<pii>> v(n);
    for (int i = 0; i < k; ++i) {
        cin >> start_server[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0;i  < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b, c[b]);
        v[b].emplace_back(a, c[a]);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> d(n, 1e9);
    for (auto &x : start_server) {
        d[x] = c[x];
        pq.emplace(c[x], x);
    }
    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        for (auto &[next_node, w] : v[node]) {
            if (weight + w < d[next_node]) {
                d[next_node] = weight + w;
                pq.emplace(weight + w, next_node);
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << "\n";
}