#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n), table(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i < n; ++i) {
        table[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j]) {
                table[i] = max(table[i], table[j] + 1);
            }
        }
    }
    cout << *max_element(table.begin(), table.end()) << "\n";
}