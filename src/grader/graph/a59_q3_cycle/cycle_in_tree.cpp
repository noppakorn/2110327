#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> depth, visited;
void dfs(int node, int parent, int distance) {
    if (visited[node]) {
        cout << distance - depth[node] << endl;
        exit(0);
    }
    visited[node] = 1;
    depth[node] = distance;
    for (auto &adj : v[node]) {
        if (adj != parent) {
            dfs(adj, node, distance + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v = vector<vector<int>>(n);
    depth = vector<int>(n);
    visited = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for (int i = 0; i < n; ++i) {
        dfs(i, -1, 0);
    }
}
