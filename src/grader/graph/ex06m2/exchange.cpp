#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    for (int _ = 0; _ < k; ++_) {
        bool check = false;
        int n;
        cin >> n;
        vector<vector<double>> r(n, vector<double>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> r[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    r[i][j] = max(r[i][j], r[i][k] * r[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (r[i][j] * r[j][i] > 1) {
                    check = true;
                    break;
                }
            }
            if (check)
                break;
        }
        cout << (check ? "YES\n" : "NO\n");
    }
}