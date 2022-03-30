#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pii>> v(n);
    for (auto &w : v) {
        w.reserve(n);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int weight;
            cin >> weight;
            v[i].emplace_back(j, weight);
            v[j].emplace_back(i, weight);
        }
    }
    vector<int> d(n, 1e9);
    vector<bool> in_mst(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 0);
    d[0] = 0;
    while (!pq.empty()) {
        auto [weight, pos] = pq.top();
        pq.pop();
        in_mst[pos] = true;
        for (auto &[b, c] : v[pos]) {
            if (!in_mst[b] && c < d[b]) {
                d[b] = c;
                pq.emplace(d[b], b);
            }
        }
    }
    cout << accumulate(d.begin(), d.end(), 0,
                       [](const int &total, const int &x) {
                           if (x == (int)1e9) {
                               return total;
                           } else {
                               return total + x;
                           }
                       })
         << "\n";
}