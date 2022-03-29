#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c, T;
    cin >> r >> c >> T;
    vector<vector<int>> v(r, vector<int>(c));
    int count = 0;
    queue<pii> q, next_q;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                q.emplace(i,j);
                count++;
            }
        }
    }
    vector<pii> direction {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int i = 0; i < T; ++i) {
        while (!q.empty()) {
            auto& [x,y] = q.front();
            q.pop();
            for (auto&[dx, dy]: direction) {
                if (x + dx < 0 || y + dy < 0 || x + dx >= r || y + dy >= c) {
                    continue;
                } else if (v[x+dx][y+dy] == 0) {
                    v[x + dx][y + dy] = 1;
                    next_q.emplace(x+dx, y +dy);
                    ++count;
                }
            }
        }
        swap(q,next_q);
    }
    cout << count << "\n";
}
