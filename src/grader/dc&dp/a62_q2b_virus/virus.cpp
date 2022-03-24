#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

bool check(vector<int> &v, int begin, int end, int direction) {
    return end - begin == 2 && direction == 1 && v[begin] == 0 &&
               v[begin + 1] == 1 ||
           direction == -1 && v[begin] == 1 && v[begin + 1] == 0;
    int mid = (begin + end) >> 1;
    if (direction == 1) {
        return (check(v, begin, mid, direction) ||
                check(v, begin, mid, -direction)) &&
               check(v, mid, end, direction);
    } else {
        return (check(v, mid, end, direction) ||
                check(v, mid, end, -direction)) &&
               check(v, begin, mid, direction);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;

    cin >> n >> k;
    int len = 1 << k;
    vector<int> v(len);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len; ++j)
            cin >> v[j];
        cout << (check(v, 0, v.size(), 1) ? "yes\n" : "no\n");
    }
}
