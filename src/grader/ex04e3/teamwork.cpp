#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<vector<int>> v2(n);
    int i = 0;
    for (auto x : v) {
        v2[i++].push_back(x);
        i %= n;
    }
    double sum = 0;
    double count = 0;
    for (auto &x : v2) {
        for (int j = 1; j < x.size(); ++j) {
            x[j] += x[j-1];
        }
        sum += accumulate(x.begin(), x.end(), 0.0);
        count += x.size();
    }
    cout << fixed << setprecision(3) << sum / count << "\n";
}