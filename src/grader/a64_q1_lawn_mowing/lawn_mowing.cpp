#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] = v[i - 1] + s[i - 1];
    }
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        ll left = a;
        ll right = n - 1;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (s[mid + 1] - s[a] + (mid - a + 1) * k >= b) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (s[right + 1] - s[a] + (right - a + 1) * k <= b) {
            cout << s[right + 1] - s[a] << "\n";
        } else {
            cout << s[right] - s[a] << "\n";
        }
    }
}