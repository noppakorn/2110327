#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
vector<tuple<int, int, int>> ans;

void tile(int l, int x, int y, int nx, int ny) {
    if (l == 2) {
        if (nx == 0 && ny == 0)
            ans.push_back({0, x, y});
        else if (nx == 1 && ny == 0)
            ans.push_back({1, x, y});
        else if (nx == 0 && ny == 1)
            ans.push_back({2, x, y});
        else
            ans.push_back({3, x, y});
        return;
    }
    int mid = l / 2;
    if (nx < mid && ny < mid) {
        tile(2, x + mid - 1, y + mid - 1, 0, 0);
        tile(mid, x, y, nx, ny);
        tile(mid, x, y + mid, mid - 1, 0);
        tile(mid, x + mid, y, 0, mid - 1);
        tile(mid, x + mid, y + mid, 0, 0);
    } else if (nx < mid && ny >= mid) {
        tile(2, x + mid - 1, y + mid - 1, 0, 1);
        tile(mid, x, y, mid - 1, mid - 1);
        tile(mid, x, y + mid, nx, ny - mid);
        tile(mid, x + mid, y, 0, mid - 1);
        tile(mid, x + mid, y + mid, 0, 0);
    } else if (nx >= mid && ny < mid) {
        tile(2, x + mid - 1, y + mid - 1, 1, 0);
        tile(mid, x, y, mid - 1, mid - 1);
        tile(mid, x, y + mid, mid - 1, 0);
        tile(mid, x + mid, y, nx - mid, ny);
        tile(mid, x + mid, y + mid, 0, 0);
    } else if (nx >= mid && ny >= mid) {
        tile(2, x + mid - 1, y + mid - 1, 1, 1);
        tile(mid, x, y, mid - 1, mid - 1);
        tile(mid, x, y + mid, mid - 1, 0);
        tile(mid, x + mid, y, 0, mid - 1);
        tile(mid, x + mid, y + mid, nx - mid, ny - mid);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, x, y;
    cin >> l >> x >> y;
    tile(l, 0, 0, x, y);
    cout << ans.size() << "\n";
    for (auto &e : ans) {
        cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << "\n";
    }
}
