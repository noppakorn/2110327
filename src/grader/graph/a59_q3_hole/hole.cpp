#include <bits/stdc++.h>
#include <queue>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> grid(1001, vector<int>(1001));
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }
    vector<pii> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    vector<vector<int>> d(1001, vector<int>(1001, 1e9));
    pq.emplace(d[a][b] = 0, a, b);

    while (!pq.empty()) {
        auto [weight, x, y] = pq.top();
        pq.pop();
        if (x == 1 || y == 1 || x == 1000 || y == 1000) {
            cout << weight << "\n";
            return 0;
        }
        if (d[x][y] != weight) {
            continue;
        }
        for (auto &[dx, dy] : direction) {
            int xx = x + dx;
            int yy = y + dy;
            if (xx == 0 || yy == 0 || xx == 1001 || yy == 1001) {
                continue;
            }
            if (weight + grid[xx][yy] < d[xx][yy]) {
                pq.emplace(d[xx][yy] = weight + grid[xx][yy], xx, yy);
            }
        }
    }
}