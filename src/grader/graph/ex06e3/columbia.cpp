#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> v[i][j];
        }
    }
    vector<pii> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<iii, vector<iii>, greater<iii>> q;
    vector<vector<int>> d(r, vector<int>(c, INT_MAX));
    q.emplace(0, 0, 0);
    d[0][0] = 0;
    while (!q.empty()) {
        auto [weight, x, y] = q.top();
        q.pop();
        for (auto &[dx, dy] : direction) {
            if (x + dx < 0 || y + dy < 0 || x + dx >= r || y + dy >= c) {
                continue;
            } else if (weight + v[x + dx][y + dy] < d[x + dx][y + dy]) {
                d[x + dx][y + dy] = weight + v[x + dx][y + dy];
                q.push({d[x + dx][y + dy], x + dx, y + dy});
            }
        }
    }
    for (auto &x : d) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}
