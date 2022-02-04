#include <bits/stdc++.h>
using namespace std;
void gen(vector<vector<int>> &v, int a, int b, int top, int bottom, int left, int right) {
    if (a == 0) {
        v[top][left] = b;
        return;
    }
    int x1 = (top + bottom) / 2;
    int y1 = (left + right) / 2;
    gen(v, a-1, b, top, x1, left, y1);
    gen(v,a-1, b+1, x1, bottom, left, y1);
    gen(v, a-1, b-1, top, x1, y1, right);
    gen(v, a-1, b, x1, bottom, y1, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int len = 1 << a;
    vector<vector<int>> v(len);
    for (int i = 0; i < v.size(); ++i) v[i] = vector<int>(len);
    gen(v, a, b, 0, len, 0, len);
    for (auto &x : v) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}