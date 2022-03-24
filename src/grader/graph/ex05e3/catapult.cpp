#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    vector<vector<int>> vt(n);
    for (int i = 0; i < n; ++i) {
        for (const auto &y : v[i]) {
            vt[y].push_back(i);
        }
    }

    stack<int> s;
    vector<int> visited(n, 0);
    vector<pii> vst;
    int time = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i])
            continue;
        visited[i] = 1;
        s.push(i);
        while (!s.empty()) {
            int current = s.top();
            bool check = false;
            for (auto &a : vt[current]) {
                if (!visited[a]) {
                    check = true;
                    visited[a] = 1;
                    s.push(a);
                }
            }
            if (!check) {
                s.pop();
                vst.push_back({++time, current});
            }
        }
    }

    sort(vst.begin(), vst.end(), greater<pii>());
    std::fill(visited.begin(), visited.end(), 0);
    priority_queue<int, vector<int>, greater<int>> res;
    for (auto &mx : vst) {
        if (visited[mx.second])
            continue;
        visited[mx.second] = 1;
        s.push(mx.second);
        int count = 0;
        while (!s.empty()) {
            int current = s.top();
            bool check = false;
            for (auto &a : v[current]) {
                if (!visited[a]) {
                    check = true;
                    visited[a] = 1;
                    s.push(a);
                }
            }
            if (!check) {
                s.pop();
                ++count;
            }
        }
        res.push(count);
    }
    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    cout << "\n";
}
