#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> v(k);
    for (int i = 0; i < k; ++i) {
        cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);
    }
    sort(v.begin(), v.end());
    queue<int> produce, store;
    for (auto &[_, e, l] : v) {
        if (!e) {
            produce.push(l);
            if (!store.empty()) {
                cout << store.front() << "\n";
                store.pop();
                produce.pop();
            } else {
                cout << 0 << "\n";
            }
        } else {
            store.push(l);
            if (!produce.empty()) {
                cout << produce.front() << "\n";
                store.pop();
                produce.pop();
            } else {
                cout << 0 << "\n";
            }
        }
    }
}