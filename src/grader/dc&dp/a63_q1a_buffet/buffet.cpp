#include <bits/stdc++.h>
using namespace std;
int n, k, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    vector<int> v(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 0; i < k; ++i) {
        int p, w;
        cin >> p >> w;
        int left = 1;
        int right = v.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int c = mid - p;
            if (v[mid] - v[p - 1] - ((c+1) * m) < w) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        cout << right << endl;
    }
}