#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
void place(vector<tuple<int,int,int>> &v, int l, int x, int y, int xb, int yb) {
    if (l == 2) {
        if (xb == 0 && yb == 0) {
            v.push_back({0,x,y});
        } else if (xb == 0 && yb == 1) {
            v.push_back({2,x,y});
        } else if (xb == 1 && yb == 0) {
            v.push_back({1,x,y});
        } else if (xb == 1 && yb == 1) {
            v.push_back({3,x,y});
        }
    } else {
        place(v, 2, );
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, x, y;
    cin >> l >> x >> y;
    vector<tuple<int,int,int>> v;
    place(v, l, 0, 0, x, y);
    for (auto x : v) {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
    }
}
