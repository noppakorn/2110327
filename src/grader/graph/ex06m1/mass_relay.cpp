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

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (p[a] < p[b]) {
        p[a] += p[b];
        p[b] = a;
    } else {
        p[b] += p[a];
        p[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<iii> v;
    v.reserve(n);
    p = vector<int>(n, -1);
    for (int i = 0; i < m; ++i) {
        int a, b, weight;
        cin >> a >> b >> weight;
        v.emplace_back(weight, a, b);
    }
    sort(v.begin(), v.end());
    vector<int> ans;

    for (auto &[weight, a, b] : v) {
        if (find(a) != find(b)) {
            ans.emplace_back(weight);
            merge(a, b);
        }
    }
    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        cout << ans[ans.size() - query] << "\n";
    }
}