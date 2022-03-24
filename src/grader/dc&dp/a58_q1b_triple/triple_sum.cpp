#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    int query;
    for (int x = 0; x < m; ++x) {
        cin >> query;
        bool done = false;
        for (int mid = 1; mid < n - 2; ++mid) {
            int left = 0, right = n - 1;
            while (left < mid && mid < right) {
                int sum = v[left] + v[mid] + v[right];
                if (sum == query) {
                    done = true;
                    break;
                } else if (sum < query) {
                    ++left;
                } else {
                    --right;
                }
            }
            if (done) break;
        }
        cout << (done ? "YES\n" : "NO\n");
    }
}
