#include <bits/stdc++.h>
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> date(k);
    for (int i = 0; i < k; ++i) {
        cin >> date[i];
    }
    vector<vector<int>> wind(n);
    for (int i = 0; i < m; ++i) {
        int a, x;
        cin >> a >> x;
        wind[a].emplace_back(x);
    }
    int sum = accumulate(b.begin(), b.end(), 0);
    queue<int> q;
    vector<bool> visited(n);
    for (auto &start : date) {
        q.emplace(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (visited[node])
                continue;
            visited[node] = 1;
            if (b[node] != 0) {
                sum -= b[node];
                b[node] = 0;
            }
            for (auto &adj : wind[node]) {
                if (!visited[adj]) {
                    q.emplace(adj);
                }
            }
        }
        cout << sum << " ";
    }
    cout << '\n';
}