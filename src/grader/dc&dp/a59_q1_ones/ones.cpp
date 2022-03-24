#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
int ones[] = {0,1,      11,      111,      1111,      11111,
              111111, 1111111, 11111111, 111111111, 1111111111};
void solve(int n, int sign, int &c) { 
    if (n == 0) return;
    if (n == 1) {
        ++c;
        return;
    }
    int len = (int)(log10(n) + 1); 
    if (n < ones[len]) {
        int rd = abs(ones[len] - n);
        int ld = abs(ones[len-1] - n);
        if (rd < ld) {
            c += len;
            solve(ones[len] - n, -sign, c);
        } else {
            c += len-1;
            solve(n - ones[len-1], sign, c);
        }
    } else {
        int rd = abs(ones[len+1] - n);
        int ld = abs(ones[len] - n);
        if (rd < ld) {
            c += len+1;
            solve(ones[len+1] - n, sign, c);
        } else {
            c += len;
            solve(n - ones[len], -sign, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int c = 0;
    solve(n, 1, c);
    cout << c << "\n";
}