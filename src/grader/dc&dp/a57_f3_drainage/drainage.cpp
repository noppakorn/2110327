#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int pos = 1;
    int count = 0;
    for (auto &x : v) {
        if (pos <= x){
            count++;
            pos = x + l;
        }
    }
    cout << count << "\n";
}