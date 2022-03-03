#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int f, w, n;
    cin >> f >> w >> n;
    vector<int> v(f);
    for (int i = 0; i < f; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int pos = 0;
    int count = 0;
    for (auto x : v) {
        if (pos < x) {
            count++;
            pos = x + 2 * w;
        }
    }
    cout << count << "\n";
}