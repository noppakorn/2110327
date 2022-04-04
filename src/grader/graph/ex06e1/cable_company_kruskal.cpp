#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

vector<int> p;

int find(int x) {
    while (p[x] >= 0) {
        x = p[x];
    }
    return x;
}

void union_set(int a, int b) {
    int p1 = find(a), p2 = find(b);
    if (p[p1] < p[p2]) {
        p[p1] += p[p2];
        p[p2] = p1;
    } else {
        p[p2] += p[p1];
        p[p1] = p2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    p = vector<int>(n, -1);
    vector<vector<int>> mat(n, vector<int>(n));
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int weight;
            cin >> weight;
            mat[i][j] = weight;
            pq.emplace(weight, i, j);
        }
    }
    int count = 0, ans = 0;
    while (count < n - 1) {
        auto [weight, a, b] = pq.top();
        pq.pop();
        if (find(a) != find(b)) {
            ++count;
            ans += mat[a][b];
            union_set(a, b);
        }
    }
    cout << ans << "\n";
}