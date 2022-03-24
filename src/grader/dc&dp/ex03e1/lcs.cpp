#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
string s1, s2;
int table[502][502];

int solve(int as, int bs) {
    if (as < 0 || bs < 0) {
        return 0;
    }
    if (table[as][bs] != 0) {
        return table[as][bs];
    }
    if (s1[as] == s2[bs]) {
        int res = 1 + solve(as - 1, bs - 1);
        table[as][bs] = res;
        return res;
    }
    int res = max(solve(as - 1, bs), solve(as, bs - 1));
    table[as][bs] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s1 >> s2;
    cout << solve(s1.length() - 1, s2.length() - 1) << "\n";
}
