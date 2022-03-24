#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> d(r, vector<int>(c, -1));
    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    d[0][0] = 0;
    q.push({0,0});
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        if (current.first == r-1 && current.second == c-1) break;
        for (int i = 0; i < 4; ++i) {
            int x = current.first + direction[i].first;
            int y = current.second + direction[i].second;
            if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == '.' && d[x][y] == -1) {
                d[x][y] = d[current.first][current.second] + 1;
                q.push({x, y});
            }
        }
    }
    cout << d[r - 1][c - 1] << "\n";
}
