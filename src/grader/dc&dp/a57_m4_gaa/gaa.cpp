#include <bits/stdc++.h>
using namespace std;

int get_length(int n) {
    if (n == 0)
        return 3;
    return 2 * get_length(n - 1) + n + 3;
}

int solve(int n, int level) {
    if (level == 0) {
        return n % 3;
    }

    int div = level + 3;
    int lr = (get_length(level) - div) / 2;
    if (n >= lr && n < lr + div) {
        return (n-lr) % div;
    } else if (n < lr) {
        return solve(n, level-1);
    } else {
        return solve(n - div - lr, level-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    --n;
    int left = 0, right = 29;
    while (left < right) {
        int mid = (left + right) / 2;
        if (get_length(mid) < n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << ((solve(n ,right) == 0) ? "g\n" : "a\n");
}
