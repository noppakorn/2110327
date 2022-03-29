#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e;
    cin >> n >> e;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        g[b].emplace_back(a);
    }
    for (int i = 0; i < 5; ++i) {
        bool status = true;
        vector<int> steps(n);
        set<int> s;
        for (int j = 0; j < n; ++j) {
            cin >> steps[j];
        }
        for (auto x : steps) {
            for (auto &req : g[x]) {
                if (s.find(req) == s.end()) {
                    status = false;
                    break;
                }
            }
            if (!status) {
                break;
            } else {
                s.insert(x);
            }
        }
        cout << (status ? "SUCCESS\n" : "FAIL\n");
    }
}
