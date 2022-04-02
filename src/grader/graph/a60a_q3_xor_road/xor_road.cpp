#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ull> code(n);
    for (int i = 0; i < n; ++i) {
        cin >> code[i];
    }
    priority_queue<pair<ull, ull>, vector<pair<ull, ull>>> pq;
    vector<ull> d(n, 0);
    vector<bool> in_mst(n);
    pq.emplace(0,0);
    d[0] = 0;
    while (!pq.empty()) {
        auto [weight, pos] = pq.top();
        pq.pop();
        in_mst[pos] = true;
        for (int i = 0; i < n; ++i) {
            if (!in_mst[i] && (code[pos] ^ code[i]) > d[i]) {
                d[i] = code[pos] ^ code[i];
                pq.emplace(d[i], i);
            }
        }
    }
    cout << accumulate(d.begin(), d.end(), 0UL) << "\n";
}