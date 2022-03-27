#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < e; ++i) {
        int a,b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    queue<pii> q;
    q.push({0,0});
    int count = 0;
    vector<bool> visited(n + 1);
    while (!q.empty()) {
        pii current = q.front();
        q.pop();
        if (visited[current.first]) continue;
        visited[current.first] = 1;
        if (current.second == k) ++count;
        else if (current.second > k) break;
        for (auto &x : v[current.first]) {
            if (!visited[x]) {
                q.push({x, current.second + 1});
            }
        }
    }
    cout << count << "\n";
}
