#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int res = -1;
    vector<int> visited(n);
    for (int i = 0; i < n; ++i) {
        fill(visited.begin(), visited.end(), 0);
        int count = 0;
        queue<pii> q;
        q.push({i, 0});

        while (!q.empty()) {
            pii current = q.front();
            q.pop();
            if (visited[current.first] || current.second > k) {
                continue;
            } else {
                ++count;
                visited[current.first] = 1;
                for (auto &x : g[current.first]) {
                    if (!visited[x]) {
                        q.push({x, current.second + 1});
                    }
                }
            }
        }
        res = max(res, count);
    }
    cout << res << "\n";
}