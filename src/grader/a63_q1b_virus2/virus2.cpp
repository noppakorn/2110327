#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int check(vector<int> &v, int begin, int end) {
    int mid = (begin + end) >> 1;
    if (end - begin == 4) {
        return std::abs(std::count(v.begin() + begin, v.begin() + mid, 1) - std::count(v.begin() + mid, v.begin() + end, 1)) <= 1;
    }
    int curr_diff = abs(count(v.begin() + begin, v.begin() + mid, 1) - count(v.begin() + mid, v.begin() + end, 1));
    return curr_diff <= 1 && check(v, begin, mid) && check(v,mid, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int len = 1 << k;
    vector<int> v(len);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len; ++j) cin >> v[j];
        cout << (check(v, 0, v.size()) ? "yes\n" : "no\n"); 
    }
}
