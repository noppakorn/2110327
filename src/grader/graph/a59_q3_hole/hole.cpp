#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> grid(1000, vector<int>(1000));
    vector<pii> hole(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
        hole[i] = {x, y};
    }
    vector<pii> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int count = 0;
    bool done = false;
    stack<pii> stack;
    vector<vector<bool>> visited(1000, vector<bool>(1000));
    while (!done) {
        for (auto &[x, y] : hole) {
            grid[x][y] = 0;
            stack.emplace(a, b);
            visited[a][b] = 1;
            while (!stack.empty()) {
                auto &[px, py] = stack.top();
                stack.pop();
                for (auto &[dx, dy] : direction) {
                    if (px + dx >= 0 && py + dy >= 0 && px + dx < 1000 &&
                        py + dy < 1000 && grid[px + dx][py + dy] != 1 &&
                        !visited[px + dx][py + dy]) {
                        visited[px + dx][py + dy] = 1;
                        stack.emplace(px + dx, py + dy);
                    }
                }
            }
            if (visited[0][0] || visited[0][999] || visited[999][0] ||
                visited[999][999]) {
                done = true;
                ++count;
                break;
            }
            grid[x][y] = 1;
        }
    }
    cout << count << "\n";
}