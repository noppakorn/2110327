#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

bool check(string &a, string &b, int astart, int astop, int bstart, int bstop) {
    if (astart == astop - 1)
        return a.substr(astart, astop - astart) ==
               b.substr(bstart, bstop - bstart);
    else if (a.substr(astart, astop - astart) ==
             b.substr(bstart, bstop - bstart))
        return true;
    int amid = (astart + astop) / 2;
    int bmid = (bstart + bstop) / 2;
    return check(a, b, astart, amid, bstart, bmid) &&
               check(a, b, amid, astop, bmid, bstop) ||
           check(a, b, astart, amid, bmid, bstop) &&
               check(a, b, amid, astop, bstart, bmid);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    cout << (check(a, b, 0, a.size(), 0, b.size()) ? "YES\n" : "NO\n");
}
