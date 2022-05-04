#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<bool> used;
unordered_map<int, int> con;
int n, m;
void solve(int step) {
    if (step == n) {
        for (auto &x : v) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                auto it = con.find(i);
                if (it != con.end() && !used[it->second])
                    continue;
                used[i] = 1;
                v[step] = i;
                solve(step + 1);
                used[i] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        con[b] = a;
    }
    v = vector<int>(n);
    used = vector<bool>(n);
    solve(0);
}
