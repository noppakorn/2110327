#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> d(n, 1e9);
    d[0] = 0;
    q.emplace(0,0);
    while (!q.empty()) {
        pii current = q.top();
        q.pop();
        for (int i = 0; i < n; ++i) {
            int adj = v[current.second][i];
            if (adj > 0 && current.first + adj < d[i]) {
                d[i] = current.first + adj;
                q.emplace(d[i], i);
            }
        }
    }
    for (int i  = 1; i < n;++i) {
        if (d[i] == 1000000000) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << *(max_element(d.begin() + 1, d.end())) << "\n";
}