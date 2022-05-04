#include <bits/stdc++.h>
#include <queue>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
const int N = 4;

class State {
  public:
    vector<vector<int>> v;
    int step;
    int cost;
    State(vector<vector<int>> v, int step, int cost) {
        this->v = v;
        this->step = step;
        this->cost = cost;
    }
    State(const State &other) {
        v = other.v;
        step = other.step;
        cost = other.cost;
    }
    bool operator<(const State &other) const { return cost > other.cost; }
};
int heuristic(vector<vector<int>> &v) {
    int cost = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[i][j] != 0) {
                cost +=
                    abs(i - ((v[i][j] - 1) / N)) + abs(j - ((v[i][j] - 1) % N));
            }
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }
    priority_queue<State> pq;
    set<vector<vector<int>>> s;
    pq.push(State(v, 0, heuristic(v)));
    s.insert(v);
    vector<pii> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int x, y;
        bool done = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (tmp.v[i][j] == 0) {
                    x = i;
                    y = j;
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }
        for (auto &[dx, dy] : direction) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
                continue;
            }
            vector<vector<int>> next_v(tmp.v);
            swap(next_v[x][y], next_v[nx][ny]);
            if (s.find(next_v) == s.end()) {
                int cost = heuristic(next_v);
                if (cost == 0) {
                    cout << tmp.step + 1 << endl;
                    return 0;
                }
                pq.push(State(next_v, tmp.step + 1, tmp.step + 1 + cost));
                s.insert(next_v);
            }
        }
    }
}
