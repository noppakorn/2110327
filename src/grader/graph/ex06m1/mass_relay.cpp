#include <bits/stdc++.h>
#include <queue>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pii>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    for (int i = 0; i < q; ++i) {
        int d;
        cin >> d;
    }
}
