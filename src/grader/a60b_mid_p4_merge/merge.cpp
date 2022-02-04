#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int solve(int n, int k,int *v) {
    if (k == 1 || n == 1) {
        for (int i = 0; i < n; ++i) {
            v[i] = i + 1;
        }
        return 1;
    } else {
        int mid = n/2;
        int v1 = solve(mid, k-2, v);
        int v2 = solve(n-mid, k-1-v1, v+mid);
        for (int i = 0; i < mid; ++i) {
            v[i] += n-mid;
        }
        return v1 + v2 + 1;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m % 2 == 0 || m > 2 * n - 1)
        cout << -1 << "\n";
    else  {
        int arr[n];
        solve(n, m, arr);
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
