#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
void floyd_warshall(vector<vector<int>> &g, vector<vector<int>> &d, int n) {
    d = g;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    floyd_warshall(g, d, n);
    cout << "----" << endl;
    for (auto &x : d) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << "----" << endl;
}
