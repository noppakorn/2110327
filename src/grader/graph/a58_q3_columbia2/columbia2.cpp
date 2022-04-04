#include <bits/stdc++.h>
#define pii pair<int, int>
#define iiii tuple<int, int, int, int>
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
    vector<pii> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pii> warp_direction{{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                               {2, 0}, {-2, 0}, {0, 2},  {0, -2},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
    vector<vector<vector<int>>> d(3,
                                  vector<vector<int>>(r, vector<int>(c, 1e9)));
    pq.emplace(d[0][0][0] = 0, 0, 0, 0);
    while (!pq.empty()) {
        auto [weight, count, x, y] = pq.top();
        pq.pop();
        if (weight != d[count][x][y])
            continue;
        for (auto &[dx, dy] : direction) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                continue;
            }
            if (weight + v[nx][ny] < d[count][nx][ny]) {
                pq.emplace(d[count][nx][ny] = weight + v[nx][ny], count, nx,
                           ny);
            }
        }
        if (count < 2) {
            for (auto &[dx, dy] : warp_direction) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                    continue;
                } else if (d[count][x][y] < d[count + 1][nx][ny]) {
                    pq.emplace(d[count + 1][nx][ny] = d[count][x][y], count + 1,
                               nx, ny);
                }
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << d[2][i][j] << " ";
        }
        cout << "\n";
    }
}